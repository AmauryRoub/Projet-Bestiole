#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include "IBestiole.h"
#include "IComportement.h"


using namespace std;


class Milieu;


class Bestiole : public IBestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   IComportement    * comportement;
   
   bool vivante;
   T               * couleur;


private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );
   IBestiole *clone() const override { return new Bestiole(*this); }
   int getId() const override { return identite; }
   int getX() const override { return x; }
   int getY() const override { return y; }

   //Pour gregaire
   double getOrientation() const override { return orientation; }

   double getVitesse() const override { return vitesse; }
   bool estVivante() const override { return vivante; }

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   std::vector<IBestiole *> getBestiolesDetectees(
      const std::vector<IBestiole *> &toutes) const override;

   // Pour gregaire
   void setComportement(IComportement *c) override;
   void setOrientation(double o) override { orientation = o; }


   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif

