#include "ContenidorBrossa.h"

#include <ctime>
#include <iostream>
#include <string>

ContenidorBrossa::ContenidorBrossa(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara) {
    this->codi = codi;
    this->color = color;
    this->ubicacio = ubicacio;
    this->anyColocacio = anyColocacio;
    this->tara = tara;
}

ContenidorBrossa::ContenidorBrossa(std::string codi, int color, float tara) : ContenidorBrossa(codi, color, "", 0, tara) {

}

ContenidorBrossa::~ContenidorBrossa() {

}

std::string ContenidorBrossa::getTipusBrossa() {
    if(this->color == ContenidorBrossa::MARRO) return "Organic";
    if(this->color == ContenidorBrossa::VERD) return "Vidre";
    if(this->color == ContenidorBrossa::GROC) return "Plastic";
    if(this->color == ContenidorBrossa::GRIS) return "Rebuig";
    return "Paper";
}

void ContenidorBrossa::retirarViaPublica() {
    if(&this->anyRetirada == nullptr || this->anyRetirada == 0 || this->ubicacio.empty())
        throw "ERROR: Intent de retirar un contenidor que no està en la via publica!";

    time_t now;
    struct tm *now_tm;
    now = time(NULL);
    now_tm = localtime(&now);
    int year = now_tm->tm_year + 1900;

    this->anyRetirada = year;
    this->ubicacio = "";
    this->anyColocacio = 0;
}

std::string ContenidorBrossa::getUbicacio() {
    return this->ubicacio;
}

void ContenidorBrossa::setUbicacio(std::string ubicacio) {
    if(ubicacio.empty()) {
        this->retirarViaPublica();
        return;
    }

    this->ubicacio = ubicacio;
}

std::string ContenidorBrossa::getCodi() {
    return this->codi;
}

std::string ContenidorBrossa::getEstat() {
    time_t now;
    struct tm *now_tm;
    now = time(NULL);
    now_tm = localtime(&now);
    int year = now_tm->tm_year + 1900;
    int year_delta = year - this->anyColocacio;

    if(year_delta > 5)
        return "VELL";
    if(year_delta >= 3)
        return "SEMINOU";
    return "NOU";
}

void ContenidorBrossa::toString() {
    std::cout << "Codi: " << this->codi << std::endl;
    std::cout << "Color: " << this->getTipusBrossa() << std::endl;
    std::cout << "Ubicacio: ";
    if(this->ubicacio != "")
        std::cout << this->ubicacio;
    else
        std::cout << "Retirat";
    std::cout << std::endl;
    std::cout << "Tara: " << this->tara << std::endl;
}

int ContenidorBrossa::getID(std::string t) {
    if(t == "plastic") return ContenidorBrossa::GROC;
    if(t == "organic") return ContenidorBrossa::MARRO;
    if(t == "rebuig") return ContenidorBrossa::GRIS;
    if(t == "vidre") return ContenidorBrossa::VERD;
    if(t == "paper") return ContenidorBrossa::BLAU;
    return -1;
}

bool ContenidorBrossa::operator==(ContenidorBrossa *p) {
    return !(*this>p) && !(*this<p);
}

bool ContenidorBrossa::operator>(ContenidorBrossa *p) {
    return this->codi.compare(p->getCodi()) > 0;
}

bool ContenidorBrossa::operator<(ContenidorBrossa *p) {
    return this->codi.compare(p->getCodi()) < 0;
}

