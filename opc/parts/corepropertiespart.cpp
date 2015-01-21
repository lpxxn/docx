#include "corepropertiespart.h"

using namespace Docx;

CorePropertiesPart::CorePropertiesPart(const QString &partName, const QString &contentType
                                       , const QByteArray &blob, Package *package)
    : XmlPart(partName, contentType, blob, package)
{

}

CorePropertiesPart::~CorePropertiesPart()
{

}

