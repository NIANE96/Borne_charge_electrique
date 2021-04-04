/*
***NIANE Abdoulaye
** 12/03/2021
**/
#ifndef BOUTON_H
#define BOUTON_H
#include "memoire_borne.h"
#include "mem_sh.h"
#include "donnees.h"



class Boutons
{
  public : 
        
        Boutons();
	int bouton_stop();
	int bouton_charge(); // permet de mettre le bouton stop à 1 return 1 si bouton stop sion 0
	
	private:
	entrees *io; // pour la connexion avec un bouton
};
#endif //BOUTON_H
