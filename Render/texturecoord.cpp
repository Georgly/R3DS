#include "texturecoord.h"

TextureCoord :: TextureCoord()
{
        u = 0;
        v = 0;
        w = 0;
}

TextureCoord :: TextureCoord(float u, float v, float w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }

