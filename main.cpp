#include <iostream>

#include "Organic.h"

int main() {
    Organic organic("XY-000",  "follandome a tu madre", 2022, 12);
    organic.buidat(14);

    Organic test("XY-001", 12);

    organic.toString();
    std::cout << "----------" << std::endl;
    test.toString();

    return 0;
}
