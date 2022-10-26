#include <ContenidorBrossa.h>

#include <string>

class Organic :  public ContenidorBrossa {
private:
    float real; // Tones

public:
    Organic(std::string codi, std::string ubicacio, int anyColocacio, float tara) : ContenidorBrossa(codi, 0, ubicacio, anyColocacio, tara) {};
    void toString();
    std::string getReciclat();
    std::string getType();
    void buidat(float pes);
    ~Organic();
};