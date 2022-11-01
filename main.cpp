#include <iostream>

#include "Organic.h"
#include "Poblacio.h"
#include "Rebuig.h"
#include "Paper.h"

void test(std::string name, int ex, int val);
void test(std::string name, std::string ex, std::string val);

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

    ContenidorBrossa* mesRen = p.mesRendiment();
    test("Rendiment 1", "XY-003", mesRen->getCodi());

    organic.buidat(100);
    organic2.buidat(200);
    organic2.buidat(200);
    paper.buidat(200);

    mesRen = p.mesRendiment();
    test("Rendiment 2", "XY-001", mesRen->getCodi());

    int conTotals = p.getQuants();
    test("Contenidors totals", 6, conTotals);

    p.eliminarContenidor(&organic);

    conTotals = p.getQuants();
    test("Contenidors totals", 5, conTotals);

    return 0;
}

void test(std::string name, int ex, int val) {
    if(val != ex) {
        std::cout << "Fallo test: " << name << std::endl;
        std::cout << "Deberia ser: " << ex << " per es " << val << std::endl;
        throw("");
    }
    std::cout << "Test pasado: " << name  << "(" << val << ")" << std::endl;
}

void test(std::string name, std::string ex, std::string val) {
    if(val != ex) {
        std::cout << "Fallo test: " << name << std::endl;
        std::cout << "Deberia ser: " << ex << " per es " << val << std::endl;
        throw("");
    }
    std::cout << "Test pasado: " << name  << " (" << val << ")" << std::endl;
}
