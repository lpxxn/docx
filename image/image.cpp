#include "image.h"

#include <QMimeDatabase>
#include <QMimeType>
#include <QBuffer>

namespace Docx {

Image::Image(const QString &path)
{
    m_img = QImage(path);
    m_imgSize = m_img.size();

    QMimeDatabase base;
    QMimeType fileInfo = base.mimeTypeForFile(path);
    m_horzDpi = m_img.logicalDpiX();
    m_vertDpi = m_img.logicalDpiY();
    m_ext = fileInfo.preferredSuffix();
    m_contentType = fileInfo.name();

}

QImage Image::img() const
{
    return m_img;
}

int Image::pxWidth() const
{
    return m_imgSize.width();
}

int Image::pxHeight() const
{
    return m_imgSize.height();
}

int Image::horzDpi() const
{
    return m_horzDpi;
}

int Image::vertDpi() const
{
    return m_vertDpi;
}

QString Image::ext() const
{
    return m_ext;
}

Image *Image::fromFile(const QString &imgPath)
{
    return nullptr;
}

Image::~Image()
{

}

}
