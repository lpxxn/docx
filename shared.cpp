#include "shared.h"

Shared::Shared()
{

}

Shared::~Shared()
{

}



Parented::Parented()
{
    //m_parent = parent;
}

Parented *Parented::part()
{
    return m_parent;
}

Parented::~Parented()
{
    delete m_parent;
}
