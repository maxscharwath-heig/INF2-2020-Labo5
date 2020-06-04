#include <stdio.h>
#include "Bateau.h"
#include "Port.h"


int main() {
	
	PortTaxe structureTaxe = {
		.taxeDeBase = {
			.taxeVoilier = 50.0,
			.taxeMoteur = 100.0
		},
		.taxeSpecifique = {
			.peche = {
				.basTonnage = 0.0,
				.hautTonnage = 100.0,
				.seuilTonnage = 20
			},
			.plaisance = {
				.bassePuissance = 50.0, 
				.facteurHautePuissance = 15.0,
				.seuilPuissance = 100
			},
			.voilier = {
				.basseSurface = 0.0,
				.grandeSurface = 25.0,
				.seuilSurface = 200
			}
		} 
	};
	
   Port port = nouveauPort(&structureTaxe, 1);

   Bateau peche1 = nouveauBateauPeche("Noe1", 20, 20);
	Bateau peche2 = nouveauBateauPeche("Noe2", 10, 10);
	Bateau peche3 = nouveauBateauPeche("Noe3", 10, 10);
	Bateau peche4 = nouveauBateauPeche("Noe4", 30, 30);
	Bateau peche5 = nouveauBateauPeche("Noe5", 10, 10);
   Bateau plaisance1 = nouveauBateauPlaisance("Gottham", 55, 42, "Batman");
   Bateau voilier1 = nouveauVoilier("Metropolis", 36);

   ajouterBateau(&port, &peche1);
	ajouterBateau(&port, &peche2);
	ajouterBateau(&port, &peche3);
	ajouterBateau(&port, &peche4);
	ajouterBateau(&port, &peche5);
   ajouterBateau(&port, &plaisance1);
   ajouterBateau(&port, &voilier1);
   afficherPort(&port);
	
	afficherTaxes(&port, T_SOMME);
	afficherTaxes(&port, T_MOYENNE);
	afficherTaxes(&port, T_MEDIANE);

   viderPort(&port);
   ajouterBateau(&port, &plaisance1);
   afficherPort(&port);
}
