#include "UDim.hpp"

// This class is meant to be inherited
// It is to be used to define 3D and 2D dimensional information
// Any class that inherits from Object is considered to be movable, resizable, rotatable, etc.

class Object
{
public:
    UDim3f Origin;
    UDim3f Size;
};