#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "ConfigurationPopulation.h"

#include <iostream>
using namespace std;

int main()
{
    ConfigurationPopulation config;
    config.ajouterComportement("Gregaire", 0.30);

    Aquarium ecosysteme(640, 480, 30);

    for (int i = 1; i <= 20; ++i) {
        Bestiole b;
        b.setComportement(config.tirerComportement());
        ecosysteme.getMilieu().addMember(b);
    }

    ecosysteme.run();
    return 0;
}