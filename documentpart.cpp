#include "documentpart.h"

#include "opc/oxml.h"
namespace Docx
{
DocumentPart::DocumentPart()
{
    m_body = new Body();
}

DocumentPart::~DocumentPart()
{

}

Paragraph *DocumentPart::addParagraph(const QString &text, const QString &style)
{

    Paragraph * p = new Paragraph();
    return m_body->addParagraph(text, style);
}



Body::Body()
{

}

Paragraph *Body::addParagraph(const QString &text, const QString &style)
{
    Paragraph *p =new Paragraph();

    return p;
}
}
