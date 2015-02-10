#include "oxmltable.h"

namespace Docx {

CT_Tbl::CT_Tbl()
{

}

CT_Tbl::~CT_Tbl()
{

}


CT_Row::CT_Row()
{

}

CT_Row::~CT_Row()
{

}


CT_TblGrid::CT_TblGrid(QDomDocument *dom, const QDomElement &ele)
    : m_dom(dom), m_element(ele)
{

}

QDomElement CT_TblGrid::addGridCol()
{
    QDomElement gridcol = m_dom->createElement(QStringLiteral("w:gridCol"));
    m_element.appendChild(gridcol);
    ++cols;
    return gridcol;
}

QDomElement CT_TblGrid::ele() const
{
    return m_element;
}

int CT_TblGrid::count() const
{
    return cols;
}

CT_TblGrid::~CT_TblGrid()
{

}

CT_TblGridCol::CT_TblGridCol()
{

}

CT_TblGridCol::~CT_TblGridCol()
{

}



/*!
 * \brief 表格的样式
 * \param dom
 * \param ele
 */
CT_TblPr::CT_TblPr(QDomDocument *dom, const QDomElement &ele)
    : m_dom(dom), m_element(ele)
{
    m_aligns.insert(WD_TABLE_ALIGNMENT::LEFT,           QStringLiteral("left"));
    m_aligns.insert(WD_TABLE_ALIGNMENT::RIGHT,          QStringLiteral("right"));
    m_aligns.insert(WD_TABLE_ALIGNMENT::CENTER,         QStringLiteral("center"));
    m_aligns.insert(WD_TABLE_ALIGNMENT::BOTH,           QStringLiteral("both"));
    m_aligns.insert(WD_TABLE_ALIGNMENT::DISTRIBUTE,     QStringLiteral("distribute"));
    m_aligns.insert(WD_TABLE_ALIGNMENT::MEDIUMKASHIDA,  QStringLiteral("mediumKashida"));
    m_aligns.insert(WD_TABLE_ALIGNMENT::HIGHKASHIDA,    QStringLiteral("highKashida"));
    m_aligns.insert(WD_TABLE_ALIGNMENT::LOWKASHIDA,     QStringLiteral("lowKashida"));
    m_aligns.insert(WD_TABLE_ALIGNMENT::THAIDISTRIBUTE, QStringLiteral("thaiDistribute"));


}

void CT_TblPr::setStyle(const QString &style)
{
    checkStyleElement();
    m_tblStyle.setAttribute(QStringLiteral("w:val"), style);
}

void CT_TblPr::setAlignment(WD_TABLE_ALIGNMENT alignment)
{
    checkAlignment();
    m_jcAlignment.setAttribute(QStringLiteral("w:val"), m_aligns.value(alignment));
}

CT_TblPr::~CT_TblPr()
{

}

void CT_TblPr::checkStyleElement()
{
    if (m_tblStyle.isNull()) {
        m_tblStyle = m_dom->createElement(QStringLiteral("w:tblStyle"));
        m_element.appendChild(m_tblStyle);
    }
}

void CT_TblPr::checkAlignment()
{
    if (m_jcAlignment.isNull()) {
        m_jcAlignment = m_dom->createElement(QStringLiteral("w:jc"));
        m_element.appendChild(m_jcAlignment);
    }
}

CT_Tc::CT_Tc()
{

}

CT_Tc::~CT_Tc()
{

}

}
