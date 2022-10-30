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
    p.afegirContenidor(&organic2);

    return 0;
}
