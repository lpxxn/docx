#ifndef TABLE_H
#define TABLE_H
#include "docx_global.h"
#include "shared.h"

namespace Docx {
class DOCX_EXPORT Table : public Parented
{
public:
    Table();
    virtual ~Table();
};

class Column : public Parented
{
public:

private:
};
}
#endif // TABLE_H
