#include "package.h"

namespace Docx {
Package::Package()
    : OpcPackage()
{
    PackURI packUri(QStringLiteral("/"));
    m_rels = new Relationships(packUri.baseURI());
}

void Package::loadRel(const QString &reltype, Part *target, const QString rId, bool isternal)
{
    m_rels->addRelationship(reltype, target, rId, isternal);
}

Package::~Package()
{

}

}
