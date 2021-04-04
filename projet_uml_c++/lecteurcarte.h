/*
***NIANE Abdoulaye
** 12/03/2021
**/
#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>
#include "base_clients.h"
#include "voyants.h"
#include "timer.h"
#include "prise.h"
#include "bouton.h"
#include "generateur_save.h"

class LecteurCarte
{
  public : 
        LecteurCarte();    //Associer une classe LecteurCarte
	void initialiser(); // Initialisation des ports
	void lire_carte(); // Permet la lecture de la carte
	
  private : 
        Base_Clients baseclient; // Pour gérer la base de données des clients
        Voyants o_voyant; // Pour gérer les voyants
        Prise o_prise;
        Timer o_timer;
        Boutons o_bouton;
        Generateur_save o_generateur_save;
        unsigned numero; // Pour l'authentification des clients
        int stop;    // flag du bouton stop
};

#endif // LECTEURCARTE_H
