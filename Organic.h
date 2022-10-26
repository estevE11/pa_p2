#include "ContenidorBrossa.h"

class Organic : ContenidorBrossa{
private:
    float real;
public:
    Organic(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    void buidat(float pes) override;
};
