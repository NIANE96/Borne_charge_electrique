/*
***NIANE Abdoulaye
** 12/03/2021
**/
#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H
#include <iostream>
#include "prise.h"
#include "voyants.h"
#include "donnees_borne.h"
#include "memoire_borne.h"
#include "mem_sh.h"
#include "donnees.h"
#include "bouton.h"

using namespace std;

class Generateur_save
{
  public : 
        
        Generateur_save(); 
        void generateur_PWM(pwm etat); //permet de generer un PWM
        void generateur_charge(int numero);
        
   private:
	entrees *io; // pour la connexion avec un boutons
        int shmid;
        Prise o_prise;
        Voyants o_voyant;
        Boutons o_bouton;      
};
#endif //GENERATEUR_SAVE_H