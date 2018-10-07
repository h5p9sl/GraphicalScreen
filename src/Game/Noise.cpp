#include "Noise.hpp"

Noise::Noise(UDim2f pos, UDim2f size, unsigned count)
{
    this->Position = pos.x, pos.y;
    this->Size = size.x, size.y;

    for (unsigned i = 0; i < count; i++)
    {
        UDim2f randompos;
        randompos.x = rand() % (unsigned)size.x + (unsigned)pos.x;
        randompos.y = rand() % (unsigned)size.y + (unsigned)pos.y;
        Pixel pixel(randompos, 0);
        this->pixels.push_back(pixel);
    }
}

Noise::~Noise()
{
}

void Noise::Initialize(LPDIRECT3DDEVICE9 dev)
{
    this->initialized = true;
    for (auto i = pixels.begin(); i != pixels.end(); ++i)
    {
        DWORD colors[] = { 0xFFFF0000, 0xFF00FF00, 0xFF0000FF, 0xFFFFFF00, 0xFF00FFFF, 0xFFFF00FF, 0xFFFFFF };
        i->SetColor(colors[rand() % 7]);
    }
}

void Noise::Draw(LPDIRECT3DDEVICE9 dev)
{
    if (!this->initialized) this->Initialize(dev);

    for (auto i = pixels.begin(); i != pixels.end(); ++i)
    {
        UDim2f randompos;
        randompos.x = rand() % (unsigned)this->Size.x + (unsigned)this->Position.x;
        randompos.y = rand() % (unsigned)this->Size.y + (unsigned)this->Position.y;
        i->SetPosition(randompos);
        i->Draw(dev);
    }

}
