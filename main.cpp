#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "BestioleFactory.h"
#include "ConfigurationPopulation.h"

#include <iostream>
using namespace std;

int main()
{
    ConfigurationPopulation config;
    config.ajouterComportement("Gregaire", 0.30);

    BestioleFactory::getInstance()->setConfiguration(&config);

    Aquarium ecosysteme(640, 480, 30);

    auto population = BestioleFactory::getInstance()->creerPopulation(20, 640, 480);
    for (auto* b : population)
        ecosysteme.getMilieu().addMember(b);

    ecosysteme.run();
    return 0;
}