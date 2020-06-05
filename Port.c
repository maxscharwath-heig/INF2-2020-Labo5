//
// Created by Maxime on 03.06.2020.
//

#include "Port.h"
#include <stdlib.h>

const Bateau* ajouterBateau(ListeBateau* liste, const Bateau* bateau);

double calculTaxe(const Bateau* bateau);

double calculSommeTaxes(const ListeBateau* liste);

double calculMoyenneTaxes(const ListeBateau* liste);

double calculMedianeTaxes(const ListeBateau* liste);

void trierListeBateau(ListeBateau* triable);

int cmpfunc(const void* a, const void* b);

Port nouveauPort(const Bateau* liste, const size_t taille) {
   Port port = {
         .nbBateau = taille,
         .listeBateau = liste,
         .listeVoilier = {.taille=0, .capacite=0},
         .listePeche = {.taille=0, .capacite=0},
         .listePlaisance = {.taille=0, .capacite=0},
   };

   for (size_t i = 0; i < taille; ++i) {
      switch (liste[i].typeBateau) {
         case T_VOILIER:
            ajouterBateau(&port.listeVoilier, &liste[i]);
            break;
         case T_PECHE:
            ajouterBateau(&port.listePeche, &liste[i]);
            break;
         case T_PLAISANCE:
            ajouterBateau(&port.listePlaisance, &liste[i]);
            break;
      }
   }
   trierListeBateau(&port.listeVoilier);
   trierListeBateau(&port.listePeche);
   trierListeBateau(&port.listePlaisance);
   return port;
}

void trierListeBateau(ListeBateau* triable) {
   qsort((void*) triable->liste, triable->taille, sizeof(BateauTaxe), cmpfunc);
}

int cmpfunc(const void* a, const void* b) {
   return (int) (((BateauTaxe*) a)->taxeTotale - ((BateauTaxe*) b)->taxeTotale);
}

const Bateau* ajouterBateau(ListeBateau* liste, const Bateau* bateau) {
   if (liste->taille >= liste->capacite) {
      size_t tempCapacite = (size_t) ((liste->capacite + 1) * 1.5);
      BateauTaxe* temp = (BateauTaxe*) realloc(
            liste->liste,
            tempCapacite * sizeof(BateauTaxe)
      );
      if (temp == NULL) return NULL;
      liste->capacite = tempCapacite;
      liste->liste = temp;
   }
   BateauTaxe nouveauBateau = {bateau, calculTaxe(bateau)};
   liste->liste[liste->taille] = nouveauBateau;
   ++liste->taille;
   return bateau;
}

double calculTaxe(const Bateau* bateau) {
   double taxeTotale = 0;
   if (bateau->categorieBateau == C_MOTEUR) {
      taxeTotale += TAXE_MOTEUR;
      if (bateau->typeBateau == T_PECHE) {
         taxeTotale += bateau->bateauMoteur.type.bateauPeche.capacite <
                       TAXE_PECHE_SEUIL ? TAXE_PECHE_BAS : TAXE_PECHE_HAUT;
      } else { // tout pour plaisance
         taxeTotale += bateau->bateauMoteur.puissance <
                       TAXE_PLAISANCE_SEUIL ?
                       TAXE_PLAISANCE_BAS :
                       TAXE_PLAISANCE_FACTEUR_HAUT *
                       bateau->bateauMoteur.type.bateauPlaisance.longueur;
      }
   } else { // tout pour voilier
      taxeTotale += TAXE_VOILIER;
      taxeTotale += bateau->voilier.voilure < TAXE_VOILIER_SEUIL ?
                    TAXE_VOILIER_BAS : TAXE_VOILIER_HAUT;
   }
   return taxeTotale;
}

void afficherPort(const Port* port) {
   for (size_t i = 0; i < port->nbBateau; ++i) {
      afficherBateau(&port->listeBateau[i]);
   }
}

void afficherTaxes(const Port* port, const TypeTaxe taxe) {
   double voilier, peche, plaisance;
   switch (taxe) {
      case T_SOMME:
         printf("Somme");
         voilier = calculSommeTaxes(&port->listeVoilier);
         peche = calculSommeTaxes(&port->listePeche);
         plaisance = calculSommeTaxes(&port->listePlaisance);
         break;
      case T_MOYENNE:
         printf("Moyenne");
         voilier = calculMoyenneTaxes(&port->listeVoilier);
         peche = calculMoyenneTaxes(&port->listePeche);
         plaisance = calculMoyenneTaxes(&port->listePlaisance);
         break;
      case T_MEDIANE:
         printf("Mediane");
         voilier = calculMedianeTaxes(&port->listeVoilier);
         peche = calculMedianeTaxes(&port->listePeche);
         plaisance = calculMedianeTaxes(&port->listePlaisance);
         break;
      default:
         break;
   }
   printf(
         " des taxes des 3 types de bateaux: \n"
         "Voilier: %.2f\tE Peche: %.2f E\tPlaisance: %.2f E \n\n",
         voilier, peche, plaisance);
}

double calculSommeTaxes(const ListeBateau* liste) {
   double taxes = 0;
   for (size_t i = 0; i < liste->taille; ++i) {
      taxes += liste->liste[i].taxeTotale;
   }
   return taxes;
}

double calculMoyenneTaxes(const ListeBateau* liste) {
   return calculSommeTaxes(liste) / liste->taille;
}

double calculMedianeTaxes(const ListeBateau* liste) {
   return liste->taille % 2 ? liste->liste[liste->taille / 2].taxeTotale :
          (liste->liste[liste->taille / 2 - 1].taxeTotale +
           liste->liste[liste->taille / 2].taxeTotale) / 2.0;
}
