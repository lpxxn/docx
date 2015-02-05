#include "shared.h"

#include <QCryptographicHash>
#include <QBuffer>

namespace Docx{


Parented::Parented()
{

}

Parented *Parented::part()
{
    return nullptr;
}

Parented::~Parented()
{
    //delete m_parent;
}

/*!
 * \brief 查找是否有eleName节点，如果没有则创建
 * \param dom
 * \param parent
 * \param eleName
 * \param addToFirst
 * \return
 */
QDomElement addOrAssignElement(QDomDocument *dom, QDomElement *parent, const QString &eleName, bool addToFirst)
{
    QDomNodeList elements = parent->elementsByTagName(eleName);

    if (elements.isEmpty()) {
        QDomElement ele = dom->createElement(eleName);
        if (addToFirst) {
            QDomNode firstnode = parent->firstChild();
            parent->insertBefore(ele, firstnode);
        } else {
            parent->appendChild(ele);
        }
        return ele;
    } else
        return elements.at(0).toElement();

}

/*!
 * \brief 图片的Hash
 * \param img
 * \return
 */
QByteArray imageHash(const QImage &img)
{
    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    img.save(&buffer);
    return QCryptographicHash::hash(ba, QCryptographicHash::Md5);
}

/*!
 * \brief QByteArray的Hash
 * \param bytes
 * \return
 */
QByteArray byteHash(const QByteArray &bytes)
{
    return QCryptographicHash::hash(bytes, QCryptographicHash::Md5);
}


}


