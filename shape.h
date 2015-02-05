#ifndef SHAPE_H
#define SHAPE_H

#include "docx_global.h"

namespace Docx {
class CT_Inline;
class Run;
class ImagePart;

class DOCX_EXPORT InlineShape
{
public:
    InlineShape(CT_Inline *inlinev);    
    int width();
    void setWidth(int width);
    int height();
    void setHeight(int height);

    virtual ~InlineShape();

private:
    CT_Inline* m_inline;

};

}
#endif // SHAPE_H
