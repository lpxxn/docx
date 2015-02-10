#include "table.h"
#include "text.h"
#include "./parts/documentpart.h"

#include <QVector>

namespace Docx {


const QString strtblRow      = QStringLiteral("w:tr");
const QString strtblCell     = QStringLiteral("w:tc");

Table::Table(DocumentPart *part, const QDomElement &element)
    : m_part(part)
{
    m_dom = part->m_dom;
    m_ctTbl = new CT_Tbl(this, element);
}

Cell *Table::cell(int rowIndex, int colIndex)
{
    Row *row = m_rows.at(rowIndex);

    return row->cells().at(colIndex);
}

Table::~Table()
{
    delete m_ctTbl;
}

Column *Table::addColumn()
{
    QDomElement gridCol = m_ctTbl->m_tblGrid->addGridCol();
    for (Row *row : m_rows) {
        row->addTc();
    }
    return new Column(gridCol, m_ctTbl->m_tblGrid->count(), this);
}

Row *Table::addRow()
{
    QDomElement rowEle = m_dom->createElement(strtblRow);
    Row *row = new Row(rowEle, this);
    m_rows.append(row);
    for (int i = 0; i< m_ctTbl->m_tblGrid->count(); i++) {
        row->addTc();
    }
    m_ctTbl->m_tblEle.appendChild(rowEle);
    return row;
}

/*!
 * \brief 得到rowIndex的行内所有的cell
 *
 * index
 * \param rowIdx
 * \return
 */
QList<Cell *> Table::rowCells(int rowIndex)
{
    Row *row = m_rows.at(rowIndex);

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
    m_ctTbl->setStyle(style);
}

void Table::setAlignment(WD_TABLE_ALIGNMENT alignment)
{
    m_ctTbl->setAlignment(alignment);
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

Table *Row::table()
{
    return m_table;
}

int Row::rowIndex()
{
    return m_table->m_rows.indexOf(this);
}

Row::~Row()
{

}

Cell::Cell(const QDomElement &element, Row *row)
    : m_row(row)
{
    m_dom = row->m_dom;
    m_part = row->m_part;
    m_tc = QSharedPointer<CT_Tc>(new CT_Tc(this, element));
    addParagraph();    
}

Paragraph *Cell::addParagraph(const QString &text, const QString &style)
{    
    QDomElement pEle = m_dom->createElement(QStringLiteral("w:p"));

    m_currentpara = new Paragraph(m_part, pEle);

    if (!text.isEmpty())
        m_currentpara->addRun(text, style);

    m_tc->m_ele.appendChild(pEle);
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

    m_tc->m_ele.appendChild(pEle);

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

Cell *Cell::merge(Cell *other)
{

    return nullptr;
}

int Cell::cellIndex()
{
    return m_row->m_cells.indexOf(this);
}

int Cell::rowIndex()
{
    return m_row->rowIndex();
}

Table *Cell::table()
{
    return m_row->m_table;
}

Cell::~Cell()
{
    qDeleteAll(m_paras);
}

}
