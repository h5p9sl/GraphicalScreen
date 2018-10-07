#ifndef PrimitveTriangle_hpp
#define PrimitveTriangle_hpp

#include "Drawable.hpp"
#include "UDim.hpp"
//
//
//
//
#include <stdio.h> // Remove later; debugging
//
//
//
//

class PrimitiveTriangle : public Drawable
{
private:
    LPDIRECT3DVERTEXBUFFER9 v_buffer;
    PrimitiveVertex vertices[3];
public:
    PrimitiveTriangle(UDim3f Vertices[3], DWORD Color[3]);
    PrimitiveTriangle(UDim3f Vertices[3], DWORD Color);
    PrimitiveTriangle();
    ~PrimitiveTriangle();

    void SetColor(DWORD Color[3]);
    void SetColor(DWORD Color);
    void SetVertices(UDim3f Vertices[3]);
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};

#endif