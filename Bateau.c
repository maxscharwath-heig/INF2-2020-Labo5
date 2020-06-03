#include "Bateau.h"

Bateau nouveauBateauPeche(const char* nom, uint16_t puissance, uint8_t capacite) {

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

Bateau nouveauBateauPlaisance(const char* nom, uint16_t puissance, uint8_t longueur,
                              const char* nomProprietaire) {
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

Bateau nouveauVoilier(const char* nom, uint16_t surfaceVoilure) {
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

void afficherBateau(const Bateau* bateau) {
   switch (bateau->typeBateau) {
      case T_PECHE :
         printf(
               "Type : Bateau de peche \n"
               "Nom  : %s \n"
               "Puissance  : %" PRIu16 "CV\n"
               "Capacite   : %" PRIu8 "t\n\n",
               bateau->nom,
               bateau->bateauMoteur.puissance,
               bateau->bateauMoteur.type.bateauPeche.capacite
         );
         break;
      case T_PLAISANCE :
         printf(
               "Type : Bateau de plaisance \n"
               "Nom  : %s \n"
               "Nom du proprietaire : %s \n"
               "Puissance  : %" PRIu16 "CV\n"
               "Longueur   : %" PRIu8 "m\n\n",
               bateau->nom,
               bateau->bateauMoteur.type.bateauPlaisance.nomProprietaire,
               bateau->bateauMoteur.puissance,
               bateau->bateauMoteur.type.bateauPlaisance.longueur
         );
         break;
      case T_VOILIER :
         printf(
               "Type : Voilier\n"
               "Nom  : %s \n"
               "Surface de la voile  : %" PRIu16 "m2\n\n",
               bateau->nom,
               bateau->voilier.voilure
         );
         break;
   }

}
