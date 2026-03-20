#include "ConfigurationPopulation.h"
#include "Gregaire.h"
#include <cstdlib>

ConfigurationPopulation::ConfigurationPopulation()
    : _probaYeux(0.5), _probaCamouflage(0.2),  _probaCarapace(0.25)
{}

void ConfigurationPopulation::ajouterComportement(const std::string& nom, double pct)
{
    repartition.push_back({nom, pct});
}

IComportement* ConfigurationPopulation::tirerComportement() const
{
    if (repartition.empty()) return nullptr;

    double r     = static_cast<double>(rand()) / RAND_MAX;
    double cumul = 0.;

    for (auto& e : repartition) {
        cumul += e.pourcentage;
        if (r <= cumul) {
            if (e.nomComportement == "Gregaire") return new Gregaire();
        }
    }
    return nullptr;
}