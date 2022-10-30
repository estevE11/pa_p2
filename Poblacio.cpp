#include "Poblacio.h"

#include <iostream>

Poblacio::Poblacio() {
    this->contenidors = new node*[5];
    for(int i = 0; i < 5; i++) {
        this->contenidors[i] = nullptr;
    }
}

Poblacio::Poblacio(ContenidorBrossa* g) : Poblacio() {
    this->afegirContenidor(g);
}

Poblacio::~Poblacio() {
    delete this->contenidors;
}

void Poblacio::eliminarContenidor(ContenidorBrossa* c) {

}

void Poblacio::afegirContenidor(ContenidorBrossa* p) {
    std::string t = p->getType();
    int id = 0;
    if(t == "plastic") id = 0;
    else if(t == "organic") id = 1;
    else if(t == "rebuig") id = 2;
    else if(t == "vidre") id = 3;
    else if(t == "paper") id = 4;

    node* curr = this->contenidors[id];
    if(curr == nullptr) {
        node* n = new node;
        n->con = p;
        n->seg = nullptr;
        this->contenidors[id] = n;
        return;
    }
    if(curr->con == p) throw("El contenidor ja esxisteix!");
    while(curr->seg) {
        curr = curr->seg;
        if(curr->con == p) throw("El contenidor ja esxisteix!");
    }

    node* n = new node;
    n->con = p;
    curr->seg = n;
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

ContenidorBrossa *Poblacio::mesRendiment() {
    return nullptr;
}

int Poblacio::getQuants(int color) {
    return 0;
}
