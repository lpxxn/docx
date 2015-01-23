#include "opcpackage.h"
#include "packagereader.h"
#include "part.h"
#include "../package.h"

#include <QList>

using namespace Docx;

OpcPackage::OpcPackage()
{

}

OpcPackage *OpcPackage::open(const QString &pkgFile)
{
    PackageReader *reader = PackageReader::fromFile(pkgFile);
    //
    Package *package = new Package();
    Unmarshaller::unmarshal(reader, package);

    return new OpcPackage();
}

OpcPackage::~OpcPackage()
{

}

Unmarshaller::Unmarshaller()
{

}
/*!
 * \brief 分解PackageReader里的内容
 * \param pkgReader
 * \param package
 */
void Unmarshaller::unmarshal(PackageReader *pkgReader, Package *package)
{
    QMap<QString, Part *> parts;
    parts = Unmarshaller::unmarshalParts(pkgReader, package);
    Unmarshaller::unmarshalRelationships(pkgReader, package, parts);

    for (Part * p : parts.values()) {
        p->afterUnmarshal();
    }

}

/*!
 * \brief 分解各部分xml文件找出
 * \param pkgReader
 * \param package
 * \return
 */
QMap<QString, Part *> Unmarshaller::unmarshalParts(PackageReader *pkgReader, Package *package)
{
    QMap<QString, Part *> parts;
    QList<SerializedPart> sparts = pkgReader->sparts();
    for (const SerializedPart &p : sparts) {
        parts[p.partName()] = PartFactory::newPart(p.partName(), p.contentType(), p.relType(), p.blob(), package);
    }
    return parts;
}

/*!
 * \brief 分解relationships
 * \param pkgReader
 * \param package
 * \param parts
 */
void Unmarshaller::unmarshalRelationships(PackageReader *pkgReader, Package *package, const QMap<QString, Part *> &parts)
{
    QMap<QString, QVector<SerializedRelationship> > partRel = pkgReader->partRels();

    for (const QString &key : partRel.keys()) {
        QVector<SerializedRelationship> rels = partRel[key];
        for (const SerializedRelationship &r : rels) {
            Part * target = parts[r.targetPartName()];
            if (key.isEmpty() || key == QStringLiteral("/")) {
                package->loadRel(r.relType(), target, r.rId(), r.isExternal());
            } else {
                Part * part = parts[key];
                part->loadRel(r.relType(), target, r.rId(), r.isExternal());
            }
        }
    }
}

    Unmarshaller::~Unmarshaller()
    {

    }
