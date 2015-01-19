#ifndef OXMLSHAPE_H
#define OXMLSHAPE_H

#include <QString>

namespace Docx {

// <pic:pic>
class CT_Picture
{
public:
    CT_Picture(const QString &picId, const QString & fileName, const QString &rId, double cx, double cy);

    QString picXml();

    ~CT_Picture();

private:


};

// <w:inline>
class CT_Inline
{
public:
    CT_Inline(double cx, double cy, const QString &shapeId, CT_Picture *pic);
    QString inlineXml();

    virtual ~CT_Inline();

private:
    CT_Picture *m_pic;

};
}
#endif // OXMLSHAPE_H
