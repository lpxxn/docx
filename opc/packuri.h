#ifndef OPCPACKURI_H
#define OPCPACKURI_H

#include <QString>
#include <QStringList>

namespace Docx {

class PackURI : public QString
{
public:
    PackURI(const QString &str);
    static PackURI fromRelRef(const QString &baseURI, const QString &relative_ref);
    QString baseURI();
    QString fileName();
    PackURI relsUri();
    QString memberName();
    QString ext();
    QString relativeRef(const QString &baseURI);

    virtual ~PackURI();
private:
    QStringList pathSplit();
};
}

#endif // PACKURI_H
