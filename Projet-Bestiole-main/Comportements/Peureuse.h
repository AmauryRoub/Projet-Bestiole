#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_
#include "IComportement.h"

class Peureuse : public IComportement {
private:
    int seuilPeur; // nb de voisines à partir duquel elle fuit
public:
    Peureuse(int seuil = 3) : seuilPeur(seuil) {}
    void agir(IBestiole &moi, const std::vector<IBestiole*> &voisines, Milieu &milieu) override;
    IComportement* clone() const override { return new Peureuse(*this); }
    const char* nom() const override { return "Peureuse"; }
};
#endif