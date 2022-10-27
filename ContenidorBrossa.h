//
// Created by Cocon on 23/10/2022.
//

#include <string>

class ContenidorBrossa {
private:
    static const int MARRO = 0,
                    VERD = 1,
                    GROC = 2,
                    BLAU = 3,
                    GRIS = 4;
    std::string codi;
    int color;
    std::string ubicacio;
    int anyColocacio;
    int anyRetirada;
protected:
    float tara;
public:
    ContenidorBrossa();
    ContenidorBrossa(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara);
    ContenidorBrossa(std::string codi, int color, float tara);
    std::string getTipusBrossa();
    void retirarViaPublica();
    std::string getUbicacio();
    void setUbicacio(std::string ubicacio);
    std::string getCodi();
    std::string getEstat();
    void toString();
    virtual void buidat(float pes) = 0; // Abstracte
    virtual std::string getType() = 0; // Abstracte
    virtual std::string getReciclat() = 0;
    ~ContenidorBrossa();

    bool operator==(ContenidorBrossa *p);
};
