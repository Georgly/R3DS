#include "vertex.h"


Vertex :: Vertex ()
    {
        vector[0] = 0;
        vector[1] = 0;
        vector[2] = 0;
        vector[3] = 1;
    }

Vertex :: Vertex (float x, float y, float z)
    {
        vector[0] = x;
        vector[1] = y;
        vector[2] = z;
        vector[3] = 1;
    }

void Vertex :: vertexFromQString(QString input)
{
    QStringList coord = input.split(' ', QString::SkipEmptyParts);
    for (int iterator = 0; iterator < 3; iterator++)
    {
        vector[iterator] = coord[iterator].toFloat();
    }
}

QString Vertex :: vertexToQString()
{
    QString result = "";
    for (int iterator = 0; iterator < 4; iterator++)
    {
        result += QString::number(vector[iterator]) + " ";
    }
    //result += "\n";

    return result;
}
