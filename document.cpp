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
}

Document::Document(QIODevice *device)
{
    qDebug() << "construct docx document from io";
}

/*!
 * \brief 添加段落
 * \param text  文本
 * \param style 样式
 * \return
 */
Paragraph *Document::addParagraph(const QString &text, const QString &style)
{
    return m_docPart->addParagraph(text, style);
}

/*!
 * \brief 添加标题
 * \param text
 * \param level
 * \return
 */
Paragraph *Document::addHeading(const QString &text, int level)
{
    QString style;
    if (level == 0)
        style = "Title";
    else
        style = QString("Heading%1").arg(level);
    return addParagraph(text, style);
}

Table *Document::addTable(int rows, int cols)
{
    return m_docPart->addTable(rows, cols);
}

InlineShape *Document::addPicture(const QString &imgPath, const Length &width, const Length &height)
{
    Run *run = addParagraph()->addRun();
    InlineShape *picture = run->addPicture(imgPath, width, height);

    return picture;
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
    m_package->save(path);
}
