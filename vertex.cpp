#include "vertex.h"


Vertex :: Vertex ()
    {
//        x = 0;
//        y = 0;
//        z = 0;
//        isPosition = 1;
        vector[0] = 0;
        vector[1] = 0;
        vector[2] = 0;
        vector[3] = 1;
    }

Vertex :: Vertex (float x, float y, float z)
    {
//        this->x = x;
//        this->y = y;
//        this->z = z;
//        this->isPosition = 1;
        vector[0] = x;
        vector[1] = y;
        vector[2] = z;
        vector[3] = 1;
    }
