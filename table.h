#ifndef TABLE_H
#define TABLE_H
#include "docx_global.h"
#include "shared.h"
#include "blkcntnr.h"
#include "./oxml/oxmltable.h"
#include "length.h"

#include <QString>
#include <QDomDocument>

namespace Docx {
class DocumentPart;
class Paragraph;
class Column;
class Row;
class Cell;
class Rows;
class Columns;

class DOCX_EXPORT Table
{
public:

    Table(DocumentPart *part, const QDomElement &element);
    void setAlignment(const QString &align);
    Cell* cell(int rowIdx, int colIdx);
    Row* addRow();
    Column* addColumn();
    QList<Cell*> rowCells(int rowIdx);
    Rows* rows();
    Columns* columns();
    void setStyle(const QString &style);
    void setAlignment(WD_TABLE_ALIGNMENT alignment);
    virtual ~Table();

private:
    QList<Row*> m_rows;
    DocumentPart *m_part = nullptr;
    QDomDocument *m_dom = nullptr;
    CT_TblGrid *m_tblGrid = nullptr;
    QDomElement m_tblEle;
    CT_TblPr *m_style = nullptr;
    friend class Row;
    //QDomElement m_tblGrid;
};

class DOCX_EXPORT Cell
{
public:
    Cell(const QDomElement &element, Row *row);
    Paragraph *addParagraph(const QString &text = QString(), const QString &style = QString());
    void addText(const QString &text);
    Table *addTable(int rows, int cols, const QString &style = QString::fromLatin1("TableGrid"));
    virtual ~Cell();

private:
    QDomDocument *m_dom;
    DocumentPart *m_part;
    QDomElement m_ele;
    QList<Paragraph *> m_paras;
    Paragraph *m_currentpara;
    Row *m_row;
};

class DOCX_EXPORT Columns
{
public:
    Columns();    
    virtual ~Columns();

private:

};

class DOCX_EXPORT Column : public Parented
{
public:
    Column(const QDomElement &tlGrid, int gridIndex, Table *table);
    Length width() const;
    void setWidth();
    virtual ~Column();

private:
    QDomElement m_grid;
    Table *m_table;
    int m_index;
};

class DOCX_EXPORT Rows
{
public:
    Rows();

    virtual ~Rows();

private:

};

class DOCX_EXPORT Row
{
public:
    Row(const QDomElement &element, Table *table);
    Table *table() const;
    QList<Cell *> cells() const;
    virtual ~Row();

private:
    void addTc();

private:
    QList<Cell *> m_cells;
    QDomElement m_ele;
    Table *m_table;
    DocumentPart *m_part;
    QDomDocument *m_dom;
    friend class Cell;
    friend class Table;

};
}
#endif // TABLE_H
