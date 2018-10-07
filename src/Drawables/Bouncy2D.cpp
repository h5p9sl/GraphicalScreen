#include "Bouncy2D.hpp"

Bouncy2D::Bouncy2D(Drawable* obj, UDim2f Position, UDim2f Size)
{
    this->pDrawableChild = obj;
    this->Size = Size;
    this->Position = Position;

    this->pDrawableChild->Size = Size;
    this->pDrawableChild->Position = this->Position;
}

Bouncy2D::~Bouncy2D()
{
}

void Bouncy2D::Draw(LPDIRECT3DDEVICE9 D3DDevice)
{
    if (!this->initialized) this->Initialize(D3DDevice);
    this->pDrawableChild->Draw(D3DDevice);
}

void Bouncy2D::Update(float fdelta)
{
    // Increment position by velocity
    // And detect collisions with window borders
    // TODO: Detect parent window resolution
    // TODO: Add RNG


    // COLLISION DETECTION
    // X axis
    this->Position.x += this->Velocity.x * fdelta;
    if (Position.x >= 640.f - Size.x) {
        this->Position.x = 640.f - Size.x;
        this->Velocity.x -= this->Velocity.x * 2;
    }
    if (Position.x <= 0.f) {
        this->Position.x = 0.f;
        this->Velocity.x -= this->Velocity.x * 2;
    }
    // Y axis
    this->Position.y += this->Velocity.y * fdelta;
    if (Position.y >= 480.f - Size.y) {
        this->Position.y = 480.f - Size.y;
        this->Velocity.y -= this->Velocity.y * 2;
    }
    if (Position.y <= 0.f) {
        this->Position.y = 0.f;
        this->Velocity.y -= this->Velocity.y * 2;
    }

    this->pDrawableChild->Position = this->Position;
}

void Bouncy2D::Initialize(LPDIRECT3DDEVICE9 D3DDevice)
{
    this->initialized = true;
}
