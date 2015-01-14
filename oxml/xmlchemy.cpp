#include "xmlchemy.h"

namespace Docx {



BaseChildElement::BaseChildElement(const QString &nsptagname, const QString &successors)
    : m_nsptagname(nsptagname), m_successors(successors)
{

}

BaseChildElement::~BaseChildElement()
{

}



ZeroOrOne::ZeroOrOne(const QString &nsptagname, const QString &successors)
    : BaseChildElement(nsptagname, successors)
{

}

ZeroOrOne::~ZeroOrOne()
{

}

}

