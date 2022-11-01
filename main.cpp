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

    Paper paper("XY-010",  "follandome a tu paper", 2022, 30);
    p.afegirContenidor(&paper);

    int conTotals = p.getQuants();
    test("Contenidors totals", 4, conTotals);

    p.afegirContenidor("XY-002", ContenidorBrossa::BLAU, "Ubicacaio rando", 2021, 6);
    p.afegirContenidor("XY-004", ContenidorBrossa::GROC, "Ubicacaio GROC", 2021, 10);
    p.afegirContenidor("XY-007", ContenidorBrossa::BLAU, "Ubicacaio blau", 2021, 10);

    conTotals = p.getQuants();
    test("Contenidors totals", 7, conTotals);

    organic.buidat(14);
    organic.buidat(200);
    rebuig.buidat(200);
    rebuig.buidat(200);

    test("Hi es", "Plastic", p.hiEs("XY-004"));

    ContenidorBrossa* mesRen = p.mesRendiment();
    test("Rendiment 1", "XY-003", mesRen->getCodi());

    organic.buidat(100);
    organic2.buidat(200);
    organic2.buidat(200);
    paper.buidat(200);

    mesRen = p.mesRendiment();
    test("Rendiment 2", "XY-010", mesRen->getCodi());

    p.eliminarContenidor(&organic2);
    conTotals = p.getQuants();
    test("Contenidors eliminats", 6, conTotals);

    p.eliminarContenidor(&paper);
    conTotals = p.getQuants();
    test("Contenidors eliminats", 5, conTotals);

    mesRen = p.mesRendiment();
    test("Rendiment 3", "XY-010", mesRen->getCodi());

    return 0;
}

void test(std::string name, int ex, int val) {
    if(val != ex) {
        std::cout << "Fallo test: " << name << std::endl;
        std::cout << "Deberia ser: " << ex << " per es " << val << std::endl;
        //throw("");
    }
    std::cout << "Test pasado: " << name  << " (" << val << ")" << std::endl;
}

void test(std::string name, std::string ex, std::string val) {
    if(val != ex) {
        std::cout << "Fallo test: " << name << std::endl;
        std::cout << "Deberia ser: " << ex << " per es " << val << std::endl;
        //throw("");
    }
    std::cout << "Test pasado: " << name  << " (" << val << ")" << std::endl;
}
