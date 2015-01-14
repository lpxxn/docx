#include "blkcntnr.h"
#include "text.h"
#include "table.h"
using namespace Docx;

BlockItemContainer::BlockItemContainer()
{

}

Paragraph *BlockItemContainer::addParagraph(const QString &text, const QString &style)
{
    return new Paragraph();
}

Table *BlockItemContainer::addTable(const int rows, const int cols)
{
    return new Table();
}

BlockItemContainer::~BlockItemContainer()
{

}

