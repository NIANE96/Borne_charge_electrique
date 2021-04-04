/*
***NIANE Abdoulaye
** 12/03/2021
**/
#ifndef VOYANTS_H
#define VOYANTS_H
#include "memoire_borne.h"
#include "mem_sh.h"
#include "donnees.h"


class Voyants
{
  public :
   
        Voyants();
        
	void voyants_set_charge(led etat); //charg voyants
	void voyants_set_dispo(led etat);
	void voyants_set_defaut(led etat);
	void voyants_set_trappe(led etat);
	void voyants_set_prise(led etat);
	
  private:
	 entrees *io;

};
#endif //VOYANTS_H