//
// Created by Maxime on 03.06.2020.
//
#ifndef LABO5_PORT_H
#define LABO5_PORT_H

#include <inttypes.h>
#include <stdio.h>
#include "Bateau.h"

typedef enum {
	T_SOMME, 
	T_MOYENNE, 
	T_MEDIANE
} TypeTaxe;

typedef struct BateauTaxe {
	Bateau* bateau;
	double taxeTotale;
} BateauTaxe;

typedef struct PortTaxe {
	struct {
		double taxeVoilier;
		double taxeMoteur;
	} taxeDeBase;
	
	struct {
		struct {
			double basTonnage;
			double hautTonnage;
			uint8_t seuilTonnage;
		} peche;
		
		struct {
			double bassePuissance;
			double facteurHautePuissance;
			uint16_t seuilPuissance;
		} plaisance;
		
		struct {
			double basseSurface;
			double grandeSurface;
			uint16_t seuilSurface;
		} voilier;
	} taxeSpecifique;
	
} PortTaxe;

typedef struct Port {
   size_t nbBateau;
   size_t capacite;
   BateauTaxe* listeBateau;
	PortTaxe* taxe;
} Port;

Port nouveauPort(PortTaxe* taxe, size_t capacite);

Bateau* ajouterBateau(Port* port, Bateau* bateau);

void afficherPort(const Port* port);

void afficherTaxes(const Port* port, const TypeTaxe taxe);

void viderPort(Port* port);


#endif //LABO5_PORT_H
