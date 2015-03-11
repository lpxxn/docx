#include "document.h"
#include "./parts/documentpart.h"
#include "./opc/opcpackage.h"
#include "package.h"
#include "text.h"
#include "table.h"

#include <QDebug>
#include <QFile>

using namespace Docx;

Document::Document()
{
    qDebug() << "construct docx document.";
    if (QLocale::system().name() == QStringLiteral("zh_CN")) {
        open(QStringLiteral("://defaultzh_CN.docx"));
    } else {
        open(QStringLiteral("://default.docx"));
    }
}

Document::Document(const QString &name)
{
    qDebug() << "construct docx document from " << name;

    Q_ASSERT_X(QFile::exists(name), "filed", "can not find the path!");

    open(name);
}

Document::Document(QIODevice *device)
{
    open(device);
}

void Document::open(const QString &name)
{
    m_package = Package::open(name);
    m_docPart = m_package->mainDocument();
}

void Document::open(QIODevice *device)
{
    m_package = Package::open(device);
    m_docPart = m_package->mainDocument();
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

Table *Document::addTable(int rows, int cols, const QString &style)
{
    return m_docPart->addTable(rows, cols, style);
}

InlineShape *Document::addPicture(const QString &imgPath, const Length &width, const Length &height)
{
    Q_ASSERT_X(QFile::exists(imgPath), "add image filed", "can not find the Image path!");

    Run *run = addParagraph()->addRun();
    InlineShape *picture = run->addPicture(imgPath, width, height);

    return picture;
}

InlineShape *Document::addPicture(const QImage &img, const Length &width, const Length &height)
{
    Run *run = addParagraph()->addRun();
    InlineShape *picture = run->addPicture(img, width, height);

    return picture;
}

Paragraph *Document::addPageBreak()
{
    Paragraph *p = addParagraph();
    Run *run = p->addRun();
    run->addBreak();
    return p;
}

QList<Paragraph *> Document::paragraphs()
{
    return m_docPart->paragraphs();
}

QList<Table *> Document::tables()
{
    return m_docPart->tables();
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


