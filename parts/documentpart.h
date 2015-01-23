#ifndef DOCUMENTPART_H
#define DOCUMENTPART_H

#include "../docx_global.h"
#include "../documenttext.h"
#include "../opc/part.h"

#include <QPair>
#include <QDomDocument>

namespace Docx {
class Body;
class CT_Default;
class Paragraph;
class Table;
class DocumentPart : public Part
{
public:
    DocumentPart(const QString &partName, const QString &contentType, const QByteArray &blob = QByteArray(), Package *package = nullptr);
    Paragraph* addParagraph(const QString &text, const QString &style);
    Table * addTable(int rows, int cols);
    void afterUnmarshal();
    QDomDocument * element() const;
    virtual ~DocumentPart();

private:
    Body *m_body;
    QDomDocument *m_element;

};


class Body
{
public:
    Body(DocumentPart *docPart);
    Paragraph* addParagraph(const QString &text, const QString &style);
    Table * addTable(int rows, int cols);

private:
};

}

#endif // DOCUMENTPART_H
