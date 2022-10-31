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
    if(t == "plastic") id = ContenidorBrossa::GROC;
    else if(t == "organic") id = ContenidorBrossa::MARRO;
    else if(t == "rebuig") id = ContenidorBrossa::GRIS;
    else if(t == "vidre") id = ContenidorBrossa::VERD;
    else if(t == "paper") id = ContenidorBrossa::BLAU;

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
        case ContenidorBrossa::MARRO:
            c = new Organic(codi,ubicacio,anyColocacio,tara);
            break;
        case ContenidorBrossa::VERD:
            c = new Vidre(codi,ubicacio,anyColocacio,tara);
            break;
        case ContenidorBrossa::GROC:
            c = new Plastic(codi,ubicacio,anyColocacio,tara);
            break;
        case ContenidorBrossa::BLAU:
            c = new Paper(codi,ubicacio,anyColocacio,tara);
            break;
        case ContenidorBrossa::GRIS:
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

ContenidorBrossa* Poblacio::mesRendiment() {
    // Creem un contenidor base que tindrar el valor de reciclat a 0
    // Per poder-lo comparar amb el primer contenidor
    ContenidorBrossa* resultat = new Organic("base", 0);
    for(int i = 0; i < 5; i++) {
        node* curr = this->contenidors[i];
        if(curr == nullptr) continue;
        if(resultat->getCodi() == "base") resultat = curr->con;
        while(curr->seg) {
            curr = curr->seg;
            if(curr->con->getReciclat() > resultat->getReciclat()) resultat = curr->con;
        }
    }
    return resultat;
}

int Poblacio::getQuants(int color) {
    int res = 1;
    node* curr = this->contenidors[color];
    if(curr == nullptr) return 0;
    while(curr->seg) {
        res++;
        curr = curr->seg;
    }
    return res;
}

int Poblacio::getQuants() {
    return 0;
}

void Poblacio::toString() {

}
