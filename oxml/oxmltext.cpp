#include "oxmltext.h"

namespace Docx {

// CT_P
CT_P::CT_P(const QDomDocument &dom)
    : OxmlElementBase(dom)
{

}

CT_P::~CT_P()
{

}

// CT_R

CT_R::CT_R(const QDomDocument &dom)
    : OxmlElementBase(dom)
{

}

CT_R::~CT_R()
{

}

// CT_RPr

CT_RPr::CT_RPr(const QDomDocument &dom)
    : OxmlElementBase(dom)
{

}

/*!
 * \brief set val attribute of <w:sStyle> child Element
 * \param style
 */
void CT_RPr::setStyle(const QString &style)
{

}

CT_RPr::~CT_RPr()
{

}

}
