#ifndef _ICONFIGURATION_H_
#define _ICONFIGURATION_H_

class IComportement;


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
};

#endif