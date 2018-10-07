#include "Noise.hpp"

Noise::Noise(UDim2f pos, UDim2f size, unsigned count)
{
    this->Origin = { pos.x, pos.y, 0 };
    this->Size = { size.x, size.y, 0 };

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
}

void Noise::Draw(LPDIRECT3DDEVICE9 dev)
{
    if (!this->initialized) this->Initialize(dev);

    for (auto i = pixels.begin(); i != pixels.end(); ++i)
    {
        UDim2f randompos;
        randompos.x = rand() % (unsigned)this->Size.x + (unsigned)this->Origin.x;
        randompos.y = rand() % (unsigned)this->Size.y + (unsigned)this->Origin.y;
        i->SetPosition(randompos);
        i->SetColor(D3DCOLOR_XRGB(rand() % 255, rand() % 255, rand() % 255));
        i->Draw(dev);
    }

}
