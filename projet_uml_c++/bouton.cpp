#include "bouton.h"


Boutons::Boutons()
{
int shmid;
 io = acces_memoire(&shmid);
 io->led_dispo = VERT;
}

int Boutons::bouton_charge()
{
if(io->bouton_charge == 1)
{
return 1;
}
else
{
return 0;
}
}

int Boutons::bouton_stop()
{
if(io->bouton_stop == 1)
{
return 1;
}
else
{
return 0;
}
}
