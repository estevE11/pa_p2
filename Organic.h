#include "ContenidorBrossa.h"

class Organic : public ContenidorBrossa{
private:
    float reciclat;
public:
    Organic(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    Organic(std::string codi, float tara);
    void buidat(float pes) override;
    std::string getReciclat();
    std::string getType() override;
    void toString();
    ~Organic();
};
