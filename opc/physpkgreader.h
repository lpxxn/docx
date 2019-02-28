#ifndef PHYSPKGREADER_H
#define PHYSPKGREADER_H

#include <QScopedPointer>
#include <QStringList>
#include <QIODevice>

class QByteArray;
class QZipReader;

namespace Docx {
class PackURI;
class PhysPkgReader
{
public:
    PhysPkgReader(const QString &filePath);
    PhysPkgReader(QIODevice *device);
    QByteArray contentTypesData();
    QByteArray blobForm(const QString &packuri);
    QByteArray relsFrom(const PackURI &sourceUri);    

    ~PhysPkgReader();    

private:
    QScopedPointer<QZipReader> m_reader;

};
}

#endif // PHYSPKGREADER_H
