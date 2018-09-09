#include "Triangle.hpp"

void Triangle::Draw(LPDIRECT3DDEVICE9 dev)
{
    dev->DrawPrimitive(D3DPT_POINTLIST, this->p[0].x, 3);
}