#ifndef Pixel_hpp
#define Pixel_hpp

#include "Drawable.hpp"
#include "UDim.hpp"

class Pixel : public Drawable
{
private:
    LPDIRECT3DVERTEXBUFFER9 v_buffer;
    PrimitiveVertex vertices;
public:
    Pixel(UDim2f v, DWORD c);
    ~Pixel();
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};

#endif