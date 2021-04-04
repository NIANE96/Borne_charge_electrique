#include "lecteurcarte.h"
#include<unistd.h>
//#include "mem_sh.h"
//#include "donnees.h"

using namespace std;

LecteurCarte::LecteurCarte()
{

}

//Constructeur initi
void LecteurCarte::initialiser()
{
 initialisations_ports();
}
 

void LecteurCarte::lire_carte()
{
     numero= 0;
     int raz;
     stop = 0;    
     int flag1 = 0;

while(!flag1)
{  
o_voyant.voyants_set_charge(OFF);   
while(1)
{
      
      o_timer.timer_raz();
      cout << endl << "********* BIENVENUE VEUILLEZ INSERER VOTRE CARTE *******" << endl;
      attente_insertion_carte();
      cout << endl << "********* carte inseree *******" << endl;
      numero= lecture_numero_carte();
      cout << "Numero de la carte est :" << numero << endl;
      
         if(baseclient.authentifier(numero))
        {
        cout << "******** AUTHENTIFICATION REUSI :) ********" << endl;
      //  o_voyant.voyants_set_charge(VERT);
        //o_voyant.voyants_clignote_charge(8);
         raz = o_timer.timer_raz();
        
        while(o_timer.timer_valeur(raz) != 8)
        {
           o_voyant.voyants_set_charge(VERT);
           usleep(500000);
           o_voyant.voyants_set_charge(OFF);
           usleep(500000);
           
           if(o_bouton.bouton_charge())
           {
            o_voyant.voyants_set_dispo(OFF);
            flag1 = 1;
            break;
           }
         }
         break;  
     }
         
        else
       {
         cout << "*** ECHEC AUTHENTIFICATION\n ***** VEUILLEZ RETIRER LA CARTE SVP ***" << endl;
         cout << "****** CARTE NON ABONNEE !********" << endl;
         
         raz = o_timer.timer_raz();
        
        while(o_timer.timer_valeur(raz) != 8)
        {
           o_voyant.voyants_set_defaut(ROUGE);
           usleep(500000);
           o_voyant.voyants_set_defaut(OFF);
           usleep(500000);
         }
        } 
        attente_retrait_carte();
        
    }
    
     o_voyant.voyants_set_charge(VERT);
       while(o_timer.timer_valeur(raz) != 30&&flag1)
       {
         if(o_bouton.bouton_charge())
         {
          o_voyant.voyants_set_dispo(OFF);
          flag1 = 1;
          cout << "***** VEUILLEZ RETIRER LA CARTE******"<<endl;
          break;
         }
       }
       
       if(flag1==0)
       {
        cout << "***** TEMPS D'ATTENTE DEPASSE RETIRER LA CARTE! :)******"<<endl;
        attente_retrait_carte();
       }
 }
 
 attente_retrait_carte();
 o_generateur_save.generateur_charge(numero);
 o_voyant.voyants_set_dispo(VERT);
 o_voyant.voyants_set_trappe(OFF);
  liberation_ports();
 }
          





