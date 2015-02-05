#ifndef DOCXSHARED_H
#define DOCXSHARED_H

#include <QDomElement>
#include <QByteArray>
#include <QImage>

namespace Docx
{

QDomElement addOrAssignElement(QDomDocument *dom, QDomElement *parent, const QString &eleName, bool addToFirst = false);

QByteArray imageHash(const QImage &img);

QByteArray byteHash(const QByteArray &bytes);

class Parented
{
public:
    Parented();
    Parented* part();

    virtual ~Parented();

private:

};
}

#endif // SHARED_H
