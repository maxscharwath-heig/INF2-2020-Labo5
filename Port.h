/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : Port.h
 Auteur(s)   : Kylian Bourcoud, Joan Maillard, Maxime Scharwath
 Date        : 05.06.2020
 But         : Déclaration du type composé Port et de ses fonctions associées.
               3 fonctions sont accessible pour l'utilisateur:
               - nouveauPort() Simplifie la créeation d'un port
                  avec un tableau de Bateau
               - afficherPort() Affiche la liste des bateaux dans le port
               - afficherTaxes() Permet d'afficher le type de taxes
                  (SOMME, MOYENNE, MEDIANE) par type de bateau.
 Remarque(s) : - BateauTaxe stoque la taxe et le pointeur du bateau associé,
                  mais actuellemnt on utilse pas ce pointeur mais il peut être utile
                  pour un affichage par type.
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO5_PORT_H
#define LABO5_PORT_H

#include <inttypes.h>
#include <stdio.h>
#include "Bateau.h"

#define TAXE_VOILIER 50.0
#define TAXE_MOTEUR 100.0

#define TAXE_PECHE_BAS 0.0
#define TAXE_PECHE_HAUT 100.0
#define TAXE_PECHE_SEUIL 20

#define TAXE_PLAISANCE_BAS 50.0
#define TAXE_PLAISANCE_FACTEUR_HAUT 15.0
#define TAXE_PLAISANCE_SEUIL 100

#define TAXE_VOILIER_BAS 0.0
#define TAXE_VOILIER_HAUT 25.0
#define TAXE_VOILIER_SEUIL 200

typedef enum {
	T_SOMME, 
	T_MOYENNE, 
	T_MEDIANE
} TypeTaxe;

//BateauTaxé permet de lier un bateau avec sa taxe
typedef struct BateauTaxe {
	const Bateau* bateau;
	double taxeTotale;
} BateauTaxe;

//ListeBateau est une structure qui permet de stoquer dynamiquement
// une liste de bateau du même type
typedef struct ListeBateau {
   BateauTaxe* liste;
   size_t taille;
   size_t capacite;
} ListeBateau;

//Port est une structure d'un port
typedef struct Port {
   size_t nbBateau;
   const Bateau* listeBateau;
   ListeBateau listeVoilier;
   ListeBateau listePeche;
   ListeBateau listePlaisance;
} Port;

Port nouveauPort(const Bateau *bateaux, size_t taille);

void afficherPort(const Port* port);

void afficherTaxes(const Port* port, TypeTaxe taxe);

#endif //LABO5_PORT_H
