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

    node* target = nullptr;

    for(int i = 0; i < 5; i++) {
        node* curr = this->contenidors[i];
        if(curr == nullptr) continue;
        std::cout << curr->con->getCodi() << " = " << p->getCodi() << " = " << (curr->con == p) << std::endl;
        if(curr->con->getCodi() == p->getCodi()) throw("El contenidor ja esxisteix!");
        while(curr->seg) {
            curr = curr->seg;
            if(curr->con->getCodi() == p->getCodi()) throw("El contenidor ja esxisteix!");
        }
        if(i == id) target = curr;
    }

    if(target == nullptr) {
        node* n = new node;
        n->con = p;
        n->seg = nullptr;
        this->contenidors[id] = n;
        return;
    }

    node* n = new node;
    n->con = p;
    n->seg = nullptr;
    target->seg = n;
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

// TODO: Metodo eliminar contenidor
void Poblacio::eliminarContenidor(ContenidorBrossa* c) {
    std::string t = c->getType();
    int id = 0;
    if(t == "plastic") id = ContenidorBrossa::GROC;
    else if(t == "organic") id = ContenidorBrossa::MARRO;
    else if(t == "rebuig") id = ContenidorBrossa::GRIS;
    else if(t == "vidre") id = ContenidorBrossa::VERD;
    else if(t == "paper") id = ContenidorBrossa::BLAU;

    node* aux = this->contenidors[id];



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
    int res = 0;
    for(int i = 0; i < 5; i++) {
        res += this->getQuants(i);
    }
    return res;
}

void Poblacio::toString() {
    for(int i = 0; i < 5; i ++) {
        node* curr = this->contenidors[i];
        if(curr == nullptr) continue;

        std::cout << ". : Contenidors ";

        switch (i) {
            case ContenidorBrossa::MARRO:
                std::cout << "marrons : ." << std::endl;
                break;
            case ContenidorBrossa::VERD:
                std::cout << "verds : ." << std::endl;
                break;
            case ContenidorBrossa::GROC:
                std::cout << "grocs : ." << std::endl;
                break;
            case ContenidorBrossa::BLAU:
                std::cout << "blaus : ." << std::endl;
                break;
            case ContenidorBrossa::GRIS:
                std::cout << "grisos : ." << std::endl;
                break;
        }


        curr->con->toString();
        std::cout << std::endl;
        while(curr->seg) {
            curr->seg->con->toString();
            std::cout << std::endl;
            curr = curr->seg;
        }
    }
}

bool Poblacio::operator==(Poblacio d) {
    return !(this > &d) && !(this < &d);
}

bool Poblacio::operator<(Poblacio d) {
    return this->getQuants() < d.getQuants();
}

bool Poblacio::operator>(Poblacio d) {
    return this->getQuants() > d.getQuants();
}