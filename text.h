#ifndef TEXT_H
#define TEXT_H
#include "shared.h"
#include "docx_global.h"
#include <QString>

namespace Docx {
class Run;

class DOCX_EXPORT Paragraph : public Parented
{
public:
    Paragraph(Parented *parent);
    Run* addRun(const QString &text, const QString &style);


private:
};

class DOCX_EXPORT Run : public Parented
{
public:
    Run(Parented *parent);
};

class DOCX_EXPORT Text
{
public:
    Text();
    virtual ~Text();
};


}

#endif // TEXT_H
