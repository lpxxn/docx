#include "oxmlshape.h"

namespace Docx {

CT_Picture::CT_Picture(const QString &picId, const QString &fileName, const QString &rId, double cx, double cy)
{

}

QString CT_Picture::picXml()
{
    return "";
}

CT_Picture::~CT_Picture()
{

}


CT_Inline::CT_Inline(double cx, double cy, const QString &shapeId, CT_Picture *pic)
{

}

QString CT_Inline::inlineXml()
{
    return "";
}

CT_Inline::~CT_Inline()
{

}




}

