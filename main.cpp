#include <iostream>

#include "Organic.h"
#include "Poblacio.h"
#include "Rebuig.h"

int main() {
    Organic organic("XY-000",  "follandome a tu madre", 2022, 12);
    organic.buidat(14);

    Organic organic2("XY-001",  "follandome a tu madre", 2022, 12);
    organic.buidat(200);

    Rebuig rebuig("XY-003",  "follandome a tu madre", 2022, 12);
    rebuig.buidat(200);


    Poblacio p;
    p.afegirContenidor(&organic);
    p.afegirContenidor(&organic2);
    p.afegirContenidor(&rebuig);

    p.afegirContenidor("XY-002", ContenidorBrossa::BLAU, "Ubicacaio rando", 2021, 6);

    std::cout << p.hiEs("XY-002") << std::endl;

    organic.buidat(100);
    organic2.buidat(200);
    organic2.buidat(200);

    ContenidorBrossa* mesRen = p.mesRendiment();
    mesRen->toString();

    int nMarro = p.getQuants(ContenidorBrossa::MARRO);
    std::cout << nMarro << std::endl;

    return 0;
}
