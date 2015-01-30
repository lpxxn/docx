#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "docx_global.h"

#include <QString>

class QIODevice;

namespace Docx {
class Paragraph;
class Table;
class DocumentPart;
class Package;

class DOCX_EXPORT Document
{
public:
    Document();
    explicit Document(const QString& name);
    explicit Document(QIODevice* device);

    /*!
     * \brief 添加段落
     * \param text  文本
     * \param style 样式
     * \return
     */
    Paragraph* addParagraph(const QString &text = QString(), const QString &style = QString());

    /*!
     * \brief 添加标题
     * \param text
     * \param level
     * \return
     */
    Paragraph* addHeading(const QString &text = QString(), int level = 1);

    Table * addTable(int rows, int cols);

    virtual ~Document();

    void save(const QString& path);

private:
    DocumentPart *m_docPart;
    Package *m_package;

};

}


#endif // DOCUMENT_H
