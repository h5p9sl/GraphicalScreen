#include "Drawable.hpp"

Drawable::~Drawable()
{
    this->initialized = false;
    this->v_buffer->Release();
}
