#ifndef OPCPACKURI_H
#define OPCPACKURI_H

#include <QStringList>

namespace Docx {

class PackURI : public QString
{
public:
    PackURI(const QString &str);
    static PackURI fromRelRef(const QString &baseURI, const QString &relative_ref);
    QString baseURI() const;
    QString fullURI() const;
    QString fileName() const;
    PackURI relsUri() const;
    QString relsUriStr() const;
    QString memberName() const;
    QString ext() const;
    QString relativeRef(const QString &baseURI);

    virtual ~PackURI();

private:
    QStringList pathSplit() const;
};

}

#endif // PACKURI_H
