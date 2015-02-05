#include "shape.h"
#include "./oxml/oxmlshape.h"
#include "text.h"
#include "./parts/imagepart.h"

namespace Docx {

InlineShape::InlineShape(CT_Inline *inlinev)
    : m_inline(inlinev)
{

}

int InlineShape::width()
{
    QString value = m_inline->m_extent.attribute(QStringLiteral("cx"), "0");
    return value.toInt();
}

void InlineShape::setWidth(int width)
{
    m_inline->m_extent.setAttribute(QStringLiteral("cx"), QString::number(width));
}

int InlineShape::height()
{
    QString value = m_inline->m_extent.attribute(QStringLiteral("cy"), "0");
    return value.toInt();
}

void InlineShape::setHeight(int height)
{
    m_inline->m_extent.setAttribute(QStringLiteral("cy"), QString::number(height));
}

InlineShape::~InlineShape()
{

}



}
