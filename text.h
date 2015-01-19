#ifndef DOCXTEXT_H
#define DOCXTEXT_H

#include "docx_global.h"
#include "shared.h"

#include <QString>

namespace Docx {
class Run;
class Text;

class DOCX_EXPORT Paragraph : public Parented
{
public:
    Paragraph();

    Run* addRun(const QString &text, const QString &style);
    void setAlignment(const QString &align);
    Paragraph* insertParagraphBefore(const QString &text, const QString &style);

    virtual ~Paragraph();

private:


};

class DOCX_EXPORT Run : public Parented
{
public:
    Run();
    void addTab();
    Text* addText(const QString &text);

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

};

class DOCX_EXPORT Text
{
public:
    Text();
    virtual ~Text();
};


}

#endif // TEXT_H
