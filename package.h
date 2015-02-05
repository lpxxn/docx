#ifndef PACKAGE_H
#define PACKAGE_H

#include "./opc/opcpackage.h"
#include "./opc/rel.h"
#include "./opc/part.h"

#include <QList>

namespace Docx {

class ImagePart;
class ImageParts;

class Package : public OpcPackage
{
public:
    Package();
    void loadRel(const QString &reltype, const QString &targetRef, Part *target, const QString rId, bool isternal = false);
    static Package* open(const QString &pkgFile);
    void save(const QString &filePath);
    void afterUnmarshal();
    ImageParts *imageparts() const;
    virtual ~Package();

private:
    void gatherImageParts(const QMap<QString, Relationship *> &rels);

private:
    ImageParts *m_imageParts;
};

class ImageParts
{
public:
    ImageParts();
    ~ImageParts();

    ImagePart *getOrAddImagePart(const PackURI &imageDescriptor);
    void append(ImagePart * item);

private:
    ImagePart *getByHash(const QByteArray &hash);
    PackURI nextImagePartName(const QString &ext);

private:
    QList<ImagePart *> m_imageparts;
};

}

#endif // PACKAGE_H
