#include "prise.h"
#include <iostream>
using namespace std;

Prise::Prise()
{
int shmid;
 io = acces_memoire(&shmid);
 //if(io == NULL)
 //cout <<"Erreur pas de mem_sh"<<endl;
}

void Prise::deverrouiller_trappe()
{
 io->led_trappe = VERT;
 }

void Prise::set_prise()
{
 io->led_prise = VERT;
 }
     
void Prise::verrouiller_trappe()
 {
 io->led_trappe = OFF;
 }
