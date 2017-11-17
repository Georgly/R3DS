#ifndef CAMERA_H
#define CAMERA_H
#include "vertex.h"

class Camera
{
public:
    Camera();
    Vertex *position = new Vertex();
    Vertex *target = new Vertex();
};

#endif // CAMERA_H
