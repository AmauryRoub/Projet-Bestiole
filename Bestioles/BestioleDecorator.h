#ifndef _BESTIOLEDECORATOR_H_
#define _BESTIOLEDECORATOR_H_

#include "IBestiole.h"

// Décorateur abstrait : délègue tout au composant par défaut
class BestioleDecorator : public IBestiole
{
protected:
    IBestiole *composant; // owned

public:
    explicit BestioleDecorator(IBestiole *c) : composant(c) {}
    virtual ~BestioleDecorator() { delete composant; }

    void action(Milieu &m) override { composant->action(m); }
    void draw(UImg &s) override { composant->draw(s); }
    void accept(IVisiteur &v) override { composant->accept(v); }
    IBestiole *clone() const override = 0; // chaque décorateur l'implémente

    int getId() const override { return composant->getId(); }
    int getX() const override { return composant->getX(); }
    int getY() const override { return composant->getY(); }
    double getOrientation() const override { return composant->getOrientation(); }
    double getVitesse() const override { return composant->getVitesse(); }
    double getCamouflage() const override { return composant->getCamouflage(); }
    int getAge() const override { return composant->getAge(); }
    int getAgeLimite() const override { return composant->getAgeLimite(); }
    bool estVivante() const override { return composant->estVivante(); }

    std::vector<IBestiole *> getBestiolesDetectees(
        const std::vector<IBestiole *> &toutes) const override
    {
        return composant->getBestiolesDetectees(toutes);
    }

    void setComportement(IComportement *c) override { composant->setComportement(c); }
    void setOrientation(double o) override { composant->setOrientation(o); }
    void tuer() override { composant->tuer(); }
    double getResistanceCollision() const override { return composant->getResistanceCollision(); }
};

#endif