#include "Bateau.h"
#include "Port.h"


int main() {
   Bateau listeBateau[] = {
         nouveauBateauPeche("Noe1", 20, 20),
         nouveauBateauPeche("Noe2", 10, 10),
         nouveauBateauPeche("Noe3", 10, 10),
         nouveauBateauPeche("Noe4", 30, 30),
         nouveauBateauPeche("Noe5", 10, 10),
         nouveauBateauPlaisance("Gotham", 55, 42, "Batman"),
         nouveauVoilier("Metropolis", 36),
   };

   Port port = nouveauPort(listeBateau, 7);

   afficherPort(&port);

   afficherTaxes(&port, T_SOMME);
   afficherTaxes(&port, T_MOYENNE);
   afficherTaxes(&port, T_MEDIANE);
}
