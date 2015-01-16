#include "table.h"
#include "text.h"

#include <QVector>

namespace Docx {
Table::Table()
    :Parented()
{

}

Table::Table(const CT_Tbl &table)
    : m_table(table)
{
    CT_Tbl t = CT_Tbl();
}

void Table::setAlignment(const QString &align)
{

}

Cell *Table::cell(int rowIdx, int colIdx)
{
    return new Cell();
}

Table::~Table()
{

}

Column *Table::addColumn()
{
    return new Column();
}

Row *Table::addRow()
{
    return new Row();
}


QVector<Cell *> Table::rowCells(const int rowIdx)
{
    QVector<Cell*> cells;
    return cells;
}

Rows *Table::rows()
{
    return new Rows();
}

Columns *Table::columns()
{
    return new Columns();
}

Columns::Columns()
{

}

Columns::~Columns()
{

}

Column::Column()
{

}

Column::Column(const CT_TblGridCol &gridCol, Table *parent)
    : m_gridCol(gridCol)
{
    m_table = parent;
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

Row::Row()
{

}

Row::~Row()
{

}

Cell::Cell()
{

}

Paragraph *Cell::addParagraph(const QString &text, const QString &style)
{
    return new Paragraph();
}

Table *Cell::addTable(int rows, int cols)
{
    return new Table();
}

Cell::~Cell()
{

}

}
