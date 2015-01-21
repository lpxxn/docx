#include "part.h"
#include "constants.h"

namespace Docx {

Part::Part(const QString &partName, const QString &contentType, const QByteArray &blob, Package *package)
{
    m_partName = partName;
    m_contentType = contentType;
    m_blob = blob;
    m_package = package;
}

Part* Part::load(const QString &partName, const QString &contentType, const QByteArray &blob, Package *package)
{
    return new Part(partName, contentType, blob, package);
}

Part::~Part()
{

}

PartFactory::PartFactory()
{

}

Part *PartFactory::newPart(const QString partname, const QString contentType, const QString reltype, const QByteArray &blob, Package *package)
{
    if (reltype == Constants::IMAGE){
        return nullptr;
    }
    if (contentType == Constants::WML_DOCUMENT_MAIN) {
        return nullptr;
    } else if (contentType == Constants::OPC_CORE_PROPERTIES) {
        return nullptr;
    } else if (contentType == Constants::WML_NUMBERING) {
        return nullptr;
    } else if (contentType == Constants::WML_STYLES) {
        return nullptr;
    }
}

// end PartFactory


// XmlPart start

XmlPart::XmlPart(const QString &partName, const QString &contentType, const QByteArray &blob, Package *package)
    : Part(partName, contentType, blob, package)
{

}

XmlPart::~XmlPart()
{

}

}
