#include "object3d_rotate.h"


void _object3D_Rotate::vueltas(int n_caras){

    //Angulo del que se parte
    double ang_inicial = (M_PI * 2) / n_caras;

    //Angulo que le sumaremos en cada itineracion
    double ang_sumatoria = (M_PI * 2) / n_caras;

    //Variable que contendra el total de puntos
    int total_puntos = Vertices.size() * n_caras;

    //Variable que indicara cuando se ha recorrido ya. todos los vertices de un perfil
    int cont_perfil = 0;
    int tam_perfil = Vertices.size();

    for(int i = 0; i < total_puntos; i++){
        cont_perfil++;
        Vertices.push_back(_vertex3f(Vertices[i % tam_perfil].x * cos(ang_inicial), Vertices[i % tam_perfil].y, Vertices[i % tam_perfil].x * sin(ang_inicial)));
        if(cont_perfil == tam_perfil){
            cont_perfil = 0;
            ang_inicial += ang_sumatoria;
        }
     }

    rellenar_triangulos(n_caras, tam_perfil);
}

void _object3D_Rotate::rellenar_triangulos(int n_caras, int tam){

    //j -> Iterador de columnas
    //mod -> Total de puntos
    //tope -> Tamaño de los triangulos
    //cara -> Contador de caras

    int mod = (n_caras + 1) * tam;
    int tope = mod * 2;
    int cara = 0;
    int pos_t = 0;

    Triangles.clear();
    Triangles.resize(tope);

    for(int i=0;i<n_caras;++i){
    for(int j=0;j<tam-1;++j){
    //crea la estructura de alambres
    int indice = (i*tam)+j;
    //creamos la tapa superior y sus caras (inferior)
    //ejemplo: i = 0, j = 1, tam = 4
    //1º = (1 * 4) + 0 = 4
    //2º = (1 * 4) + 0 + 4 = 8
    //3º = (1 * 4) + 0 + 1 = 5
    Triangles[pos_t]=_vertex3ui(indice,indice+tam,indice+1);
    ++pos_t;
    Triangles[pos_t]=_vertex3ui(indice+1,indice+tam,indice+tam+1);
    ++pos_t;
    }
    }

}
