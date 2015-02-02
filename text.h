#ifndef DOCXTEXT_H
#define DOCXTEXT_H

#include "docx_global.h"
#include "shared.h"
#include "./enums/enumtext.h"

#include <QString>
#include <QDomElement>
#include <QList>

class QDomDocument;

namespace Docx {
class Run;
class Text;
class CT_RPr;
class CT_PPr;
class DocumentPart;

class DOCX_EXPORT Paragraph : public Parented
{
public:

    Paragraph(DocumentPart *part, const QDomElement &element);

    /*!
     * \brief 添加文本块
     * \param text
     * \param style
     * \return
     */
    Run* addRun(const QString &text = QString(), const QString &style = QString());

    void addText(const QString &text);

    /*!
     * \brief 所有字体
     * \return
     */
    QString text() const;

    /*!
     * \brief 设置样式
     * \param style
     */
    void setStyle(const QString &style);

    /*!
     * \brief 对齐方式
     * \param align
     */
    void setAlignment(WD_PARAGRAPH_ALIGNMENT align);

    /*!
     * \brief 在本段落前添加段落
     * \param text
     * \param style
     * \return
     */
    Paragraph* insertParagraphBefore(const QString &text, const QString &style);

    virtual ~Paragraph();

private:
    DocumentPart *m_part;
    QDomDocument *m_dom;
    QDomElement *m_pEle;
    QList<Run *> m_runs;
    CT_PPr *m_style;
    friend class CT_PPr;

};

class DOCX_EXPORT Run : public Parented
{
public:    
    Run(DocumentPart *part, QDomElement *parent);

    void addTab();

    void addText(const QString &text);
    QString text() const;

    void setStyle(const QString &style);

    virtual ~Run();

    void setAllcaps(bool isallcaps = true);

    void setSmallcaps(bool smallcpas = true);

    void setBold(bool isbold = true);

    void setItalic(bool isItalic = true);

    void setDoubleStrike(bool isDoubleStrike = true);

    void setShadow(bool shadow = true);

    void setUnderLine(const WD_UNDERLINE &underline);

private:

    QString m_text;
    DocumentPart *m_part;
    QDomDocument *m_dom;
    QDomElement m_rEle;
    QDomElement *m_parent;
    CT_RPr *m_style = nullptr;
    friend class CT_RPr;

};


}

#endif // TEXT_H
