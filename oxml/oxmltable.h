#ifndef OXMLTABLE_H
#define OXMLTABLE_H

#include "../enums/enumtext.h"

#include <QDomElement>
#include <QMap>

namespace Docx {

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
    CT_Tbl();

    virtual ~CT_Tbl();

private:
    CT_TblPr *m_tblPr;
    CT_TblGrid *m_tblGrid;
    CT_TblGridCol *m_tblGridCol;

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


    virtual ~CT_Tc();

private:

};


}

#endif // OXMLTABLE_H
