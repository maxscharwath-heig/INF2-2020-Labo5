#ifndef LABO5_BATEAU_H
#define LABO5_BATEAU_H

#include <inttypes.h>
#include <stdio.h>

typedef struct Bateau {
   char* nom;
   enum {
      C_MOTEUR, C_VOILIER
   } categorieBateau;
   enum {
      T_VOILIER, T_PECHE, T_PLAISANCE
   } typeBateau;
   union {
      // Bateau à moteur
      struct {
         uint16_t puissance;
         union {
            // bateau  de pêche
            struct {
               uint8_t capacite;
            } bateauPeche;


            // bateau de plaisance
            struct {
               uint8_t longueur;
               char* nomProprietaire;
            } bateauPlaisance;
         } type;
      } bateauMoteur;
      //Voilier
      struct {
         uint16_t voilure;
      } voilier;
   };
} Bateau;

Bateau nouveauBateauPeche(char* nom, uint16_t puissance, uint8_t capacite);
Bateau nouveauBateauPlaisance(char* nom, uint16_t puissance, uint8_t longueur, char* nomProprietaire);
Bateau nouveauVoilier(char* nom, uint16_t surfaceVoilure);

void afficherBateau(Bateau bateau);

#endif //LABO5_BATEAU_H
