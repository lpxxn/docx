#include "shape.h"
#include "./oxml/oxmlshape.h"

namespace Docx {

InlineShape::InlineShape(CT_Inline *inlinev)
    : m_inline(inlinev)
{

}

double InlineShape::height()
{
    return 0.0;
}

void InlineShape::setHeight(double height)
{

}

double InlineShape::width()
{
    return 0.0;
}

void InlineShape::setWidth(double width)
{

}

InlineShape::~InlineShape()
{

}



}
