#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QString>

namespace Docx {

class Image
{
public:
    Image(const QString &path);
    QImage img() const;
    int pxWidth() const;
    int pxHeight() const;
    int horzDpi() const;
    int vertDpi() const;
    QString ext() const;
    static Image* fromFile(const QString &imgPath);
    ~Image();

private:
    QSize m_imgSize;
    QString m_ext;
    QString m_contentType;
    QImage m_img;
    int m_horzDpi;
    int m_vertDpi;
};
}

#endif // IMAGE_H
