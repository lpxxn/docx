#include "opcpackage.h"
#include "packagereader.h"

using namespace Docx;

OpcPackage::OpcPackage()
{

}

OpcPackage *OpcPackage::open(const QString &pkgFile)
{
    PackageReader *reader = PackageReader::fromFile(pkgFile);
    OpcPackage *package = new OpcPackage();
    return new OpcPackage();
}

OpcPackage::~OpcPackage()
{

}



Unmarshaller::Unmarshaller()
{

}

Unmarshaller::~Unmarshaller()
{

}
