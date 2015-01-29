#ifndef DOCXSHARED_H
#define DOCXSHARED_H
#include <QDomElement>

namespace Docx
{
QDomElement addOrAssignElement(QDomDocument *dom, QDomElement *parent, const QString eleName, bool addToFirst = false);

class Shared
{
public:
    Shared();
    virtual ~Shared();
};

class Parented
{
public:
    Parented();
    Parented* part();

    virtual ~Parented();

private:

};
}

#endif // SHARED_H
