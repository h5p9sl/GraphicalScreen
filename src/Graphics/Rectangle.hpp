#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "Drawable.hpp"

class Window;

class Rectangle : public Drawable
{
public:
    virtual void Draw(const Window* window);
};

#endif