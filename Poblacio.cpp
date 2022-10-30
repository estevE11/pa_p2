#include "Poblacio.h"
#include "Organic.h"
#include "Vidre.h"
#include "Paper.h"
#include "Rebuig.h"
#include "Plastic.h"

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
    n->seg = nullptr;
    curr->seg = n;
}

void Poblacio::afegirContenidor(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara) {
    ContenidorBrossa *c;
    switch (color) {
        case 0:
            c = new Organic(codi,ubicacio,anyColocacio,tara);
            break;
        case 1:
            c = new Vidre(codi,ubicacio,anyColocacio,tara);
            break;
        case 2:
            c = new Plastic(codi,ubicacio,anyColocacio,tara);
            break;
        case 3:
            c = new Paper(codi,ubicacio,anyColocacio,tara);
            break;
        case 4:
            c = new Rebuig(codi,ubicacio,anyColocacio,tara);
            break;
        //L'enunciat no indica que passa si el color que es reb no es correcte, per tant hem proposat una manera
        default:
            throw("El color no hi es!");
    }
    this->afegirContenidor(c);
}

void Poblacio::eliminarContenidor(ContenidorBrossa* c) {

}

std::string Poblacio::hiEs(std::string codi) {
    for(int i = 0; i < 5; i++) {
        node* curr = this->contenidors[i];
        if(curr == nullptr) continue;
        if(curr->con->getCodi() == codi) return curr->con->getTipusBrossa();
        while(curr->seg) {
            curr = curr->seg;
            if(curr->con->getCodi() == codi) return curr->con->getTipusBrossa();
        }
    }
    throw("El contenidor no hi es!");
}

ContenidorBrossa Poblacio::*mesRendiment() {

}

int Poblacio::getQuants(int color) {
    return 0;
}

int Poblacio::getQuants() {

}

void Poblacio::toString() {

}

ContenidorBrossa *Poblacio::mesRendiment() {
    return nullptr;
}
