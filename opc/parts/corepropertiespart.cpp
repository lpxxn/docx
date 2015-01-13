#include "corepropertiespart.h"



CorePropertiesPart::CorePropertiesPart(const QString &partName, const QString &contentType
                                       , const QString &blob, Package *package)
    : XmlPart(partName, contentType, blob, package)
{

}

CorePropertiesPart::~CorePropertiesPart()
{

}

