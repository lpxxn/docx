#include "documentpart.h"
#include "text.h"
#include "table.h"
#include "opc/oxml.h"
namespace Docx
{
DocumentPart::DocumentPart()
{
    m_body = new Body();
}

DocumentPart::~DocumentPart()
{

}

Paragraph *DocumentPart::addParagraph(const QString &text, const QString &style)
{
    Paragraph * p = new Paragraph();
    return m_body->addParagraph(text, style);
}

Table *DocumentPart::addTable(int rows, int cols)
{
    return m_body->addTable(rows, cols);
}



Body::Body()
{

}

Paragraph *Body::addParagraph(const QString &text, const QString &style)
{
    Paragraph *p =new Paragraph();

    return p;
}

Table *Body::addTable(int rows, int cols)
{
    Table *table =  new Table();
    return table;
}
}
