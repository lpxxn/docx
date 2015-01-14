#ifndef DOCXSHARED_H
#define DOCXSHARED_H

namespace Docx
{

class Shared
{
public:
    Shared();
    virtual ~Shared();
};

class Parented
{
public:
    Parented();
    Parented* part();

    virtual ~Parented();

private:

};
}

#endif // SHARED_H
