#ifndef Triangle_hpp
#define Triangle_hpp

#include "PrimitiveTriangle.hpp"
#include "Object.hpp"
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

class Triangle : private PrimitiveTriangle, public Object
{
public:
    Triangle();
    ~Triangle();
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};

#endif