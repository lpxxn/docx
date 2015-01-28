#ifndef XMLCHEMY_H
#define XMLCHEMY_H

#include<QString>
#include<QDomElement>

namespace Docx {

class BaseChildElement
{
public:
    BaseChildElement(const QString &nsptagname, const QString &successors = "");

    virtual ~BaseChildElement();

private:
    QString m_nsptagname;
    QString m_successors;
};

class ZeroOrOne : public BaseChildElement
{
public:
    ZeroOrOne(const QString &nsptagname, const QString &successors = "");

    virtual ~ZeroOrOne();

private:
};

/*!
 * \brief base class for custom element classes standardized behavior
 */

class OxmlElementBase
{
public:
    OxmlElementBase();
    OxmlElementBase(QDomElement *x);
    void insertElementBefore(QDomElement *elm, const QString &tagname);

    virtual ~OxmlElementBase();

protected:
    QDomElement *m_element;

};

}

#endif // XMLCHEMY_H
