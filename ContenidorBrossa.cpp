//
// Created by Cocon on 23/10/2022.
//

#include "ContenidorBrossa.h"

ContenidorBrossa::ContenidorBrossa(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara) {

}

std::string ContenidorBrossa::getTipusBrossa() {
    return std::string();
}

void ContenidorBrossa::retirarViaPublica() {

}

std::string ContenidorBrossa::getUbicacio() {
    return this->ubicacio;
}

// Si el parametre es null vol dir q es retira el contenidor (cridar funcio "retirarViaPublica")
void ContenidorBrossa::setUbicacio(std::string ubicacio) {

}

int ContenidorBrossa::getCodi() {
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
