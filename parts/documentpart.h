#ifndef DOCUMENTPART_H
#define DOCUMENTPART_H
#include "docx_global.h"
#include "documenttext.h"

#include <QPair>

namespace Docx {
class Body;
class CT_Default;
class Paragraph;
class Table;
class DocumentPart
{
public:
    DocumentPart();    
    Paragraph* addParagraph(const QString &text, const QString &style);
    Table * addTable(int rows, int cols);

    virtual ~DocumentPart();

private:
    Body *m_body;
};


class Body
{
public:
    Body();
    Paragraph* addParagraph(const QString &text, const QString &style);
    Table * addTable(int rows, int cols);

private:
};

}

#endif // DOCUMENTPART_H
