#ifndef OXMLTABLE_H
#define OXMLTABLE_H


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
    CT_TblPr();

    virtual ~CT_TblPr();

private:

};

/*!
 * \brief <w:tblGrid>  child of <w:tbl>, holds <w:gridCol>
 */
class CT_TblGrid
{
public:
    CT_TblGrid();

    virtual ~CT_TblGrid();

private:

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
    CT_TblGrid m_tblGrid;
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
