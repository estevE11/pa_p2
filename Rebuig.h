#include <ContenidorBrossa.h>

#include <string>

class Rebuig :  public ContenidorBrossa {
private:
    float real; // Tones

public:
    Rebuig(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    void toString();
    std::string getReciclat();
    std::string getType();
    void buidat(float pes);
    ~Rebuig();
};