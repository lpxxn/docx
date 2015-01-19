#ifndef PACKAGEREADER_H
#define PACKAGEREADER_H

#include <QString>

namespace Docx {
class PhysPkgReader;
class SerializedRelationships;

class PackageReader
{
public:
    PackageReader();
    static PackageReader* fromFile(const QString pkgFile);
    static SerializedRelationships* srelsFrom(PhysPkgReader *physReader, const QString sourceUri);

    ~PackageReader();
};

}

#endif // PACKAGEREADER_H
