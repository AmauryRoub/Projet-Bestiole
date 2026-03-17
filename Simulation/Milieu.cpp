#include "Milieu.h"
#include "BestioleFactory.h"
#include <cstdlib>
#include <ctime>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3),
                                          width(_width), height(_height)
{
    cout << "const Milieu" << endl;
    std::srand(time(NULL));
}

Milieu::~Milieu(void)
{
    cout << "dest Milieu" << endl;
}   

void Milieu::addMember(IBestiole *b)
{
    ptrBestioles.push_back(b);
    notifier({TypeEvenement::NAISSANCE, b->getId(), pas, "ajout"});
}

void Milieu::notifier(const Evenement &e)
{
    for (auto *o : observateurs)
        o->notifier(e);
}

void Milieu::gererNaissancesSpontanees()
{
    const double TAUX_NAISSANCE = 0.005;
    if (static_cast<double>(std::rand()) / RAND_MAX < TAUX_NAISSANCE)
    {
        IBestiole *b = BestioleFactory::getInstance()->creer(width, height);
        addMember(b);
    }
}


void Milieu::step()
{
    // Efface le fond
    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);

    // Snapshot journal avant action
    for (auto *b : ptrBestioles)
    {
        if (b->estVivante())
        {
            SnapshotBestiole s;
            s.id = b->getId();
            s.x = b->getX();
            s.y = b->getY();
            s.vitesse = b->getVitesse();
            s.orientation = b->getOrientation();
            journal.ajouterSnapshot(s);
        }
    }

    // Action + dessin de chaque bestiole
    for (auto *b : ptrBestioles)
    {
        if (b->estVivante())
        {
            b->action(*this);
            b->draw(*this);
        }
    }

    gererNaissancesSpontanees();


    notifier({TypeEvenement::PAS_SIMULATION, -1, pas, ""});
    ++pas;
}

int Milieu::nbVoisins(const IBestiole& b)
{
    return b.getBestiolesDetectees(ptrBestioles).size();
}

void Milieu::fairenaitre()
{
    IBestiole *b = BestioleFactory::getInstance()->creer(width, height);
    addMember(b);
}