#pragma once

#include "../Engine/Graphics/PrimitiveRectangle.hpp"

class PhysicsBox : public PrimitiveRectangle
{
public:
    PhysicsBox();
    ~PhysicsBox();
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};