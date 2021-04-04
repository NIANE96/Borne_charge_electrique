/*
***NIANE Abdoulaye
** 12/03/2021
**/


#ifndef BASE_CLIENTS_H
#define BASE_CLIENTS_H


class Base_Clients
{
  public : 
        
        Base_Clients();
	int authentifier(int numero_carte); // permet l'authentifation
	int reprise(int numero_reprise); //permet de reprendre la carte
};

#endif // BASE_CLIENTS_H
