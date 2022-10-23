#include <ContenidorBrossa.h>

#include <string>

class Paper :  public ContenidorBrossa {
private:
    float real; // kg

public:
    Paper(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    void toString();
    std::string getReciclat();
    std::string getType();
    void buidat(float pes);
    ~Paper();
};