/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : main.c
 Auteur(s)   : Kylian Bourcoud, Joan Maillard, Maxime Scharwath
 Date        : 05.06.2020
 But         : Tester la mise en place des librairies Bateau et Port
 Remarque(s) : -
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "Bateau.h"
#include "Port.h"

int main() {
   Bateau listeBateaux[] = {
         nouveauBateauPeche("Noe1", 20, 20),
         nouveauBateauPeche("Noe2", 10, 10),
         nouveauBateauPeche("Noe3", 10, 10),
         nouveauBateauPeche("Noe4", 30, 30),
         nouveauBateauPeche("Noe5", 10, 10),
         nouveauBateauPlaisance("Gotham", 55, 42, "Batman"),
         nouveauVoilier("Metropolis", 36),
   };

   Port port = nouveauPort(listeBateaux, 7);

   afficherPort(&port);

   afficherTaxes(&port, T_SOMME);
   afficherTaxes(&port, T_MOYENNE);
   afficherTaxes(&port, T_MEDIANE);
}
