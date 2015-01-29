#ifndef OXMLDOCXTEXT_H
#define OXMLDOCXTEXT_H

#include "xmlchemy.h"

namespace Docx {
class Run;
class Paragraph;

class CT_P : public OxmlElementBase
{
public:
    CT_P(QDomElement *element);

    virtual ~CT_P();

private:

};


/*!
 * \brief 段落的属性
 */
class CT_PPr
{
public:
    CT_PPr(Paragraph *paragraph);
    void setStyle(const QString &style = QString());
    void addOrAssignStyle();
    virtual ~CT_PPr();


private:
    QDomElement m_style;
    QDomElement m_pStyle;
    Paragraph *m_paragraph;

};


class CT_RPr
{
public:
    CT_RPr(Run *run);
    void setStyle(const QString &style = QString());
    void setBold(bool bold);
    virtual ~CT_RPr();    

private:
    void addOrAssignStyle();

private:
    Run *m_run;
    QDomElement m_style;
    QDomElement m_rStyle;
};

}

#endif // TEXT_H
