//
// Created by ziade on 27/10/2022.
//
#include <iostream>ç
#include "Vidre.h"

Vidre::Vidre(std::string codi, std::string ubicacio, int anyColocacio, float tara) : ContenidorBrossa(codi, 0, ubicacio, anyColocacio, tara){
}

Vidre::Vidre(std::string codi, float tara) : ContenidorBrossa(codi, 0, "", 0, tara){
}

void Vidre::buidat(float pes) {
    this->reciclat += (pes - this->tara)*3l;
}

std::string Vidre::getReciclat() {
    return std::to_string(this->reciclat);
}

std::string Vidre::getType() {
    return "vidre";
}

void Vidre::toString() {
    ContenidorBrossa::toString();
    std::cout << "Reciclat: " << this->getReciclat() << std::endl;
}

Vidre::~Vidre() {

}
