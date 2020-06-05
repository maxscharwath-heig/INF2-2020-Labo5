/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : Bateau.h
 Auteur(s)   : Kylian Bourcoud, Joan Maillard, Maxime Scharwath
 Date        : 05.06.2020
 But         : Déclaration du type composé Bateau et de ses fonctions associées
               les 3 fonctions ci-dessous simplifie la creation de
               la structure Bateau pour l'utilisateur.
               - nouveauBateauPeche()
               - nouveauBateauPlaisance()
               - nouveauVoilier()

               - afficherBateau() permet d'afficher les information du bateau donné.
 Remarque(s) : -
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO5_BATEAU_H
#define LABO5_BATEAU_H

#include <inttypes.h>
#include <stdio.h>

typedef struct Bateau {
   const char* nom;
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
               const char* nomProprietaire;
            } bateauPlaisance;
         } type;
      } bateauMoteur;
      //Voilier
      struct {
         uint16_t voilure;
      } voilier;
   };
} Bateau;

Bateau nouveauBateauPeche(
      const char* nom,
      uint16_t puissance,
      uint8_t capacite
      );

Bateau nouveauBateauPlaisance(
      const char* nom,
      uint16_t puissance,
      uint8_t longueur,
      const char* nomProprietaire
      );

Bateau nouveauVoilier(
      const char* nom,
      uint16_t surfaceVoilure
      );

void afficherBateau(const Bateau* bateau);

#endif //LABO5_BATEAU_H
