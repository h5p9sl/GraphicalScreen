#ifndef Noise_hpp
#define Noise_hpp

#include <vector>

#include "../Engine/Drawable.hpp"
#include "../Engine/UDim.hpp"
#include "../Engine/Graphics/Pixel.hpp"

class Noise : public Drawable
{
private:
    LPDIRECT3DVERTEXBUFFER9 v_buffer;
    std::vector<Pixel> pixels;
public:
    UDim2f Position;
    UDim2f Size;
public:
    Noise(UDim2f pos, UDim2f size, unsigned count);
    ~Noise();
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};

#endif