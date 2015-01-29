#include "oxmltext.h"
#include "../text.h"
#include "../shared.h"

namespace Docx {

// CT_P
CT_P::CT_P(QDomElement *element) : OxmlElementBase(element)
{

}

CT_P::~CT_P()
{

}

// CT_PPr

CT_PPr::CT_PPr(Paragraph *paragraph)
    : m_paragraph(paragraph)
{

}

void CT_PPr::setStyle(const QString &style)
{
    addOrAssignStyle();
    if (m_pStyle.isNull())
        m_pStyle = addOrAssignElement(m_paragraph->m_dom, &m_style, QStringLiteral("w:pStyle"));
    if (!style.isEmpty())
        m_pStyle.setAttribute(QStringLiteral("w:val"), style);
}

void CT_PPr::addOrAssignStyle()
{
    if (m_style.isNull())
        m_style = addOrAssignElement(m_paragraph->m_dom, m_paragraph->m_pEle, QStringLiteral("w:pPr"), true);
}

CT_PPr::~CT_PPr()
{

}

// CT_RPr

CT_RPr::CT_RPr(Run *run)
    : m_run(run)
{

}

/*!
 * \brief set val attribute of <w:sStyle> child Element
 * \param style
 */
void CT_RPr::setStyle(const QString &style)
{
    addOrAssignStyle();
    if (m_rStyle.isNull())
        m_rStyle = addOrAssignElement(m_run->m_dom, &m_style, QStringLiteral("w:rStyle"));
    if (!style.isEmpty())
        m_rStyle.setAttribute(QStringLiteral("w:val"), style);
}

void CT_RPr::setBold(bool bold)
{
    addOrAssignStyle();
    QDomElement m_bold = addOrAssignElement(m_run->m_dom, &m_style, QStringLiteral("w:b"));
    if (!bold)
        m_bold.setAttribute("w:val", 0);
    else
        m_bold.removeAttribute("w:val");
}


void CT_RPr::addOrAssignStyle()
{
    if (m_style.isNull())
        m_style = addOrAssignElement(m_run->m_dom, &m_run->m_rEle, QStringLiteral("w:rPr"), true);
}

CT_RPr::~CT_RPr()
{

}



}
