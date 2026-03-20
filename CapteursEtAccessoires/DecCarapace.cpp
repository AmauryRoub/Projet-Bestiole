#include "DecCarapace.h"
#include "IVisiteur.h"

DecCarapace::DecCarapace(IBestiole* c, double omega, double eta)
    : BestioleDecorator(c), omega(omega), eta(eta) {}

IBestiole* DecCarapace::clone() const
{
    return new DecCarapace(composant->clone(), omega, eta);
}

void DecCarapace::accept(IVisiteur& v)
{
    v.visiter(*this);
    composant->accept(v);
}

void DecCarapace::draw(UImg& support)
{
    composant->draw(support);
    // Anneau gris symbolisant la carapace
    T coul[3] = {150, 150, 150};
    support.draw_circle(getX(), getY(), 12, coul, 0.0f, 1U);
}
