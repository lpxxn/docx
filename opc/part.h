#ifndef PART_H
#define PART_H
#include <QString>

class Package;

class Part
{
public:
    Part(const QString &partName, const QString &contentType, const QString &blob, Package *package = nullptr);
    virtual Part *load(const QString &partName, const QString &contentType, const QString &blob, Package *package = nullptr);
    virtual ~Part();

private:
    QString m_partName;
    QString m_contentType;
    QString m_blob;
    Package *m_package;

};

class PartFactory
{
public:
    static PartFactory* instance();

private:
    PartFactory();

private:
    static PartFactory *stPartfactory;

};

class XmlPart : public Part
{
public:
    XmlPart(const QString &partName, const QString &contentType, const QString &blob, Package *package = nullptr);

    virtual ~XmlPart();
private:

};



#endif // PART_H
