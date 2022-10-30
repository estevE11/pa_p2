#include "ContenidorBrossa.h"

#include <string>

class Poblacio {
private:
    struct node {
        ContenidorBrossa* con;
        node* seg;
    };

    // Array per emmagatzemar els nodes capçelera de les llistes enllaçades
    node** contenidors;

public:
    Poblacio();
    Poblacio(ContenidorBrossa* g);
    ~Poblacio();
    void afegirContenidor(ContenidorBrossa* g);
    void afegirContenidor(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara);
    // Se li passa un codi i ha de retornar el color del contenidor, sino existeix llança una exepcio
    std::string hiEs(std::string codi);
    void eliminarContenidor(ContenidorBrossa* c);
    ContenidorBrossa *mesRendiment();
    int getQuants(int color);
    int getQuants();
    void toString();
};
