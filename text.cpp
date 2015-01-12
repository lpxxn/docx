#include "text.h"

namespace Docx {

/*!
 * \brief Paragraph::Paragraph
 * \param parent
 */
Paragraph::Paragraph(Parented *parent)
    : Parented()
{

}

Run *Paragraph::addRun(const QString &text, const QString &style)
{
    return new Run(nullptr);
}

/*!
 * \brief Run::Run
 * \param parent
 *
 *
 */
Run::Run(Parented *parent)
    : Parented()
{

}


/*!
 * \brief Text::Text
 */
Text::Text()
{

}

Text::~Text()
{

}

}
