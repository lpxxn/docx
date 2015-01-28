#include "package.h"
#include "./opc/packagereader.h"
#include "./opc/packagewriter.h"

namespace Docx {
Package::Package()
    : OpcPackage()
{
    PackURI packUri(QStringLiteral("/"));
    m_rels = new Relationships(packUri.baseURI());
}

void Package::loadRel(const QString &reltype, const QString &targetRef, Part *target, const QString rId, bool isternal)
{
    m_rels->addRelationship(reltype, targetRef, target, rId, isternal);
}

Package *Package::open(const QString &pkgFile)
{
    PackageReader *reader = PackageReader::fromFile(pkgFile);
    //
    Package *package = new Package();
    Unmarshaller::unmarshal(reader, package);

    return package;
}

void Package::save(const QString &filePath)
{
    PackageWriter p(filePath);
    QList<Part *> parts = this->parts();
    p.writeContentTypes(parts);
    p.writePkgRels(m_rels);
    p.writeParts(parts);
}

Package::~Package()
{

}

ImageParts::ImageParts()
{

}

}
