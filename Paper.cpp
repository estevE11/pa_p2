//
// Created by ziade on 27/10/2022.
//
#include <iostream>
#include "Paper.h"

Paper::Paper(std::string codi, std::string ubicacio, int anyColocacio, float tara) : ContenidorBrossa(codi, ContenidorBrossa::BLAU, ubicacio, anyColocacio, tara){
    this->reciclat = 0;
}

Paper::Paper(std::string codi, float tara) : Paper(codi, "", 0, tara) {
}

void Paper::buidat(float pes) {
    this->reciclat += (pes - this->tara)*.95f;
}

std::string Paper::getReciclat() {
    return std::to_string(this->reciclat);
}

std::string Paper::getType() {
    return "paper";
}

void Paper::toString() {
    ContenidorBrossa::toString();
    std::cout << "Reciclat: " << this->getReciclat() << std::endl;
}

Paper::~Paper() {

}
