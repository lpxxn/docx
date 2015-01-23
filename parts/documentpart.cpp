#include "documentpart.h"
#include "../text.h"
#include "../table.h"
#include "../opc/oxml.h"

namespace Docx
{

DocumentPart::~DocumentPart()
{

}

DocumentPart::DocumentPart(const QString &partName, const QString &contentType, const QByteArray &blob, Package *package)
    : Part(partName, contentType, blob, package)
{
    m_body = new Body(this);
    m_element = new QDomDocument();
    m_element->setContent(blob);
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
void DocumentPart::afterUnmarshal()
{
}

QDomDocument *DocumentPart::element() const
{
    return m_element;
}



Body::Body(DocumentPart *docPart)
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


