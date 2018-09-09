#ifndef Triangle_hpp
#define Triangle_hpp

#include "Drawable.hpp"
#include "UDim.hpp"

class Window;

class Triangle : public Drawable
{
public:
    UDim3 p[3];
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};

#endif