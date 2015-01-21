#include "physpkgreader.h"
#include "packuri.h"

#include <private/qzipreader_p.h>
#include <QByteArray>

namespace Docx {


PhysPkgReader::PhysPkgReader(const QString &filePath) :
    m_reader(new QZipReader(filePath))
{

}

// Return the '[Content_Types].xml' blob from the package
QByteArray PhysPkgReader::contentTypesData()
{
    return blobForm(QLatin1String("[Content_Types].xml"));
}

QByteArray PhysPkgReader::blobForm(const QString &packuri)
{
    return m_reader->fileData(packuri);
}

QByteArray PhysPkgReader::relsFrom(const PackURI &sourceUri)
{
    QString relstr = sourceUri.relsUriStr();
    return blobForm(relstr);
}

PhysPkgReader::~PhysPkgReader()
{

}

}
