#ifndef CONTENTTYPEMAP_H
#define CONTENTTYPEMAP_H

#include "packuri.h"

#include <QString>
#include <QMap>

namespace Docx {


class ContentTypeMap
{
public:
    ContentTypeMap();
    static ContentTypeMap* fromXml(const QByteArray &contentTypesXml);
    void addDefault(const QString &extension, const QString &contentType);
    void addOverride(const QString &partName, const QString &contentType);
    QString contentType(const PackURI &partname) const;
    ~ContentTypeMap();

private:
    QMap<QString, QString> m_overrides;
    QMap<QString, QString> m_defaults;


};

}

#endif // CONTENTTYPEMAP_H
