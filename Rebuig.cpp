//
// Created by ziade on 27/10/2022.
//
#include <iostream>
#include "Rebuig.h"

Rebuig::Rebuig(std::string codi, std::string ubicacio, int anyColocacio, float tara) : ContenidorBrossa(codi, ContenidorBrossa::GRIS, ubicacio, anyColocacio, tara){
    this->reciclat = 0;
}

Rebuig::Rebuig(std::string codi, float tara) : Rebuig(codi, "", 0, tara){
}

void Rebuig::buidat(float pes) {
    this->reciclat += ((pes - this->tara)/1000)*.75f;
}

std::string Rebuig::getReciclat() {
    return std::to_string(this->reciclat);
}

std::string Rebuig::getType() {
    return "rebuig";
}

void Rebuig::toString() {
    ContenidorBrossa::toString();
    std::cout << "Reciclat: " << this->getReciclat() << std::endl;
}

Rebuig::~Rebuig() {

}
