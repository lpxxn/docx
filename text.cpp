#include "text.h"

namespace Docx {


Paragraph::Paragraph()
{

}

Run *Paragraph::addRun(const QString &text, const QString &style)
{
    return new Run();
}

Paragraph::~Paragraph()
{

}

Run::Run()
  : Parented()
{

}

Run::~Run()
{

}

Text::Text()
{

}

Text::~Text()
{

}



}


