#pragma once

#include "../Engine/Drawable.hpp"
#include "../Engine/UDim.hpp"
#include "../Engine/Graphics/PrimitiveRectangle.hpp"

class PhysicsBox2D : public Drawable
{
private:
    PrimitiveRectangle* rectangleChild;
public:
    UDim2f Velocity;
public:
    PhysicsBox2D();
    ~PhysicsBox2D();
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};