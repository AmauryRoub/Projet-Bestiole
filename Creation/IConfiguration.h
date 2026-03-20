#ifndef _ICONFIGURATION_H_
#define _ICONFIGURATION_H_

class IComportement;
struct ParamsSimulation
{
    // Paramètres de la simulation, à compléter au besoin (taux de naissance, clonage, collision, etc..)
    // Accessoires
    double psiMin = 0.2, psiMax = 0.9;
};

/**
 * @class IConfiguration
 * @brief Interface abstraite pour la gestion des configurations de comportement.
 * 
 * Cette classe définit un contrat pour les implémentations concrètes qui fournissent
 * des comportements configurables. Elle utilise le pattern Strategy pour permettre
 * l'extraction dynamique de comportements.
 * 
 * @note Cette classe est abstraite et ne peut pas être instanciée directement.
 *       Les classes dérivées doivent implémenter la méthode tirerComportement().
 */
class IConfiguration
{
public:
    virtual ~IConfiguration() {}

    virtual IComportement *tirerComportement() const = 0;
    virtual const ParamsSimulation &getParams() const = 0;


    virtual double probaCamouflage() const = 0;
    virtual double probaCarapace()   const = 0;
};

#endif