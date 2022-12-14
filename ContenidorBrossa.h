#pragma once

#include <string>

class ContenidorBrossa {
private:
    std::string codi;
    int color;
    std::string ubicacio;
    int anyColocacio;
    int anyRetirada;
protected:
    float tara;
public:
    static const int MARRO = 1,
            VERD = 3,
            GROC = 0,
            BLAU = 4,
            GRIS = 2;

    ContenidorBrossa(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara);
    ContenidorBrossa(std::string codi, int color, float tara);
    std::string getTipusBrossa();
    void retirarViaPublica();
    std::string getUbicacio();
    void setUbicacio(std::string ubicacio);
    std::string getCodi();
    std::string getEstat();

    static int getID(std::string type);

    virtual void toString();
    virtual void buidat(float pes) = 0;
    virtual std::string getType() = 0;
    virtual std::string getReciclat() = 0;
    ~ContenidorBrossa();

    bool operator==(ContenidorBrossa *p);
    bool operator>(ContenidorBrossa *p);
    bool operator<(ContenidorBrossa *p);
};
