#ifndef BLKCNTNR_H
#define BLKCNTNR_H

#include "shared.h"

#include <QString>

namespace Docx {

class Paragraph;
class Table;

class BlockItemContainer : public Parented
{
public:
    BlockItemContainer();
    Paragraph* addParagraph(const QString &text, const QString &style);
    Table *addTable(int rows, int cols);

    virtual ~BlockItemContainer();
};
}

#endif // BLKCNTNR_H
