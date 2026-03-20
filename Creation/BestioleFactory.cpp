#include "BestioleFactory.h"
#include "Bestiole.h"
#include "DecCamouflage.h"
#include <cstdlib>

BestioleFactory* BestioleFactory::instance = nullptr;

BestioleFactory* BestioleFactory::getInstance()
{
    if (!instance)
        instance = new BestioleFactory();
    return instance;
}

/// Génère un double aléatoire dans [min, max]
static double randDouble(double min, double max) {
    return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
}

/// Retourne true avec la probabilité p ∈ [0,1]
static bool tirerProba(double p) {
    return static_cast<double>(rand()) / RAND_MAX < p;
}

IBestiole* BestioleFactory::creer(int xLim, int yLim) const
{
    // Corps de base : position aléatoire dans le milieu
    Bestiole* base = new Bestiole();
    base->initCoords(xLim, yLim);

    // Comportement tiré selon les pourcentages de la configuration
    if (config)
        base->setComportement(config->tirerComportement());

    // Cast vers IBestiole* — point d'extension pour les Decorateurs (capteurs, accessoires)
    IBestiole* b = base;
    const ParamsSimulation& p = config ? config->getParams() : ParamsSimulation();

    // Accessoires

    if (config && tirerProba(config->probaCamouflage())) {
        b = new DecCamouflage(b, randDouble(p.psiMin, p.psiMax));
    }

    return b;
}

std::vector<IBestiole*> BestioleFactory::creerPopulation(int nb, int xLim, int yLim) const
{
    std::vector<IBestiole*> pop;
    pop.reserve(nb);
    for (int i = 0; i < nb; ++i)
        pop.push_back(creer(xLim, yLim));
    return pop;
}