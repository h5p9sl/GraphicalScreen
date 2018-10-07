#include "Triangle.hpp"

Triangle::Triangle()
    : PrimitiveTriangle()
{
    
}

Triangle::~Triangle()
{
}

void Triangle::Initialize(LPDIRECT3DDEVICE9 dev)
{
    this->initialized = true;
    this->PrimitiveTriangle::Initialize(dev);
}

void Triangle::Draw(LPDIRECT3DDEVICE9 dev)
{

}