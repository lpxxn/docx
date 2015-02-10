#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "docx_global.h"
#include "length.h"

#include <QString>
#include <QImage>

class QIODevice;

namespace Docx {
class Paragraph;
class Table;
class DocumentPart;
class Package;
class InlineShape;

class DOCX_EXPORT Document
{
public:
    Document();
    explicit Document(const QString& name);
    explicit Document(QIODevice* device);

    Paragraph *addParagraph(const QString &text = QString(), const QString &style = QString());

    Paragraph *addHeading(const QString &text = QString(), int level = 1);

    Table *addTable(int rows, int cols, const QString &style = QStringLiteral("TableGrid"));

    InlineShape *addPicture(const QString &imgPath, const Length &width = Length(), const Length &height = Length());
    InlineShape *addPicture(const QImage &img, const Length &width = Length(), const Length &height = Length());

    virtual ~Document();

    void save(const QString& path);

private:
    void open(const QString& name);

private:
    DocumentPart *m_docPart;
    Package *m_package;

};

}


#endif // DOCUMENT_H
