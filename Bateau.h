#ifndef LABO5_BATEAU_H
#define LABO5_BATEAU_H

typedef struct Bateau {
   // nom
   enum {MOTEUR, VOILIER} categorieBateau;
   enum {OTHER, PECHE, PLAISANCE} typeBateau;
   union {
      // Bateau à moteur
      union {
         // bateau  de pêche
         uint8_t capacite;

         // bateau de plaisance
         struct{
            uint8_t longueur;
            // nomProprio
         } bateauPlaisance;
      } type;

      // voilier
      uint16_t voilure;
   };

#endif //LABO5_BATEAU_H
