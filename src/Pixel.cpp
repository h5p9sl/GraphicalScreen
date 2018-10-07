#include "Pixel.hpp"

Pixel::Pixel(UDim2f v, DWORD c)
{
    this->vertices.vertex.x = v.x;
    this->vertices.vertex.y = v.y;
    this->vertices.vertex.z = 0.f;
    this->vertices.color = c;
    this->vertices.rhs = 1.f;
}

Pixel::~Pixel()
{
    this->v_buffer->Release();
}

void Pixel::Initialize(LPDIRECT3DDEVICE9 dev)
{
    this->initialized = true;

    dev->CreateVertexBuffer(
        sizeof(PrimitiveVertex),
        0,
        PrimitiveVertexFVF,
        D3DPOOL_MANAGED,
        &this->v_buffer,
        NULL
    );
    
    if (v_buffer) {
        v_buffer->Lock(0, sizeof(vertices), &pBuffer, 0);
        memcpy(pBuffer, &vertices, sizeof(vertices));
        v_buffer->Unlock();
    }
}

void Pixel::Draw(LPDIRECT3DDEVICE9 dev)
{
    if (!this->initialized)
        this->Initialize(dev);
    
    dev->SetFVF(PrimitiveVertexFVF);

    dev->SetStreamSource(0, this->v_buffer, 0, sizeof(PrimitiveVertex));

    dev->DrawPrimitive(D3DPT_POINTLIST, 0, 1);
}