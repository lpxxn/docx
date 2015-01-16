#ifndef SHAPE_H
#define SHAPE_H


namespace Docx {
class CT_Inline;

class InlineShape
{
public:
    InlineShape(CT_Inline *inlinev);

    double height();
    void setHeight(double height);
    double width();
    void setWidth(double width);

    virtual ~InlineShape();

private:
    CT_Inline m_inline;

};

}
#endif // SHAPE_H
