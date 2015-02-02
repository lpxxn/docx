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
    void gatherImageParts(QMap<QString, Relationship *> rels);

private:
    ImageParts *m_imageParts;
};

class ImageParts
{
public:
    ImageParts();
    void append(ImagePart * item);

private:
    QList<ImagePart *> m_imageparts;
};

}

#endif // PACKAGE_H
