#ifndef OPCDOCXPART_H
#define OPCDOCXPART_H

#include "../parts/imagepart.h"

#include <QString>
#include <QByteArray>

namespace Docx {

class Package;

class Part
{
public:
    Part(const QString &partName, const QString &contentType, const QByteArray &blob = QByteArray(), Package *package = nullptr);
    virtual Part *load(const QString &partName, const QString &contentType, const QByteArray &blob, Package *package = nullptr);
    virtual ~Part();

private:
    QString m_partName;
    QString m_contentType;
    QByteArray m_blob;
    Package *m_package;

};

class PartFactory
{
public:
    PartFactory();
    static Part* newPart(const QString partname, const QString contentType, const QString reltype, const QByteArray &blob = QByteArray(), Package *package = nullptr);

private:


};

class XmlPart : public Part
{
public:
    XmlPart(const QString &partName, const QString &contentType, const QByteArray &blob = QByteArray(), Package *package = nullptr);

    virtual ~XmlPart();
private:

};

}

#endif // PART_H
