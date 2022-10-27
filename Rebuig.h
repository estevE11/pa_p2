//
// Created by ziade on 27/10/2022.
//
#include "ContenidorBrossa.h"

class Rebuig : public ContenidorBrossa{
private:
    float reciclat;
public:
    Rebuig(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    Rebuig(std::string codi, float tara);
    void buidat(float pes) override;
    std::string getReciclat();
    std::string getType() override;
    void toString();
    ~Rebuig();

};