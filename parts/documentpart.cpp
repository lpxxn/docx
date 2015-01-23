#include "documentpart.h"
#include "../text.h"
#include "../table.h"
#include "../opc/oxml.h"

#include <QDebug>

namespace Docx
{

DocumentPart::DocumentPart(const QString &partName, const QString &contentType, const QByteArray &blob, Package *package)
    : Part(partName, contentType, blob, package)
{
    m_body = new Body(this);
    m_element = new QDomDocument();
    m_element->setContent(blob);
}

Paragraph *DocumentPart::addParagraph(const QString &text, const QString &style)
{
    qDebug() << "Add Paragraph  Text = " + text;
    Paragraph * p = new Paragraph();
    return m_body->addParagraph(text, style);
}

DocumentPart *DocumentPart::load(const PackURI &partName, const QString &contentType, const QByteArray &blob, Package *package)
{
    return new DocumentPart(partName, contentType, blob, package);
}

Table *DocumentPart::addTable(int rows, int cols)
{
    return m_body->addTable(rows, cols);
}
void DocumentPart::afterUnmarshal()
{
    qDebug() << "afetrUnmarshal";
}

QDomDocument *DocumentPart::element() const
{
    return m_element;
}

DocumentPart::~DocumentPart()
{
    delete m_body;
    delete m_element;
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


