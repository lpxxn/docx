#ifndef OPCPACKAGE_H
#define OPCPACKAGE_H

#include <QString>
#include <QMap>

namespace Docx {

class PackageReader;
class Package;
class Part;

class OpcPackage
{
public:
    OpcPackage();
    static OpcPackage* open(const QString &pkgFile);
    virtual ~OpcPackage();

private:

};

class Unmarshaller
{
public:
    Unmarshaller();
    static void unmarshal(PackageReader *pkgReader, Package *package);
    static QMap<QString, Part *> unmarshalParts(PackageReader *pkgReader, Package *package);
    static void unmarshalRelationships(PackageReader *pkgReader, Package *package, const QMap<QString, Part *> &parts);
    virtual ~Unmarshaller();

};
}
#endif // OPCPACKAGE_H
