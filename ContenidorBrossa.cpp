//
// Created by Cocon on 23/10/2022.
//

#include "ContenidorBrossa.h"

#include <time.h>>

ContenidorBrossa::ContenidorBrossa(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara) {

}

std::string ContenidorBrossa::getTipusBrossa() {
    if(this->color == this->MARRO) return "Organic";
    if(this->color == this->VERD) return "Vidre";
    if(this->color == this->GROC) return "Plastic";
    if(this->color == this->GRIS) return "Resta";
    return "Paper";
}

void ContenidorBrossa::retirarViaPublica() {
    if(this->anyRetirada == NULL || this->anyRetirada == 0 || this->ubicacio == "")
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

// Si el parametre es null vol dir q es retira el contenidor (cridar funcio "retirarViaPublica")
void ContenidorBrossa::setUbicacio(std::string ubicacio) {

}

std::string ContenidorBrossa::getCodi() {
    return this->codi;
}

/*
 * Si té més de 5 anys retorna "vell"
 * Si té entre 3 i 5 anys retorna "seminou".
 * Si té menys de 3 any retorna "nou".
 *
 * Els anys que té un contenidor ve donat per la diferencia entre l’any de la data a dia
    d’avui i l’any de col·locació. Si el contenidor no està a la via pública el mètode ha
    de retornar la cadena “retirat”.
 * */
std::string ContenidorBrossa::getEstat() {
    return std::string();
}

/*
 * Imprimir:
 *  Codi: XX-YYYY
 *  Color: en format string, invoca al mètode adient
 *  Ubicació: nom de carrer si està en servei, “retirat” si està al
 *  magatzem de l’Ajuntament
 *  Tara: valor real amb dos decimals
 * */
void ContenidorBrossa::toString() {

}

void ContenidorBrossa::buidat(float pes) {

}

std::string ContenidorBrossa::getType() {
    return std::string();
}

std::string ContenidorBrossa::getReciclat() {
    return std::string();
}

ContenidorBrossa::~ContenidorBrossa() {

}
