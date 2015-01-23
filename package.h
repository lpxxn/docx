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
    void loadRel(const QString &reltype, Part *target, const QString rId, bool isternal = false);
    virtual ~Package();

private:
    Relationships *m_rels;
};
}

#endif // PACKAGE_H
