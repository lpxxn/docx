#ifndef OPCPACKAGE_H
#define OPCPACKAGE_H

#include <QString>

namespace Docx {

class OpcPackage
{
public:
    OpcPackage();
    static OpcPackage* open(const QString &pkgFile);
    virtual ~OpcPackage();
};

class Unmarshaller
{
public:
    Unmarshaller();

    virtual ~Unmarshaller();

};
}
#endif // OPCPACKAGE_H
