#ifndef Bouncy2D_hpp
#define Bouncy2D_hpp

#include "../Engine/Drawable.hpp"

class Bouncy2D : public Drawable
{
private:
    Drawable* pDrawableChild;
public:
    UDim2f Velocity;
public:
    Bouncy2D(Drawable* obj, UDim2f Position, UDim2f Size);
    ~Bouncy2D();
public:
    void Update(float fdelta);
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};

#endif