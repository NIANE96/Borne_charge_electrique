#include <iostream>
#include"voyants.h"
#include <unistd.h>
#include "timer.h"

using namespace std;

Voyants :: Voyants()
{
int shmid;
 io = acces_memoire(&shmid);
 if(io == NULL)
 cout <<"Erreur pas de mem_sh"<<endl;
}

void Voyants::voyants_set_charge(led etat)
{
 io->led_charge =etat;

}

void Voyants::voyants_set_dispo(led etat)
{
 io->led_dispo =etat;
}


void Voyants::voyants_set_defaut(led etat)
{
 io->led_defaut =etat;
}

void Voyants::voyants_set_prise(led etat)
{
 io->led_prise =etat;
}

void Voyants::voyants_set_trappe(led etat)
{
 io->led_trappe =etat;
}

