#ifndef UDim_hpp
#define UDim_hpp

struct UDim2;
struct UDim3;
struct fVec3;

struct UDim2
{
    unsigned int x, y;
};

struct UDim3
{
    unsigned int x, y, z;
};

struct fVec3
{
    float x, y, z;
};

#endif