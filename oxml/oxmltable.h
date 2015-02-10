#ifndef OXMLTABLE_H
#define OXMLTABLE_H

#include "../enums/enumtext.h"

#include <QDomElement>
#include <QMap>

namespace Docx {

class Table;
class Cell;
class CT_TblPr;
class CT_TblGrid;
class CT_TblGridCol;
class CT_Row;
class CT_Tc;

/*!
 * \brief <w:tbl>
 */
class CT_Tbl
{
public:
    CT_Tbl(Table *table, const QDomElement &ele);
    void setStyle(const QString &style);
    void setAlignment(WD_TABLE_ALIGNMENT alignment);
    virtual ~CT_Tbl();

private:
    CT_TblPr *m_style = nullptr;
    CT_TblGrid *m_tblGrid = nullptr;
    QDomDocument *m_dom;
    Table *m_table;
    QDomElement m_tblEle;
    friend class Table;
};

/*!
 * \brief <w:tblPr> child of <w:tbl> tables style
 */
class CT_TblPr
{
public:
    CT_TblPr(QDomDocument *dom, const QDomElement &ele);
    void setStyle(const QString &style);
    void setAlignment(WD_TABLE_ALIGNMENT alignment);
    virtual ~CT_TblPr();

private:
    void checkStyleElement();
    void checkAlignment();

private:
    QDomElement m_element;
    QDomDocument *m_dom;    
    QDomElement m_tblStyle;
    QDomElement m_jcAlignment;
    QMap<WD_TABLE_ALIGNMENT, QString> m_aligns;
};

/*!
 * \brief <w:tblGrid>  child of <w:tbl>, holds <w:gridCol>
 */
class CT_TblGrid
{
public:
    CT_TblGrid(QDomDocument *dom, const QDomElement &ele);
    QDomElement addGridCol();
    QDomElement ele() const;
    int count() const;
    virtual ~CT_TblGrid();

private:
    QDomElement m_element;
    QDomDocument *m_dom;
    int cols = 0;
};

/*!
 * \brief <w:gridCol> child of <w:tblGrid> defines a table column
 */
class CT_TblGridCol
{
public:
    CT_TblGridCol();

    virtual ~CT_TblGridCol();

private:

};

/*!
 * \brief <w:tr>
 */
class CT_Row
{
public:
    CT_Row();

    virtual ~CT_Row();

private:
};

/*!
 * \brief <w:tc> table cell element
 */
class CT_Tc
{
public:
    CT_Tc();
    CT_Tc(Cell *cell, const QDomElement &ele);


    virtual ~CT_Tc();

private:
    Cell *m_cell = nullptr;
    QDomElement m_ele;
    friend class Cell;

};


}

#endif // OXMLTABLE_H
