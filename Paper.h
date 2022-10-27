//
// Created by ziade on 27/10/2022.
//
#include "ContenidorBrossa.h"

class Paper : public ContenidorBrossa{
private:
    float reciclat;
public:
    Paper(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    Paper(std::string codi, float tara);
    void buidat(float pes) override;
    std::string getReciclat();
    std::string getType() override;
    void toString();
    ~Paper();

};
