#ifndef Drawable_hpp
#define Drawable_hpp

#include <d3d9.h>

class Window;

class Drawable
{
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice) = 0;
};

#endif