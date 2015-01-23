#ifndef COREPROPERTIESPART_H
#define COREPROPERTIESPART_H

#include <QString>
#include <QByteArray>

#include "../part.h"
#include "../../package.h"

namespace Docx {


class CorePropertiesPart : public XmlPart
{
public:
    CorePropertiesPart(const QString &partName, const QString &contentType
                       , const QByteArray &blob, Package *package = nullptr);
    static void load(const QString &partName, const QString &contentType
                , const QByteArray &blob, Package *package = nullptr);
    virtual ~CorePropertiesPart();

    void afterUnmarshal();
};

}
#endif // COREPROPERTIESPART_H
