#ifndef DOCXTEXT_H
#define DOCXTEXT_H
#include "shared.h"
#include "docx_global.h"
#include <QString>

namespace Docx {
class Run;

class DOCX_EXPORT Paragraph : public Parented
{
public:
    Paragraph();

    Run* addRun(const QString &text, const QString &style);

    virtual ~Paragraph();

private:


};

class DOCX_EXPORT Run : public Parented
{
public:
    Run();

    virtual ~Run();

};

class DOCX_EXPORT Text
{
public:
    Text();
    virtual ~Text();
};


}

#endif // TEXT_H
