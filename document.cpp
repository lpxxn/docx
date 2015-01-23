#include "document.h"
#include "./parts/documentpart.h"
#include "./opc/opcpackage.h"
#include "package.h"
#include "text.h"
#include "table.h"

using namespace Docx;

#include <QDebug>

Document::Document()
{
    qDebug() << "construct docx document.";    
}

Document::Document(const QString &name)
{
    qDebug() << "construct docx document from " << name;
    //OpcPackage * pack = new OpcPackage();

    m_package = Package::open(name);
    m_docPart = m_package->mainDocument();
    m_docPart->addParagraph("text");
}

Document::Document(QIODevice *device)
{
    qDebug() << "construct docx document from io";
}

Paragraph *Document::addParagraph(const QString &text, const QString &style)
{
    return m_docPart->addParagraph(text, style);
}

Table *Document::addTable(int rows, int cols)
{
    return m_docPart->addTable(rows, cols);
}

Document::~Document()
{
    qDebug() << "delete Docx::Document.";
    delete m_docPart;
    delete m_package;
}

void Document::save(const QString &path)
{
    qDebug() << "save docx file: " << path;
}
