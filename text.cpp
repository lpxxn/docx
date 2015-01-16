#include "text.h"

namespace Docx {


Paragraph::Paragraph()
{

}

Run *Paragraph::addRun(const QString &text, const QString &style)
{
    return new Run();
}

void Paragraph::setAlignment(const QString &align)
{

}

Paragraph *Paragraph::insertParagraphBefore(const QString &text, const QString &style)
{
    return new Paragraph();
}

Paragraph::~Paragraph()
{

}

Run::Run()
  : Parented()
{

}

void Run::addTab()
{

}

Text *Run::addText(const QString &text)
{
    return new Text();
}

Run::~Run()
{

}
bool Run::isallcaps() const
{
    return m_isCaps;
}

void Run::setIsallcaps(bool isallcaps)
{
    m_isCaps = isallcaps;
}
bool Run::isbold() const
{
    return m_isBold;
}

void Run::setIsbold(bool isbold)
{
    m_isBold = isbold;
}
bool Run::isItalic() const
{
    return m_isItalic;
}

void Run::setIsItalic(bool isItalic)
{
    m_isItalic = isItalic;
}
bool Run::isDoubleStrike() const
{
    return m_isDoubleStrike;
}

void Run::setIsDoubleStrike(bool isDoubleStrike)
{
    m_isDoubleStrike = isDoubleStrike;
}







Text::Text()
{

}

Text::~Text()
{

}



}


