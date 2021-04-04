#include "timer.h"
#include<iostream>
#include<unistd.h>

using namespace std;

Timer::Timer()
{
int shmid;
raz = 0;
depart_timer = 0;
io = acces_memoire(&shmid);
if(io == NULL)
cout <<"Erreur pas de mem_sh"<<endl;
}
  
 int Timer::timer_raz()
{
depart_timer = io->timer_sec;
 return depart_timer;
  }
 
 int Timer::timer_valeur(int raz)
 {
 int val = 0;
 val = (io->timer_sec) - raz;
 return val;
 }
	
