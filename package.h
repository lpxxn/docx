#ifndef PACKAGE_H
#define PACKAGE_H

#include "./opc/opcpackage.h"
#include "./opc/rel.h"
#include "./opc/part.h"

namespace Docx {
class Package : public OpcPackage
{
public:
    Package();
    void loadRel(const QString &reltype, const QString &targetRef, Part *target, const QString rId, bool isternal = false);
    static Package* open(const QString &pkgFile);
    void save(const QString &filePath);

    virtual ~Package();

private:

};

class ImageParts
{
public:
    ImageParts();

private:

};

}

#endif // PACKAGE_H
