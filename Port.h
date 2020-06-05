//
// Created by Maxime on 03.06.2020.
//
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

typedef struct BateauTaxe {
	Bateau* bateau;
	double taxeTotale;
} BateauTaxe;

typedef struct Port {
   size_t nbBateau;
   size_t capacite;
   BateauTaxe* listeBateau;
} Port;

Port nouveauPort(size_t capacite);

Bateau* ajouterBateau(Port* port, Bateau* bateau);

void afficherPort(const Port* port);

void afficherTaxes(const Port* port, const TypeTaxe taxe);

void viderPort(Port* port);


#endif //LABO5_PORT_H
