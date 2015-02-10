#include "oxmltable.h"
#include "../table.h"
#include <QDomElement>

namespace Docx {

const QString strstyle       = QStringLiteral("w:tblPr");
const QString strtblGrid     = QStringLiteral("w:tblGrid");

CT_Tbl::CT_Tbl(Table *table, const QDomElement &ele)
    : m_table(table), m_tblEle(ele)
{
    m_dom = m_table->m_dom;

    QDomNodeList tblGrids = m_tblEle.elementsByTagName(strtblGrid);
    if (tblGrids.isEmpty()) {
        QDomElement tblGrid = m_dom->createElement(strtblGrid);
        m_tblGrid = new CT_TblGrid(m_dom, tblGrid);
        m_tblEle.appendChild(tblGrid);
    } else {
        m_tblGrid = new CT_TblGrid(m_dom, tblGrids.at(0).toElement());
    }
}

void CT_Tbl::setStyle(const QString &style)
{
    if (!m_style) {
        QDomElement styleEle = m_dom->createElement(strstyle);
        m_style = new CT_TblPr(m_dom, styleEle);
        QDomNode n = m_tblEle.firstChild();
        m_tblEle.insertBefore(styleEle, n);
    }
    m_style->setStyle(style);
}

void CT_Tbl::setAlignment(WD_TABLE_ALIGNMENT alignment)
{
    m_style->setAlignment(alignment);
}

CT_Tbl::~CT_Tbl()
{
    delete m_style;
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

CT_Tc::CT_Tc(Cell *cell, const QDomElement &ele)
    : m_cell(cell), m_ele(ele)
{

}

CT_Tc::~CT_Tc()
{

}

}
