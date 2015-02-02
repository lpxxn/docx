#include "documentpart.h"
#include "../text.h"
#include "../table.h"
#include "../opc/oxml.h"

#include <QDebug>

namespace Docx
{

DocumentPart::DocumentPart(const QString &partName, const QString &contentType, const QByteArray &blob, Package *package)
    : Part(partName, contentType, QByteArray(), package)
{        
    m_dom = new QDomDocument();
    m_dom->setContent(blob);
    m_inlineshapes = new InlineShapes(this);
}

Paragraph *DocumentPart::addParagraph(const QString &text, const QString &style)
{
    qDebug() << "Add Paragraph  Text = " + text;
    QDomNodeList nodes = m_dom->elementsByTagName(QStringLiteral("w:sectPr"));

    QDomNode n = nodes.at(nodes.count() - 1);
    QDomNode parentNode = n.parentNode();

    QDomElement pEle = m_dom->createElement(QStringLiteral("w:p"));

    Paragraph *p = new Paragraph(this, pEle);

    if (!text.isEmpty())
        p->addRun(text, style);

    parentNode.insertBefore(pEle, n);

    return p;
}

DocumentPart *DocumentPart::load(const PackURI &partName, const QString &contentType, const QByteArray &blob, Package *package)
{
    return new DocumentPart(partName, contentType, blob, package);
}

Table *DocumentPart::addTable(int rows, int cols)
{
    Table *table =  new Table();
    return table;
}
void DocumentPart::afterUnmarshal()
{
    qDebug() << "afetrUnmarshal";
}

QDomDocument *DocumentPart::element() const
{
    return m_dom;
}

QByteArray DocumentPart::blob() const
{
    return m_dom->toByteArray();
}

ImagePart *DocumentPart::getOrAddImagePart(const QString &imageDescriptor)
{
    return nullptr;
}

DocumentPart::~DocumentPart()
{
    delete m_inlineshapes;
    delete m_dom;
}

InlineShapes::InlineShapes(DocumentPart *part)
    : m_part(part)
{

}

InlineShapes::~InlineShapes()
{

}

}


