#include "ply.h"

_ply::_ply()
{
    string nombre_archivo = "/home/juanjo/Descargas/ply_models/cow.ply";
    _file_ply archivo;

    if(archivo.open(nombre_archivo)){

        //Leemos el archivo
        archivo.read(coordenadas, posiciones);
        //Una vez leido cerramos el archivo
        archivo.close();

        //Limpiamos el vector
        Vertices.clear();
        //Lo redimensionamos al tamaño coordenadas / 3 porque un vector tiene 3 coordenadas
        Vertices.resize(coordenadas.size() / 3);
        //Rellenamos el vector
        for(unsigned int i = 0; i < Vertices.size(); i++){
            Vertices[i].x = coordenadas[i * 3];
            Vertices[i].y = coordenadas[i * 3 + 1];
            Vertices[i].z = coordenadas[i * 3 + 2];
        }

        //Hacemos lo mismo con los triangulos
        Triangles.clear();
        Triangles.resize(posiciones.size() / 3);
        for(unsigned int i = 0; i < Triangles.size(); i++){
            Triangles[i]._0 = posiciones[i * 3];
            Triangles[i]._1 = posiciones[i * 3 + 1];
            Triangles[i]._2 = posiciones[i * 3 + 2];
        }
    }else{
        cout << "Error archivo no leido";
    }
}
