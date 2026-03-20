#include "BestioleFactory.h"
#include "Bestiole.h"
#include "DecCamouflage.h"
#include "DecCarapace.h"
#include "DecYeux.h"
#include "DecOreilles.h"
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
    IComportement* comportement = config ? config->tirerComportement() : nullptr;
    if (comportement)
        base->setComportement(comportement);

    IBestiole* b = base;
    const ParamsSimulation& p = config ? config->getParams() : ParamsSimulation();

// Capteurs obligatoires pour les grégaires
    bool dejaDesYeux = false;
    if (comportement && std::string(comportement->nom()) == "Gregaire") {
        b = new DecYeux(b, randDouble(M_PI / 6.,  M_PI / 3.), 100., 1.0);
        dejaDesYeux = true;
    }

// Tirage aléatoire des yeux seulement si pas déjà équipée
    if (!dejaDesYeux && config && tirerProba(config->probaYeux())) {
        double alpha  = randDouble(p.alphaMin,  p.alphaMax);
        double deltaY = randDouble(p.deltaYMin, p.deltaYMax);
        double gammaY = randDouble(p.gammaYMin, p.gammaYMax);
        b = new DecYeux(b, alpha, deltaY, gammaY);
    }

    if (config && tirerProba(config->probaOreilles())) {
    b = new DecOreilles(b, randDouble(p.deltaOMin, p.deltaOMax),
                           randDouble(p.gammaOMin, p.gammaOMax));
    }

    if (config && tirerProba(config->probaCarapace())) {
    b = new DecCarapace(b, randDouble(p.omegaMin, p.omegaMax),
                            randDouble(p.etaMin,   p.etaMax));
}

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