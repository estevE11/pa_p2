#include "Poblacio.h"

Poblacio::Poblacio() {
    this->contenidors = new node*[5];
}

Poblacio::Poblacio(ContenidorBrossa* g) : Poblacio() {
    this->afegirContenidor(g);
}

Poblacio::~Poblacio() {
    delete this->contenidors;
}

void Poblacio::eliminarContenidor(ContenidorBrossa* c) {
    
}

void Poblacio::afegirContenidor(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara) {

}

std::string Poblacio::hiEs(std::string codi) {

}

ContenidorBrossa Poblacio::*mesRendiment() {
    
}

int Poblacio::getQuants() {
    
}

void Poblacio::toString() {
    
}
