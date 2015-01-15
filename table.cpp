#include "table.h"
#include "text.h"

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

Table::~Table()
{

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

Table *Cell::addTable(const int rows, const int cols)
{
    return new Table();
}

Cell::~Cell()
{

}

}
