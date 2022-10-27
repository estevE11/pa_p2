//
// Created by ziade on 27/10/2022.
//
#include "ContenidorBrossa.h"

class Vidre : public ContenidorBrossa{
private:
    long reciclat;
public:
    Vidre(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    Vidre(std::string codi, float tara);
    void buidat(float pes) override;
    std::string getReciclat();
    std::string getType() override;
    void toString();
    ~Vidre();

};
