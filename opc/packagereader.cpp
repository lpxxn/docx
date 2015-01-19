#include "packagereader.h"
#include "physpkgreader.h"
#include "contenttypemap.h"
#include "serializedrelationships.h"
#include "packuri.h"


namespace Docx {


PackageReader::PackageReader()
{

}

PackageReader *PackageReader::fromFile(const QString pkgFile)
{
    PhysPkgReader *physReader = new PhysPkgReader(pkgFile);
    ContentTypeMap *contentypes = ContentTypeMap::fromXml(physReader->contentTypesData());


    return new PackageReader();
}

SerializedRelationships *PackageReader::srelsFrom(PhysPkgReader *physReader, const QString sourceUri)
{
    QByteArray rels_xml = physReader->relsFrom(PackURI(sourceUri));

    return nullptr;
}

PackageReader::~PackageReader()
{

}

}
