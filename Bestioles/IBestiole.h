#ifndef _IBESTIOLE_H_
#define _IBESTIOLE_H_

#include "UImg.h"
#include <vector>

class Milieu;
class IVisiteur;
class IComportement;

class IBestiole
{
public:
    virtual ~IBestiole() {}

    virtual void action(Milieu &monMilieu) = 0;
    virtual void draw(UImg &support) = 0;
    virtual IBestiole *clone() const = 0;

    
    virtual int getId() const = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual double getOrientation() const = 0;

    virtual std::vector<IBestiole *> getBestiolesDetectees(
        const std::vector<IBestiole *> &toutes) const = 0;

    virtual void setComportement(IComportement *c) = 0;
    virtual void setOrientation(double o) = 0;
};

#endif