#include "face.h"


Face :: Face()
{

}

bool Face :: addFace(QStringList indexes,
                     int maxVertexIndex, int maxTextureCoorIndex, int maxNormalVectorIndex, QString& errorStr)
{
    if (indexes[0].toInt() > maxVertexIndex)
    {
        errorStr = "Refference on unexistable vertex";
        return false;
    }

    switch (indexes.count())
    {
        case 1:
        {
            vertexIndex.push_back(indexes[0].toInt());
            break;
        }
        case 2:
        {
        if (indexes[1].toInt() > maxTextureCoorIndex)
        {
            errorStr = "Refference on unexistable texture coord";
            return false;
        }
            vertexIndex.push_back(indexes[0].toInt());
            textureCoordIndex.push_back(indexes[1].toInt());
            break;
        }
        case 3:
        {
            vertexIndex.push_back(indexes[0].toInt());
            if (indexes[1] != "")
            {
                if (indexes[1].toInt() > maxTextureCoorIndex)
                {
                    errorStr = "Refference on unexistable texture coord";
                    return false;
                }
                textureCoordIndex.push_back(indexes[1].toInt());
            }
            if (indexes[2].toInt() > maxNormalVectorIndex)
            {
                errorStr = "Refference on unexistable normal vector";
                return false;
            }
            normalVectorIndex.push_back(indexes[2].toInt());
            break;
        }
            default:
                break;
    }
    return true;
}

QList<int> Face :: getVertex()
    {
        return vertexIndex;
    }
QList<int> Face :: getNormal()
    {
        return normalVectorIndex;
    }

