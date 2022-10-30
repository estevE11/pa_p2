//
// Created by Cocon on 26/10/2022.
//
#include <iostream>
#include "Organic.h"

Organic::Organic(std::string codi, std::string ubicacio, int anyColocacio, float tara) : ContenidorBrossa(codi, 0, ubicacio, anyColocacio, tara){
}

Organic::Organic(std::string codi, float tara) : ContenidorBrossa(codi, 0, "", 0, tara){
}

void Organic::buidat(float pes) {
    this->reciclat += ((pes - this->tara)/1000)*.9f;
}

std::string Organic::getReciclat() {
    return std::to_string(this->reciclat);
}

std::string Organic::getType() {
    return "organic";
}

void Organic::toString() {
    ContenidorBrossa::toString();
    std::cout << "Reciclat: " << this->getReciclat() << std::endl;
}

Organic::~Organic() {
}

