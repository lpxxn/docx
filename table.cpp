#include "table.h"
#include "text.h"
#include "./parts/documentpart.h"

#include <QVector>

namespace Docx {

const QString strtblGrid     = QStringLiteral("w:tblGrid");
const QString strtblRow      = QStringLiteral("w:tr");
const QString strtblCell     = QStringLiteral("w:tc");
const QString strstyle       = QStringLiteral("w:tblPr");

Table::Table(DocumentPart *part, const QDomElement &element)
    : m_part(part), m_tblEle(element)
{
    m_dom = part->m_dom;
    QDomNodeList tblGrids = m_tblEle.elementsByTagName(strtblGrid);
    if (tblGrids.isEmpty()) {
        QDomElement tblGrid = m_dom->createElement(strtblGrid);
        m_tblGrid = new CT_TblGrid(m_dom, tblGrid);
        m_tblEle.appendChild(tblGrid);
    } else {
        m_tblGrid = new CT_TblGrid(m_dom, tblGrids.at(0).toElement());
    }
}

/*!
 * \brief 设置位置
 * \param align
 */
void Table::setAlignment(const QString &align)
{

}

Cell *Table::cell(int rowIdx, int colIdx)
{
    return nullptr;
}

Table::~Table()
{

}

Column *Table::addColumn()
{
    QDomElement gridCol = m_tblGrid->addGridCol();
    for (Row *row : m_rows) {
        row->addTc();
    }
    return new Column(gridCol, m_tblGrid->count(), this);
}

Row *Table::addRow()
{
    QDomElement rowEle = m_dom->createElement(strtblRow);
    Row *row = new Row(rowEle, this);
    m_rows.append(row);
    for (int i = 0; i< m_tblGrid->count(); i++) {
        row->addTc();
    }
    m_tblEle.appendChild(rowEle);
    return new Row(rowEle, this);
}

QList<Cell *> Table::rowCells(int rowIdx)
{
    Row *row = m_rows.at(rowIdx);

    return row->cells();
}

Rows *Table::rows()
{
    return new Rows();
}

Columns *Table::columns()
{
    return new Columns();
}

/*!
 * \brief 设置样式
 * \param style
 */
void Table::setStyle(const QString &style)
{
    if (!m_style) {
        QDomElement styleEle = m_dom->createElement(strstyle);
        m_style = new CT_TblPr(m_dom, styleEle);
        QDomNode n = m_tblEle.firstChild();
        m_tblEle.insertBefore(styleEle, n);
    }
    m_style->setStyle(style);
}

void Table::setAlignment(WD_TABLE_ALIGNMENT alignment)
{
    m_style->setAlignment(alignment);
}

Columns::Columns()
{

}

Columns::~Columns()
{

}

Column::Column(const QDomElement &tlGrid, int gridIndex, Table *table)
    : m_grid(tlGrid), m_index(gridIndex), m_table(table)
{

}

Length Column::width() const
{
    return Length();
}

void Column::setWidth()
{

}

Column::~Column()
{

}

Rows::Rows()
{

}

Rows::~Rows()
{

}

Row::Row(const QDomElement &element, Table *table)
    : m_ele(element), m_table(table)
{
    m_dom = m_table->m_dom;
    m_part= m_table->m_part;
}

void Row::addTc()
{
    QDomElement celEle = m_dom->createElement(strtblCell);
    Cell *cell = new Cell(celEle, this);
    m_cells.append(cell);
    m_ele.appendChild(celEle);
}

Table *Row::table() const
{
    return m_table;
}

QList<Cell *> Row::cells() const
{
    return m_cells;
}

Row::~Row()
{

}

Cell::Cell(const QDomElement &element, Row *row)
    : m_ele(element)
{
    m_dom = row->m_dom;
    m_part = row->m_part;
    addParagraph();
}

Paragraph *Cell::addParagraph(const QString &text, const QString &style)
{    
    QDomElement pEle = m_dom->createElement(QStringLiteral("w:p"));

    m_currentpara = new Paragraph(m_part, pEle);

    if (!text.isEmpty())
        m_currentpara->addRun(text, style);

    m_ele.appendChild(pEle);
    m_paras.append(m_currentpara);
    return m_currentpara;
}

void Cell::addText(const QString &text)
{
    m_currentpara->addRun(text);
}

Table *Cell::addTable(int rows, int cols, const QString &style)
{       
    QDomElement pEle = m_dom->createElement(QStringLiteral("w:tbl"));
    Table *table =  new Table(m_part, pEle);

    m_ele.appendChild(pEle);

    for (int i = 0; i < cols; i++) {
        table->addColumn();
    }
    for (int i = 0; i < rows; i++) {
        table->addRow();
    }
    table->setStyle(style);
    addParagraph();
    return table;
}

Cell::~Cell()
{
    qDeleteAll(m_paras);
}

}
