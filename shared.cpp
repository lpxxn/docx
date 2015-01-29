#include "shared.h"

namespace Docx{

Shared::Shared()
{

}

Shared::~Shared()
{

}



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


QDomElement addOrAssignElement(QDomDocument *dom, QDomElement *parent, const QString eleName, bool addToFirst)
{
    QDomNodeList elements = parent->elementsByTagName(eleName);

    if (elements.count() == 0) {
        QDomElement ele = dom->createElement(eleName);
        if (addToFirst) {
            QDomNode firstnode = parent->firstChild();
            parent->insertBefore(ele, firstnode);
        } else
            parent->appendChild(ele);

        return ele;
    } else
        return elements.at(0).toElement();

}
}
