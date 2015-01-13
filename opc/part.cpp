#include "part.h"


Part::Part(const QString &partName, const QString &contentType, const QString &blob, Package *package)
{
    m_partName = partName;
    m_contentType = contentType;
    m_blob = blob;
    m_package = package;
}

Part* Part::load(const QString &partName, const QString &contentType, const QString &blob, Package *package)
{
    return Part(partName, contentType, blob, package);
}

Part::~Part()
{

}

PartFactory* PartFactory::stPartfactory = nullptr;

PartFactory *PartFactory::instance()
{
    if (stPartfactory == nullptr)
        stPartfactory = new PartFactory();
    return stPartfactory;
}

PartFactory::PartFactory()
{

}

