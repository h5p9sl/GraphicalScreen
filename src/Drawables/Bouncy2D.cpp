#include "Bouncy2D.hpp"

Bouncy2D::Bouncy2D(Drawable* obj, UDim2f Size, UDim2f Position)
{
    this->pDrawableChild = obj;
    this->Size = Size;
    this->Position = Position;

    this->pDrawableChild->Size = {this->Size.x, this->Size.y, 0.f};
    this->pDrawableChild->Origin = {this->Position.x, this->Position.y, 0.f};
}

Bouncy2D::~Bouncy2D()
{
}

void Bouncy2D::Draw(LPDIRECT3DDEVICE9 D3DDevice)
{
    this->pDrawableChild->Draw(D3DDevice);
}

void Bouncy2D::Update(float fdelta)
{
    // Increment position by velocity
    // And detect collisions with window borders
    // TODO: Detect parent window resolution
    // TODO: Add RNG
    this->Position.x += this->Velocity.x * fdelta;
    if (Position.x > 640.f) {
        this->Position = 640.f;
        this->Velocity.x -= this->Velocity.x * 2;
    }
    if (Position.x < 0.f) {
        this->Position = 0.f;
        this->Velocity.x -= this->Velocity.x * 2;
    }

    this->Position.y += this->Velocity.y * fdelta;
    if (Position.y > 480.f) {
        this->Position = 480.f;
        this->Velocity.y -= this->Velocity.y * 2;
    }
    if (Position.y < 0.f) {
        this->Position = 0.f;
        this->Velocity.y -= this->Velocity.y * 2;
    }

    this->pDrawableChild->Origin = {this->Position.x, this->Position.y, 0.f};
}