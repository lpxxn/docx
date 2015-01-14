#include "packuri.h"
#include <string>

using namespace std;
using namespace Docx;

PackURI::PackURI(const QString &str)
    : QString(str)
{

}

PackURI PackURI::fromRelRef(const QString &baseURI, const QString &relative_ref)
{    
    return PackURI(QString().append(baseURI).append(relative_ref));
}

QString PackURI::baseURI()
{
    QStringList strs = pathSplit();

    return strs.first();
}

QString PackURI::fileName()
{
    QStringList strs = pathSplit();

    return strs.at(1);
}

PackURI PackURI::relsUri()
{
    QStringList strs = pathSplit();

    QString rels_filename = QString("%1.rels").arg(strs.at(1));
    QString rels_uri_str = QString("%1_rels%2").arg(strs.at(0)).arg(rels_filename);
    return PackURI(rels_uri_str);
}

QString PackURI::memberName()
{
    // remove first /
    return this->mid(1);
}

QString PackURI::ext()
{
    return this->split('.').last();
}


QString PackURI::relativeRef(const QString &baseURI)
{
    QString str;
    if (baseURI == "/")
        str = this->mid(1);
    else {
        str = this->replace(baseURI, "");
        if (str.startsWith('/'))
            str = str.mid(1);
    }

    return str;
}

PackURI::~PackURI()
{

}

QStringList PackURI::pathSplit()
{
    QStringList oStr;
    if (this->length() == 1) {
        oStr.append("/");
        oStr.append("");
        return oStr;
    }

    int i = this->toStdString().rfind('/');

    oStr.append(this->left(i));

    int l = oStr.length() - i - 1;

    oStr.append(this->right(l));
    return oStr;

}

