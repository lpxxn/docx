#ifndef PACKURI_H
#define PACKURI_H

#include <QString>
#include <QStringList>

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

    ~PackURI();
private:
    QStringList pathSplit();
};

#endif // PACKURI_H
