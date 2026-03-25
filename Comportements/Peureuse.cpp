#include "Peureuse.h"
#include "IBestiole.h"
#include <cmath>

void Peureuse::agir(IBestiole &moi,
                    const std::vector<IBestiole*> &voisines,
                    Milieu& /*milieu*/)
{
    if ((int)voisines.size() >= seuilPeur)
        moi.setOrientation(moi.getOrientation() + M_PI); // fuit dans la direction opposée
}