#ifndef SHARED_H
#define SHARED_H

class Shared
{
public:
    Shared();
    ~Shared();
};

class Parented
{
public:
    Parented();
    Parented* part();

    ~Parented();

private:
    Parented *m_parent;
};

#endif // SHARED_H
