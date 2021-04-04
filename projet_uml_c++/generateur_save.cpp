#include "generateur_save.h"
#include <unistd.h>
#include "timer.h"
#include "prise.h"
#include "voyants.h"

using namespace std;

Generateur_save::Generateur_save()
{
int shmid;
 io = acces_memoire(&shmid);
if(io==NULL)
cout << "Erreur pas de mem sh" <<endl;
}

void Generateur_save::generateur_PWM(pwm etat)
{
 io->gene_pwm = etat;
}

void Generateur_save::generateur_charge(int numero)// rechargement
{
 Generateur_save();
o_voyant.voyants_set_charge(ROUGE);
Generateur_save::generateur_PWM(DC);
o_prise.deverrouiller_trappe();
while(io->gene_u!=9)
{
  sleep(1);
  cout << "******* ATTENTE 9V *******" << endl;
}
o_prise.verrouiller_trappe();
o_voyant.voyants_set_prise(VERT);
Generateur_save::generateur_PWM(AC_1K);
while(io->gene_u!=6)
{
 sleep(1);
 cout << "******* ATTENTE 6V *******" << endl;
}
io->contacteur_AC = 1;
if(io->gene_u==9)
{
 io->contacteur_AC = 0;
 o_voyant.voyants_set_charge(VERT);
 Generateur_save::generateur_PWM(DC);
}

else
{
 while(io->gene_u!=9) //&& !io->o_bouton.bouton_stop)
 {
   Generateur_save::generateur_PWM(AC_CL);
 }
  Generateur_save::generateur_PWM(STOP);
  o_voyant.voyants_set_charge(VERT);
}
io->contacteur_AC = 0;
while(1) // authentification de la carte et retrait apres rechargement
{
 cout << "******* FIN DE RECHARGEMENT *******" << endl;
 cout << "******* VEUILLEZ INSERER VOTRE CARTE *******" << endl;
 attente_insertion_carte();
 if(numero == lecture_numero_carte())
 {
   cout << "******* CARTE AUTHENTIFIER! *******" << endl;
   cout << "******* VEUILLEZ RETIRER LA CARTE *******" << endl;
   attente_retrait_carte();
   break;
 } 
 else
 cout << "******* ERREUR CARTE *******" << endl;
}

 cout << "******* N'OUBLIEZ PAS DE DEBRANCHER LA PRISE A BIENTOT!:) *******" << endl;
 o_prise.deverrouiller_trappe();
 while(io->gene_u!=12)
 {
  sleep(1);
  cout << "****** ATTENTE 6V ****** "<< endl;
 }
  o_voyant.voyants_set_prise(OFF);
  o_voyant.voyants_set_dispo(VERT);
}
