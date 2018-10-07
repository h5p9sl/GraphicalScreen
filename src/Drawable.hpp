#ifndef Drawable_hpp
#define Drawable_hpp

#include "UDim.hpp"
#include <d3d9.h>

class Window;

#define PrimitiveVertexFVF D3DFVF_XYZRHW | D3DFVF_DIFFUSE
struct PrimitiveVertex
{
    UDim3f vertex;
    float rhs = 1.f;
    DWORD color;
};

class Drawable
{
public:
    UDim3f Origin;
    UDim3f Size;
protected:
    void* pBuffer;
    bool initialized = false;
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice) = 0;
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice) = 0;
};

#endif