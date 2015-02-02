#include "imagepart.h"
#include "../shared.h"


namespace Docx {


ImagePart::ImagePart(const PackURI &partName, const QString &contentType, const QByteArray &blob, Docx::Image *image)
    : Part(partName, contentType, blob)
{
    if (blob.isEmpty()) {
        m_hash = imageHash(image->img());
    } else {
        m_hash = byteHash(blob);
    }
    m_image = image;
}

ImagePart *ImagePart::load(const PackURI &partName, const QString &contentType, const QByteArray &blob, Image *image)
{
    return new ImagePart(partName, contentType, blob, image);
}

void ImagePart::afterUnmarshal()
{
}

Image *ImagePart::image() const
{
    if (m_image == nullptr) {
        return nullptr;
    }
    return m_image;
}

QByteArray ImagePart::Hash() const
{
    return m_hash;
}

ImagePart::~ImagePart()
{

}

}
