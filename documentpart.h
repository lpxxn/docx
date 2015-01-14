#ifndef DOCUMENTPART_H
#define DOCUMENTPART_H
#include "docx_global.h"
#include "documenttext.h"
#include "text.h"
namespace Docx {
class Body;
class CT_Default;
//class Paragraphss;
class DocumentPart
{
public:
    DocumentPart();    
    Paragraph* addParagraph(const QString &text, const QString &style);

    virtual ~DocumentPart();

private:
    Body *m_body;
};


class Body
{
public:
    Body();
    Paragraph* addParagraph(const QString &text, const QString &style);

private:
};

}

#endif // DOCUMENTPART_H
