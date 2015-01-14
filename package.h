#ifndef PACKAGE_H
#define PACKAGE_H

#include "opc/opcpackage.h"

namespace Docx {
class Package : public OpcPackage
{
public:
    Package();
    virtual ~Package();
};
}

#endif // PACKAGE_H
