#ifndef OPCDOCXPART_H
#define OPCDOCXPART_H

#include "packuri.h"

#include <QString>
#include <QByteArray>

namespace Docx {

class Package;
class ImagePart;
class OpcPackage;
class Relationships;

class Part
{
public:
    Part(const PackURI &partName, const QString &contentType, const QByteArray &blob = QByteArray(), Package *package = nullptr);
    static Part *load(const PackURI &partName, const QString &contentType, const QByteArray &blob, Package *package = nullptr);
    virtual void loadRel(const QString &reltype, const QString &targetRef, Part *target, const QString rId, bool isternal);
    PackURI partName() const;
    QString contentType() const;
    virtual QByteArray blob() const;
    Relationships *rels() const;
    virtual void afterUnmarshal();

    virtual ~Part();

private:
    PackURI m_partName;
    QString m_contentType;
    QByteArray m_blob;
    Package *m_package;
    Relationships *m_rels;

};

class PartFactory
{
public:
    PartFactory();
    static Part* newPart(const PackURI &partname, const QString &contentType, const QString &reltype, const QByteArray &blob = QByteArray(), Package *package = nullptr);

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
