#include <stdio.h>
#include "Bateau.h"





int main() {
   Bateau peche1 = nouveauBateauPeche("Noe", 20, 50 );
   Bateau Plaisance1 = nouveauBateauPlaisance("Gottham", 55, 42, "Batman" );
   Bateau voilier1 = nouveauVoilier("Metropolis", 36 );

   afficherBateau(peche1);
   afficherBateau(Plaisance1);
   afficherBateau(voilier1);
}
