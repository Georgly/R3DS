#include "model.h"
#include <QFile>
#include <QDebug>



    Model :: Model()
    {}

    QString Model :: importModel(QString fileName)
    {
        QString errStr = "";
        QString inputStr = parseFIle(fileName);
        vertexModel.clear();
        faceModel.clear();
        normalVectorModel.clear();
        textureCoordModel.clear();
        QTextStream* input = new QTextStream(&inputStr);
        errStr = importModel(*input);
        return errStr;
    }

    QString Model :: importModel(QTextStream &inputStream)
    {
        QString errStr = "Success";
        bool isErrorInInput = true;
        QString inputStr = inputStream.readAll();

        QStringList fileStrList = inputStr.split('\n');
        int length = fileStrList.count();

        for (int iterator = 0; iterator < length; iterator++)
        {
            if (fileStrList[iterator].trimmed() == "")
            {
                continue;
            }
            QStringList vertexStr = fileStrList[iterator].split(' ',  QString::SkipEmptyParts);
            if(vertexStr[0] == "v")
            {
                isErrorInInput = addNewVertex(vertexStr, errStr);
            }
            else if(vertexStr[0] == "vn")
            {
                isErrorInInput = addNewNormalVector(vertexStr, errStr);
            }
            else if(vertexStr[0] == "vt")
            {
                isErrorInInput = addNewTextureCoord(vertexStr, errStr);
            }
            else if(vertexStr[0] == "f")
            {
                isErrorInInput = addNewFace(vertexStr, errStr);
            }
            if ( !isErrorInInput )
            {
                errStr += " (line " + QString :: number(iterator + 1) + ")";
                qDebug() << errStr;
                return errStr;
            }
        }
        return errStr;
    }

    void Model :: exportModel()
    {
        QFile fileOut("testmodel.obj");
        if (!fileOut.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream writeStream(&fileOut);

        for (int iterator = 0 ; iterator < vertexModel.count() ; iterator++)
        {
            Vertex *vertex = vertexModel.data();
            writeStream << "v " + QString :: number(vertex[iterator].vector[0])
                    + " " + QString :: number(vertex[iterator].vector[1])
                    + " " + QString :: number(vertex[iterator].vector[2]) + "\n";
        }
        for (int iterator = 0 ; iterator < faceModel.count() ; iterator++)
        {
            Face *face = faceModel.data();
            writeStream << faceToString(face[iterator]);
        }
        fileOut.close();
    }

QString Model :: parseFIle(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        qDebug() << "File not opened.";
        QString emptyFileErrStr = "";
        return emptyFileErrStr;
    }
    QTextStream* readFile = new QTextStream(&file);
    QString text = readFile->readAll();

    file.close();
    return text;
}

    QString Model :: faceToString(Face face)
    {
        QString returnStr = "f";
        for (int iterator = 0; iterator < face.getVertex().count(); iterator++)
        {
            returnStr += " " + QString :: number(face.getVertex()[iterator]);
        }
        returnStr += "\n";
        return returnStr;
    }

    bool Model :: addNewFace(QStringList vertexStr, QString& errorStr)
    {
        Face *face = new Face();
        if (!isFaceCorrectFormat(vertexStr, errorStr))
        {
            return false;
        }

        bool isIndexOutOfRange = true;
        for (int iterator = 1; iterator < vertexStr.count(); iterator++)//TODO isIndexOutofRange work wrong
        {
            QStringList indexes = vertexStr[iterator].split('/');
            isIndexOutOfRange = face->addFace(indexes,
                                              vertexModel.count(),
                                              textureCoordModel.count(),
                                              normalVectorModel.count(),
                                              errorStr);//check this function
            if(!isIndexOutOfRange)
            {
                return false;
            }
        }
        faceModel.push_back(*face);

        return true;
    }

    bool Model :: isFaceCorrectFormat(QStringList vertexStr, QString& errStr)
    {
        if (vertexStr.count() < 4)
        {
            errStr = "Incorrect count of component in face";
            return false;
        }
        QRegExp re("^f( \\d+((/(\\d+)?)?/\\d+)?){3,}");
        if(!re.exactMatch(vertexStr.join(" ")))
        {
            errStr = "Input face string has wrong format";
            return false;
        }
        return true;
    }

    bool Model :: addNewTextureCoord(QStringList vertexStr, QString& errorStr)
    {
        QString errStr = "";
        TextureCoord *textureV = new TextureCoord(vertexStr[1].toFloat(),
                vertexStr[2].toFloat(),
                vertexStr.count() == 3 ? 0 : vertexStr[3].toFloat());
        textureCoordModel.push_back(*textureV);
        return true;
    }

    bool Model :: addNewNormalVector(QStringList vertexStr, QString& errorStr)
    {
        QString errStr = "";
        NormalVector *normalVector = new NormalVector(vertexStr[1].toFloat(),
                vertexStr[2].toFloat(),
                vertexStr[3].toFloat());
        normalVectorModel.push_back(*normalVector);
        return true;
    }

    bool Model :: addNewVertex(QStringList vertexStr, QString& errorStr)
    {
        if (!isVertexCorrectFormat(vertexStr, errorStr))
        {
            return false;
        }

        Vertex *vertex = new Vertex(vertexStr[1].toFloat(),
                vertexStr[2].toFloat(),
                vertexStr[3].toFloat()
                );
        setMinMaxVertex(*vertex);
        vertexModel.push_back(*vertex);

        return true;
    }

    bool Model :: isVertexCorrectFormat(QStringList vertexStr, QString& errStr)
    {
        //bool isErrorInStr = "";
        if(vertexStr.count() != 4 )
        {
            errStr = "Incorrect count of component in vertex";
            return false;
        }
        for (int iterator = 1 ; iterator < 4 ; iterator++ )
        {
            QRegExp re("^-?\\d+(\.\\d+)?$");
            if (!re.exactMatch(vertexStr[iterator]))
            {
                errStr = "Input vertex string contents letters or wrong symbols";
                return false;
            }
        }
        return true;
    }

void Model :: setMinMaxVertex(Vertex vertex)
{
    if (vertex.vector[0] < minVertex->vector[0])
        minVertex->vector[0] = vertex.vector[0];
    if (vertex.vector[1] < minVertex->vector[1])
        minVertex->vector[1] = vertex.vector[1];
    if (vertex.vector[2] < minVertex->vector[2])
        minVertex->vector[2] = vertex.vector[2];
    if (vertex.vector[0] > maxVertex->vector[0])
        maxVertex->vector[0] = vertex.vector[0];
    if (vertex.vector[1] > maxVertex->vector[1])
        maxVertex->vector[1] = vertex.vector[1];
    if (vertex.vector[2] > maxVertex->vector[2])
        maxVertex->vector[2] = vertex.vector[2];
}
