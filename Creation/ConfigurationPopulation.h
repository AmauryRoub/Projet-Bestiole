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

public:
    void ajouterComportement(const std::string& nom, double pct);
    IComportement* tirerComportement() const override;
};

#endif