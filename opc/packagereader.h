#ifndef PACKAGEREADER_H
#define PACKAGEREADER_H

#include "serializedrelationships.h"

#include <QString>
#include <QList>

namespace Docx {

class PhysPkgReader;
class SerializedRelationships;
class ContentTypeMap;

class PackageReader
{
public:
    PackageReader(SerializedRelationships *srels, ContentTypeMap *contentTypes, const QList<SerializedPart> &sparts);
    static PackageReader* fromFile(const QString &pkgFile);
    static SerializedRelationships* srelsFrom(PhysPkgReader *physReader, const QString &sourceUri);
    static QList<SerializedPart> loadSerializedParts(PhysPkgReader *physReader, const SerializedRelationships *srels, const ContentTypeMap *contentTypes);

    ~PackageReader();

private:
    SerializedRelationships *m_srels;
    ContentTypeMap *m_contentTypes;
    QList<SerializedPart> m_sparts;
};

}

#endif // PACKAGEREADER_H
