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
    config.setProbaYeux(0.5);   
    config.setProbaOreilles(0.4);
    config.setProbaCamouflage(0.2);
    config.setProbaCarapace(0.25);

    BestioleFactory::getInstance()->setConfiguration(&config);

    Aquarium ecosysteme(1280, 720, 30);

    auto population = BestioleFactory::getInstance()->creerPopulation(20, 1280, 720);
    for (auto* b : population)
        ecosysteme.getMilieu().addMember(b);

    ecosysteme.run();
    return 0;
}