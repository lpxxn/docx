#include "document.h"

using namespace Docx;

#include <QDebug>

Document::Document()
{
    qDebug() << "construct docx document.";
}

Document::Document(const QString &name)
{
    qDebug() << "construct docx document from " << name;
}

Document::Document(QIODevice *device)
{
    qDebug() << "construct docx document from io";
}

Document::~Document()
{
    qDebug() << "delete Docx::Document.";
}

void Document::save(const QString &path)
{
    qDebug() << "save docx file: " << path;
}
