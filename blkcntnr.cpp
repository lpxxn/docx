#include "blkcntnr.h"
#include "text.h"
#include "table.h"

using namespace Docx;

BlockItemContainer::BlockItemContainer()
{

}

Paragraph *BlockItemContainer::addParagraph(const QString &text, const QString &style)
{
    return nullptr;
}

Table *BlockItemContainer::addTable(int rows, int cols)
{
    return new Table();
}

BlockItemContainer::~BlockItemContainer()
{

}

