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
    std::string hiEs(std::string codi);
    void eliminarContenidor(ContenidorBrossa* c);
    ContenidorBrossa* mesRendiment();
    int getQuants(int color);
    int getQuants();
    void toString();

    bool operator==(Poblacio d);
    bool operator<(Poblacio d);
    bool operator>(Poblacio d);
};
