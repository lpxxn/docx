#include "imagepart.h"
#include "../shared.h"

#include <QDebug>


namespace Docx {


ImagePart::ImagePart(const PackURI &partName, const QString &contentType, const QByteArray &blob, Docx::Image *image)
    : Part(partName, contentType, blob)
{
    if (blob.isEmpty()) {
        m_hash = imageHash(image->img());
        m_image = image;
    } else {
        m_image = new Image(m_blob, m_partName.ext());
        m_hash = byteHash(blob);
    }
}

QString ImagePart::fileName() const
{
    if (m_partName.isEmpty())
        return QString("image.%1").arg(m_image->ext());
    return m_partName.fileName();
}

Length ImagePart::defaultCx() const
{
    int px_width = m_image->pxWidth();
    int horz_dpi = m_image->horzDpi();
    float width_in_inches = (float)px_width / (float)horz_dpi;
    return Inches::emus(width_in_inches);
}

Length ImagePart::defaultCy() const
{
    int px_height = m_image->pxHeight();
    int horz_dpi = m_image->horzDpi();
    float height_in_inches = (float)(914400 * px_height) / (float)horz_dpi;
    return Emu::emus(height_in_inches);
}

ImagePart *ImagePart::load(const PackURI &partName, const QString &contentType, const QByteArray &blob, Image *image)
{
    qDebug() << "Image Name" << partName << "  image ext  " << partName.ext();
    return new ImagePart(partName, contentType, blob, image);
}

ImagePart *ImagePart::fromImage(const PackURI &partName, Image *image)
{
    qDebug() << "Image Name" << partName << "  image ext  " << partName.ext();
    return new ImagePart(partName, image->contentType(), image->blob(), image);
}

void ImagePart::afterUnmarshal()
{
}

Image *ImagePart::image() const
{    
    return m_image;
}

QByteArray ImagePart::hash() const
{
    return m_hash;
}

ImagePart::~ImagePart()
{
    delete m_image;
}

}
