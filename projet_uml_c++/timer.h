/*
***NIANE Abdoulaye
** 12/03/2021
**/
#ifndef TIMER_H
#define TIMER_H
#include <lcarte.h>
#include "memoire_borne.h"
#include "mem_sh.h"
#include "donnees.h"



class Timer
{
  public : 
        
        Timer();
        int timer_raz();
	int timer_valeur(int raz);
	
  private:
	entrees *io; // pour la connexion avec un boutons
        int raz; // pour sauvegarder la valeur du temps lors de raz
        int depart_timer; // temps actuel
};
#endif //TIMER_H
