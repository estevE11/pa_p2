#include <ContenidorBrossa.h>

#include <string>

class Plastic :  public ContenidorBrossa {
private:
    long n_envasos; // Numero de envasos reciclats

public:
    Plastic(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    void toString();
    std::string getReciclat();
    std::string getType();
    void buidat(float pes);
    ~Plastic();
};