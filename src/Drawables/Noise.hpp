#pragma once

#include <vector>

#include "../Engine/Drawable.hpp"
#include "../UDim.hpp"
#include "Pixel.hpp"

class Noise : public Drawable
{
private:
    LPDIRECT3DVERTEXBUFFER9 v_buffer;
    std::vector<Pixel> pixels;
public:
    Noise(UDim2f pos, UDim2f size, unsigned count);
    ~Noise();
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};