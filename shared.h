#ifndef DOCXSHARED_H
#define DOCXSHARED_H
#include <QDomElement>

namespace Docx
{
/*!
 * \brief 查找是否有eleName节点，如果没有则创建
 * \param dom
 * \param parent
 * \param eleName
 * \param addToFirst
 * \return
 */
QDomElement addOrAssignElement(QDomDocument *dom, QDomElement *parent, const QString &eleName, bool addToFirst = false);

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
