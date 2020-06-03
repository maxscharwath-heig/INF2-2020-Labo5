#include <stdio.h>
#include "Bateau.h"
#include "Port.h"


int main() {
   Port port = nouveauPort(1);

   Bateau peche1 = nouveauBateauPeche("Noe", 20, 50);
   Bateau plaisance1 = nouveauBateauPlaisance("Gottham", 55, 42, "Batman");
   Bateau voilier1 = nouveauVoilier("Metropolis", 36);

   ajouterBateau(&port, &peche1);
   ajouterBateau(&port, &plaisance1);
   ajouterBateau(&port, &voilier1);
   afficherPort(&port);

   detruirePort(&port);
   ajouterBateau(&port, &plaisance1);
   afficherPort(&port);
}
