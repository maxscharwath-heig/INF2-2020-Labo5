#include "Bateau.h"

Bateau nouveauBateauPeche(char *nom, uint16_t puissance, uint8_t capacite) {

   Bateau bateau = {
      .nom             = nom,
      .categorieBateau = C_MOTEUR,
      .typeBateau      = T_PECHE,
      .bateauMoteur    = {
            .puissance    = puissance,
            .type         = {
                  .bateauPeche = {
                        .capacite = capacite
                  }
            }
      }
   };
   return bateau;
}

Bateau nouveauBateauPlaisance(char *nom, uint16_t puissance, uint8_t longueur, char *nomProprietaire) {
   Bateau bateau = {
         .nom             = nom,
         .categorieBateau = C_MOTEUR,
         .typeBateau      = T_PLAISANCE,
         .bateauMoteur    = {
               .puissance    = puissance,
               .type         = {
                     .bateauPlaisance = {
                           .longueur        = longueur,
                           .nomProprietaire = nomProprietaire
                     }
               }
         }
   };
   return bateau;
}

Bateau nouveauVoilier(char *nom, uint16_t surfaceVoilure) {
   Bateau bateau = {
         .nom             = nom,
         .categorieBateau = C_VOILIER,
         .typeBateau      = T_VOILIER,
         .voilier    = {
               .voilure = surfaceVoilure
         }
   };
   return bateau;
}

void afficherBateau(Bateau bateau) {
   switch (bateau.typeBateau){
      case T_PECHE :
         printf(
               "Type : Bateau de peche \n"
               "Nom  : %s \n"
               "capacite  : %s \n"
               , bateau.nom
               );
         break;
      case T_PLAISANCE :
         printf("Type : Bateau de plaisance \n");
         break;
      case T_VOILIER :
         printf("Type : Voilier\n");
         break;
   }

}
