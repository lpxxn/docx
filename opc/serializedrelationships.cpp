#include "serializedrelationships.h"

#include <QDomDocument>

namespace Docx {

SerializedRelationship::SerializedRelationship()
{

}

SerializedRelationship::SerializedRelationship(const QString baseURI, const QString id
                                               , const QString relType, const QString target)
    : m_baseURI(baseURI), m_rId(id), m_relType(relType), m_target(target)
{

}

SerializedRelationship::~SerializedRelationship()
{

}

// End SerializedRelationship

SerializedRelationships::SerializedRelationships()
{

}

SerializedRelationships *SerializedRelationships::loadFromData(const QString baseURI, const QByteArray &relsXml)
{
    SerializedRelationships *rels = new SerializedRelationships();
    if (relsXml.isEmpty())
        return rels;

    QDomDocument dom;
    dom.setContent(relsXml);
    QDomNodeList nodes = dom.elementsByTagName(QStringLiteral("Relationship"));
    for (int i = 0; i < nodes.count(); i++) {
        QDomNode n = nodes.at(i);
        QDomElement ele = n.toElement();

        rels->m_rels.append(SerializedRelationship(baseURI,
                                                   ele.attribute(QStringLiteral("Id")),
                                                   ele.attribute(QStringLiteral("Type")),
                                                   ele.attribute(QStringLiteral("Target"))));
    }
    return rels;

}

SerializedRelationships::~SerializedRelationships()
{

}



}
