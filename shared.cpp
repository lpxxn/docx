#include "shared.h"

using namespace Docx;

Shared::Shared()
{

}

Shared::~Shared()
{

}



Parented::Parented()
{

}

Parented *Parented::part()
{
    return nullptr;
}

Parented::~Parented()
{
    //delete m_parent;
}
