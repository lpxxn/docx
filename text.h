#ifndef DOCXTEXT_H
#define DOCXTEXT_H

#include "docx_global.h"
#include "shared.h"

#include <QString>
#include <QDomElement>
#include <QList>

class QDomDocument;

namespace Docx {
class Run;
class Text;

class DOCX_EXPORT Paragraph : public Parented
{
public:

    Paragraph(QDomDocument *domDocument, QDomElement *element);

    Run* addRun(const QString &text, const QString &style = "");
    void setAlignment(const QString &align);
    Paragraph* insertParagraphBefore(const QString &text, const QString &style);
    QDomElement &element();
    virtual ~Paragraph();

private:


private:    
    QDomDocument *m_dom;
    QDomElement *m_pEle;
    QList<Run *> m_runs;

};

class DOCX_EXPORT Run : public Parented
{
public:    
    Run(QDomDocument *domDocument, QDomElement *parent);

    void addTab();
    void addText(const QString &text);
    QString text() const;
    void clearText();

    virtual ~Run();

    bool isallcaps() const;
    void setIsallcaps(bool isallcaps);

    bool isbold() const;
    void setIsbold(bool isbold);

    bool isItalic() const;
    void setIsItalic(bool isItalic);

    bool isDoubleStrike() const;
    void setIsDoubleStrike(bool isDoubleStrike);

private:
    bool m_isCaps;
    bool m_isBold;
    bool m_isItalic;
    bool m_isDoubleStrike;

    QString m_text;
    QDomDocument *m_dom;
    QDomElement m_rEle;
    QDomElement *m_parent;

};

class DOCX_EXPORT Text
{
public:
    Text();
    Text(QDomDocument *domDocument, QDomElement *parent);
    virtual ~Text();

private:
    QDomDocument *m_dom;
    QDomElement *m_parent;
};


}

#endif // TEXT_H
