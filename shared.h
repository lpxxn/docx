#ifndef SHARED_H
#define SHARED_H

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
    Parented *m_parent;
};

#endif // SHARED_H
