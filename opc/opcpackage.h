#ifndef OPCPACKAGE_H
#define OPCPACKAGE_H

namespace Docx {

class OpcPackage
{
public:
    OpcPackage();
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
