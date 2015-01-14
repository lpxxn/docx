#ifndef XMLCHEMY_H
#define XMLCHEMY_H

#include<QString>

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

}

#endif // XMLCHEMY_H
