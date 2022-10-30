#include <iostream>

#include "Organic.h"
#include "Poblacio.h"

int main() {
    Organic organic("XY-000",  "follandome a tu madre", 2022, 12);
    organic.buidat(14);

    Organic organic2("XY-001",  "follandome a tu madre", 2022, 12);
    organic.buidat(200);


    Poblacio p;
    p.afegirContenidor(&organic);
    p.afegirContenidor(&organic2);

    p.afegirContenidor("XY-002", 1, "Ubicacaio rando", 2021, 6);

    std::cout << p.hiEs("XY-002") << std::endl;

    return 0;
}
