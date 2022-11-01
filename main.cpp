#include <iostream>

#include "Organic.h"
#include "Poblacio.h"
#include "Rebuig.h"
#include "Paper.h"

int main() {
    Poblacio p;

    Organic organic("XY-000",  "follandome a tu madre", 2022, 12);
    p.afegirContenidor(&organic);

    Organic organic2("XY-001",  "follandome a tu madre", 2022, 12);
    p.afegirContenidor(&organic2);

    Rebuig rebuig("XY-003",  "follandome a tu madre", 2022, 12);
    p.afegirContenidor(&rebuig);

    Paper paper("XY-003",  "follandome a tu paper", 2022, 30);

    p.afegirContenidor("XY-002", ContenidorBrossa::BLAU, "Ubicacaio rando", 2021, 6);
    p.afegirContenidor("XY-004", ContenidorBrossa::GROC, "Ubicacaio GROC", 2021, 10);
    p.afegirContenidor("XY-007", ContenidorBrossa::BLAU, "Ubicacaio blau", 2021, 10);


    organic.buidat(14);
    organic.buidat(200);
    rebuig.buidat(200);
    rebuig.buidat(200);

    std::cout << p.hiEs("XY-004") << std::endl;


    std::cout << std::endl << std::endl;
    p.toString();
    std::cout << std::endl << std::endl;

    ContenidorBrossa* mesRen = p.mesRendiment();
    std::cout << "\nMes rendiment" << std::endl;
    mesRen->toString();


    organic.buidat(100);
    organic2.buidat(200);
    organic2.buidat(200);
    paper.buidat(200);

    mesRen = p.mesRendiment();
    std::cout << "\nMes rendiment 2" << std::endl;
    mesRen->toString();

    std::cout << std::endl;
    for(int i = 0; i < 5; i++) {
        int n = p.getQuants(i);
        std::cout  << n << std::endl;
    }
    int conTotals = p.getQuants();
    std::cout << "Numero total de contenidors: " << conTotals << std::endl;


    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
    p.toString();

    return 0;
}
