#include <iostream>

#include "Organic.h"
#include "Poblacio.h"
#include "Rebuig.h"
#include "Paper.h"

void test(std::string name, int ex, int val);
void test(std::string name, std::string ex, std::string val);

int main() {
    Poblacio p;

    Organic organic("XY-000",  "carrer 1", 2022, 12);
    p.afegirContenidor(&organic);

    Organic organic2("XY-001",  "carrer 2", 2022, 12);
    p.afegirContenidor(&organic2);

    Organic organic3("XY-015",  "carrer 3", 2022, 12);
    p.afegirContenidor(&organic3);

    Rebuig rebuig("XY-003",  "carrer 3", 2022, 12);
    p.afegirContenidor(&rebuig);

    Paper paper("XY-010",  "carrer 2", 2022, 30);
    p.afegirContenidor(&paper);

    int conTotals = p.getQuants();
    test("Contenidors totals", 5, conTotals);

    p.afegirContenidor("XY-002", ContenidorBrossa::BLAU, "carrer 1", 2021, 6);
    p.afegirContenidor("XY-004", ContenidorBrossa::GROC, "carrer 3", 2021, 10);
    p.afegirContenidor("XY-007", ContenidorBrossa::VERD, "carrer 2", 2021, 10);

    conTotals = p.getQuants();
    test("Contenidors totals", 8, conTotals);

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
    test("Contenidor eliminats", 7, conTotals);

    p.eliminarContenidor(&paper);
    conTotals = p.getQuants();
    test("Contenidor eliminats", 6, conTotals);

    mesRen = p.mesRendiment();
    test("Rendiment 3", "XY-003", mesRen->getCodi());

    p.eliminarContenidor(&organic);
    conTotals = p.getQuants();
    test("Contenidor eliminats", 5, conTotals);
    
    return 0;
}

void test(std::string name, int ex, int val) {
    if(val != ex) {
        std::cout << "> Fallo test: " << name;
        std::cout << ". Deberia ser: " << ex << " per es " << val << std::endl;
        //throw("");
    }
    std::cout << "Test pasado: " << name  << " (" << val << ")" << std::endl;
}

void test(std::string name, std::string ex, std::string val) {
    if(val != ex) {
        std::cout << "> Fallo test: " << name << std::endl;
        std::cout << "Deberia ser: " << ex << " per es " << val << std::endl;
        //throw("");
    }
    std::cout << "Test pasado: " << name  << " (" << val << ")" << std::endl;
}
