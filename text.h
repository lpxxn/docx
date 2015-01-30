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

class DOCX_EXPORT Paragraph : public Parented
{
public:

    Paragraph(QDomDocument *domDocument, const QDomElement &element);

    /*!
     * \brief 添加文本块
     * \param text
     * \param style
     * \return
     */
    Run* addRun(const QString &text = QString(), const QString &style = QString());

    void setStyle(const QString &style);

    /*!
     * \brief 对齐方式
     * \param align
     */
    void setAlignment(const WD_PARAGRAPH_ALIGNMENT &align);

    /*!
     * \brief 在本段落前添加段落
     * \param text
     * \param style
     * \return
     */
    Paragraph* insertParagraphBefore(const QString &text, const QString &style);

    virtual ~Paragraph();

private:    
    QDomDocument *m_dom;
    QDomElement *m_pEle;
    QList<Run *> m_runs;
    CT_PPr *m_style;
    friend class CT_PPr;

};

class DOCX_EXPORT Run : public Parented
{
public:    
    Run(QDomDocument *domDocument, QDomElement *parent);

    void addTab();
    void addText(const QString &text);

    /*!
     * \brief 设置样式
     * \param style
     */
    void setStyle(const QString &style);

    virtual ~Run();

    /*!
     * \brief 全部大写
     * \param isallcaps
     */
    void setAllcaps(bool isallcaps = true);


    /*!
     * \brief 加粗
     * \param isbold
     */
    void setBold(bool isbold = true);

    /*!
     * \brief 倾斜
     * \param isItalic
     */
    void setItalic(bool isItalic = true);

    /*!
     * \brief 又划线
     * \param isDoubleStrike
     */
    void setDoubleStrike(bool isDoubleStrike = true);

    /*!
     * \brief 下划线
     * \param underline
     */
    void setUnderLine(const WD_UNDERLINE &underline);

private:

    QString m_text;
    QDomDocument *m_dom;
    QDomElement m_rEle;
    QDomElement *m_parent;
    CT_RPr *m_style = nullptr;
    friend class CT_RPr;

};

class DOCX_EXPORT Text
{
public:
    Text();
    Text(QDomDocument *domDocument, QDomElement *parent);
    virtual ~Text();

private:
    QDomDocument *m_dom;
    QDomElement *m_parent;
};


}

#endif // TEXT_H
