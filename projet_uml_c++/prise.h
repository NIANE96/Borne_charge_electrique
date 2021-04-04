/*
***NIANE Abdoulaye
** 12/03/2021
**/
#ifndef PRISE_H
#define PRISE_H
#include <lcarte.h>
#include "donnees_borne.h"
#include "donnees.h"
#include"mem_sh.h"
#include "voyants.h"

class Prise
{
  public : 
        
        Prise();
        void deverrouiller_trappe();
        void verrouiller_trappe();
	void set_prise();
	
  private:
	entrees *io;
};
#endif //PRISE_H
