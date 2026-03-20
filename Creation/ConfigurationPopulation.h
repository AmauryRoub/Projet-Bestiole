#ifndef _CONFIGURATIONPOPULATION_H_
#define _CONFIGURATIONPOPULATION_H_

#include "IConfiguration.h"
#include <vector>
#include <string>

struct EntreeConfig {
    std::string nomComportement;
    double      pourcentage;
};

class ConfigurationPopulation : public IConfiguration
{
private:
    std::vector<EntreeConfig> repartition;
    ParamsSimulation          params;
    double _probaCamouflage, _probaCarapace;

public:
    ConfigurationPopulation();
    void setProbaCamouflage(double p) { _probaCamouflage = p; }
    void setProbaCarapace(double p)   { _probaCarapace   = p; }

    void ajouterComportement(const std::string& nom, double pct);
    IComportement* tirerComportement() const override;
    const ParamsSimulation& getParams()         const override { return params; }
    double probaCamouflage() const override { return _probaCamouflage; }
    double probaCarapace()   const override { return _probaCarapace;   }
};

#endif