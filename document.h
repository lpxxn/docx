#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "docx_global.h"

class QIODevice;

namespace Docx {
class Paragraph;
class Table;
class DocumentPart;

class DOCX_EXPORT Document
{
public:
    Document();
    explicit Document(const QString& name);
    explicit Document(QIODevice* device);
    Paragraph* addParagraph(const QString &text, const QString &style);
    Table * addTable(int rows, int cols);

    virtual ~Document();

    void save(const QString& path);

private:
    DocumentPart *m_docPart;

};

}


#endif // DOCUMENT_H
