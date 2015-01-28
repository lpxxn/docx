#include "oxmltext.h"

namespace Docx {

// CT_P
CT_P::CT_P(QDomElement *element) : OxmlElementBase(element)
{

}

CT_P::~CT_P()
{

}

// CT_R

CT_R::CT_R(QDomElement *element)
    : OxmlElementBase(element)
{

}

CT_R::~CT_R()
{

}

// CT_RPr

CT_RPr::CT_RPr(QDomElement *element)
    : OxmlElementBase(element)
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
