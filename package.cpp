#include "package.h"
#include "./opc/packagereader.h"
#include "./opc/packagewriter.h"
#include "./parts/imagepart.h"

namespace Docx {
Package::Package()
    : OpcPackage()
{
    PackURI packUri(QStringLiteral("/"));
    m_rels = new Relationships(packUri.baseURI());
    m_imageParts = new ImageParts();
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

void Package::afterUnmarshal()
{
    QMap<QString, Relationship *> rels = m_rels->rels();

    gatherImageParts(rels);
}

ImageParts *Package::imageparts() const
{
    return m_imageParts;
}

Package::~Package()
{
    delete m_imageParts;
}

void Package::gatherImageParts(QMap<QString, Relationship *> rels)
{
    for (const Relationship *rel : rels.values()) {
        if (rel->relType() == Constants::IMAGE) {
            ImagePart *impart = static_cast<ImagePart *>(rel->target());
            m_imageParts->append(impart);
        }
        if (rel->target()) {
            Relationships *tarRels = rel->target()->rels();
            gatherImageParts(tarRels->rels());
        }
    }
}

ImageParts::ImageParts()
{

}

void ImageParts::append(ImagePart *item)
{
    m_imageparts.append(item);
}

}
