#include <ContenidorBrossa.h>

#include <string>

class Plastic :  public ContenidorBrossa {
private:
    float real; // Tones

public:
    Plastic(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    void toString();
    std::string getReciclat();
    std::string getType();
    void buidat(float pes);
    ~Plastic();
};