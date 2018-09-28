#include "Triangle.hpp"

PrimitiveTriangle::PrimitiveTriangle(UDim3f Vertices[3], DWORD Color[3])
{
    this->SetColor(Color);
    this->SetVertices(Vertices);
}

PrimitiveTriangle::PrimitiveTriangle(UDim3f Vertices[3], DWORD Color)
{
    this->SetColor(Color);
    this->SetVertices(Vertices);
}

PrimitiveTriangle::PrimitiveTriangle()
{
}

PrimitiveTriangle::~PrimitiveTriangle()
{
    this->v_buffer->Release();
}

void PrimitiveTriangle::SetColor(DWORD Color)
{
    for (unsigned i = 0; i < 3; i++)
        this->vertices[i].color = Color;
}

void PrimitiveTriangle::SetColor(DWORD Color[3])
{
    for (unsigned i = 0; i < 3; i++)
        this->vertices[i].color = Color[i];
}

void PrimitiveTriangle::SetVertices(UDim3f Vertices[3])
{
    for (unsigned i = 0; i < 3; i++) {
        this->vertices[i].vertex = Vertices[i];
    }
}

void PrimitiveTriangle::Initialize(LPDIRECT3DDEVICE9 dev)
{
    this->initialized = true;
    
    // Create vertex buffer and store it in v_buffer
    dev->CreateVertexBuffer(
        sizeof(PrimitiveVertex) * 3,
        0,
        PrimitiveVertexFVF,
        D3DPOOL_MANAGED,
        &this->v_buffer,
        NULL
    );
    
    if (v_buffer) {
        // Tells Direct3D that we need complete control of the memory.
        // Tells the video hardware not to mess around with the memory while we are working with it.
        v_buffer->Lock(0, sizeof(vertices), &pBuffer, 0);
        // Now we can call memcpy() to copy the Vertices to the vertex buffer
        memcpy(pBuffer, vertices, sizeof(vertices));
        // Unlock memory, we are done using it
        v_buffer->Unlock();
    }
}

void PrimitiveTriangle::Draw(LPDIRECT3DDEVICE9 dev)
{
    if (!this->initialized) {
        this->Initialize(dev);
    }
    // Now, on to the actual drawing part.
    // We will set the FVF mode to our custom FVF
    dev->SetFVF(PrimitiveVertexFVF);
    // Next we need to call the function SetStreamSource, which tells DirectX where the vertices are located.
    dev->SetStreamSource(0, this->v_buffer, 0, sizeof(PrimitiveVertex));
    // Now we can finally call DrawPrimitive, which does the rest for us
    dev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}