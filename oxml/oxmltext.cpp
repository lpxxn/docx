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

void CT_PPr::setAlignment(const WD_PARAGRAPH_ALIGNMENT &align)
{
    addOrAssignStyle();
    QDomElement alignStyle = addOrAssignElement(m_paragraph->m_dom, &m_style, QStringLiteral("w:jc"));
    QString str = paragraphAlignToString(align);
    alignStyle.setAttribute(QStringLiteral("w:val"), str);

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
    addOrAssignStyleChildElement(QStringLiteral("w:b"), bold);
    //    addOrAssignStyle();
    //    QDomElement m_bold = addOrAssignElement(m_run->m_dom, &m_style, QStringLiteral("w:b"));
    //    if (!bold)
    //        m_bold.setAttribute("w:val", 0);
    //    else
    //        m_bold.removeAttribute("w:val");
}

void CT_RPr::setAllcaps(bool isallcaps)
{
    addOrAssignStyleChildElement(QStringLiteral("w:caps"), isallcaps);
}

void CT_RPr::setItalic(bool italic)
{
    addOrAssignStyleChildElement(QStringLiteral("w:i"), italic);
}

void CT_RPr::setDoubleStrike(bool isDoubleStrike)
{
    addOrAssignStyleChildElement(QStringLiteral("w:dstrike"), isDoubleStrike);
}

void CT_RPr::setUnderLine(const WD_UNDERLINE &underline)
{
    addOrAssignStyle();
    QDomElement line = addOrAssignElement(m_run->m_dom, &m_style, QStringLiteral("w:u"));

    line.setAttribute("w:val", underLineToString(underline));
}


void CT_RPr::addOrAssignStyle()
{
    if (m_style.isNull())
        m_style = addOrAssignElement(m_run->m_dom, &m_run->m_rEle, QStringLiteral("w:rPr"), true);
}

void CT_RPr::addOrAssignStyleChildElement(const QString &eleName, bool enable)
{
    addOrAssignStyle();
    QDomElement m_bold = addOrAssignElement(m_run->m_dom, &m_style, eleName);
    if (!enable)
        m_bold.setAttribute("w:val", 0);
    else
        m_bold.removeAttribute("w:val");
}

CT_RPr::~CT_RPr()
{

}



}
