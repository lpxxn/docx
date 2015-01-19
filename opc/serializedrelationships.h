#ifndef SERIALIZEDRELATIONSHIPS_H
#define SERIALIZEDRELATIONSHIPS_H

#include <QVector>
#include <QString>
#include <QByteArray>

namespace Docx {

class SerializedRelationship
{
public:
    SerializedRelationship();
    SerializedRelationship(const QString baseURI, const QString id, const QString relType, const QString target);
    ~SerializedRelationship();

private:
    QString m_baseURI;
    QString m_rId;
    QString m_relType;
    QString m_target;

};


class SerializedRelationships
{
public:
    SerializedRelationships();
    static SerializedRelationships* loadFromData(const QString baseURI, const QByteArray &relsXml);

    ~SerializedRelationships();

private:
    QVector<SerializedRelationship> m_rels;
};

}

#endif // SERIALIZEDRELATIONSHIPS_H
