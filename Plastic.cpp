//
// Created by ziade on 27/10/2022.
//
#include <iostream>
#include "Plastic.h"

Plastic::Plastic(std::string codi, std::string ubicacio, int anyColocacio, float tara) : ContenidorBrossa(codi, 0, ubicacio, anyColocacio, tara){
}

Plastic::Plastic(std::string codi, float tara) : ContenidorBrossa(codi, 0, "", 0, tara){
}

void Plastic::buidat(float pes) {
    this->reciclat += (pes - this->tara)*.8f;
}

std::string Plastic::getReciclat() {
    return std::to_string(this->reciclat);
}

std::string Plastic::getType() {
    return "plastic";
}

void Plastic::toString() {
    ContenidorBrossa::toString();
    std::cout << "Reciclat: " << this->getReciclat() << std::endl;
}

Plastic::~Plastic() {

}
