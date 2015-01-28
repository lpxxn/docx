#include "text.h"

#include <QDomDocument>
#include <QDebug>

namespace Docx {


Paragraph::Paragraph(QDomDocument *domDocument, QDomElement *element)
{
    m_dom = domDocument;
    m_pEle = element;
}

Run *Paragraph::addRun(const QString &text, const QString &style)    
{
    Run *run = new Run(m_dom, m_pEle);
    run->addText(text);
    if (!style.isEmpty()) {

    }
    m_runs.append(run);
    return run;
}

void Paragraph::setAlignment(const QString &align)
{

}

Paragraph *Paragraph::insertParagraphBefore(const QString &text, const QString &style)
{
    return nullptr;
}

Paragraph::~Paragraph()
{
    qDeleteAll(m_runs);
}

// End Paragraph


Run::Run(QDomDocument *domDocument, QDomElement *parent)
    : m_dom(domDocument), m_parent(parent)
{
    m_rEle = m_dom->createElement(QStringLiteral("w:r"));
    m_parent->appendChild(m_rEle);
}

void Run::addTab()
{

}

void Run::addText(const QString &text)
{
    QDomElement tEle = m_dom->createElement(QStringLiteral("w:t"));
    tEle.appendChild(m_dom->createTextNode(text));
    m_rEle.appendChild(tEle);
    //m_rEle
}

QString Run::text() const
{
    return m_text;
}

void Run::clearText()
{
    m_text.clear();
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

Text::Text(QDomDocument *domDocument, QDomElement *parent)
    : m_dom(domDocument), m_parent(parent)
{

}

Text::~Text()
{

}



}


