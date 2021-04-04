#include"base_clients.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Base_Clients :: Base_Clients()
{

}

int Base_Clients :: authentifier(int numero_carte)
{

  int num[4] = {16, 18, 20, 1234};
  int i = 0;
  int fin = 0;
  
  for(i=0; i<4; i++)
    {
    if(num[i] == numero_carte)
    fin = 1;
     }
  if(fin ==1)
   return 1;
   else
   return 0;
   
  }
