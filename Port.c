//
// Created by Maxime on 03.06.2020.
//

#include "Port.h"
#include <stdlib.h>

double calculTaxe(Bateau* bateau);
void calculSommeTaxes(const Port* port, double* voilier, double* peche, double* plaisance);
void calculMoyenneTaxes(const Port* port, double* voilier, double* peche, double* plaisance);
void calculMedianeTaxes(const Port* port, double* voilier, double* peche, double* plaisance);
int cmpfunc (const void * a, const void * b);


Port nouveauPort(size_t capacite) {
   BateauTaxe* temp = NULL;
   if (capacite > 0) {
      temp = (BateauTaxe*) calloc(capacite, sizeof(BateauTaxe));
      if (temp == NULL) {
         exit(EXIT_FAILURE);
      }
   }
   Port port = {
         .nbBateau = 0,
         .capacite = capacite,
         .listeBateau = temp,
   };
   return port;
}

Bateau* ajouterBateau(Port* port, Bateau* bateau) {
   if (port->nbBateau >= port->capacite) {
      size_t tempCapacite = (port->capacite + 1) * 1.5;
      BateauTaxe* temp = (BateauTaxe*) realloc(
            port->listeBateau,
            tempCapacite * sizeof(BateauTaxe)
      );
      if (temp == NULL) return NULL;
      port->capacite = tempCapacite;
      port->listeBateau = temp;
   }
	BateauTaxe nouveauBateau = {bateau, calculTaxe(bateau)};
   port->listeBateau[port->nbBateau] = nouveauBateau;
   ++port->nbBateau;
   return bateau;
}

double calculTaxe(Bateau* bateau) {
	double taxeTotale = 0;
	if (bateau->categorieBateau == C_MOTEUR) {
		taxeTotale += TAXE_MOTEUR;
		if (bateau->typeBateau == T_PECHE) {
			taxeTotale += bateau->bateauMoteur.type.bateauPeche.capacite < 
							  TAXE_PECHE_SEUIL ? TAXE_PECHE_BAS : TAXE_PECHE_HAUT;
		}
		else { // tout pour plaisance
			taxeTotale += bateau->bateauMoteur.puissance < 
							  TAXE_PLAISANCE_SEUIL ?
							  TAXE_PLAISANCE_BAS :
							  TAXE_PLAISANCE_FACTEUR_HAUT *
							  bateau->bateauMoteur.type.bateauPlaisance.longueur;
		}
	}
	else { // tout pour voilier
		taxeTotale += TAXE_VOILIER;
		taxeTotale += bateau->voilier.voilure < TAXE_VOILIER_SEUIL ?
						  TAXE_VOILIER_BAS : TAXE_VOILIER_HAUT;
	}
	return taxeTotale;
}

void afficherPort(const Port* port) {
   for (size_t i = 0; i < port->nbBateau; ++i) {
      afficherBateau(port->listeBateau[i].bateau);
   }
}

void afficherTaxes(const Port* port, const TypeTaxe taxe) {
	double voilier, peche, plaisance;
	switch(taxe) {
		case T_SOMME:
			printf("Somme");
			calculSommeTaxes(port, &voilier, &peche, &plaisance);
		break;
		case T_MOYENNE:
			printf("Moyenne");
			calculMoyenneTaxes(port, &voilier, &peche, &plaisance);
		break;
		case T_MEDIANE:
			printf("Mediane");
			calculMedianeTaxes(port, &voilier, &peche, &plaisance);
		break;
		default:
		break;
	}
	printf(" des taxes des 3 types de bateaux: \n Voilier: %.2f E Peche: %.2f E Plaisance: %.2f E \n\n", voilier, peche, plaisance);
}

void calculSommeTaxes(const Port* port, double* voilier, double* peche, double* plaisance) {
	*voilier = *peche = *plaisance = 0;
	for (size_t i = 0; i < port->nbBateau; ++i) {
		switch(port->listeBateau[i].bateau->typeBateau) {
			case T_PECHE:
				*peche += port->listeBateau[i].taxeTotale;
			break;
			case T_PLAISANCE:
				*plaisance += port->listeBateau[i].taxeTotale;
			break;
			case T_VOILIER:
				*voilier += port->listeBateau[i].taxeTotale;
			break;
			default:
			break;
		}
   }
}

void calculMoyenneTaxes(const Port* port, double* voilier, double* peche, double* plaisance) {
	size_t nbVoilier, nbPeche, nbPlaisance;
	*voilier = *peche = *plaisance = 0;
	nbVoilier = nbPeche = nbPlaisance = 0;
	for (size_t i = 0; i < port->nbBateau; ++i) {
		switch(port->listeBateau[i].bateau->typeBateau) {
			case T_PECHE:
				*peche += port->listeBateau[i].taxeTotale;
				++nbPeche;
			break;
			case T_PLAISANCE:
				*plaisance += port->listeBateau[i].taxeTotale;
				++nbPlaisance;
			break;
			case T_VOILIER:
				*voilier += port->listeBateau[i].taxeTotale;
				++nbVoilier;
			break;
			default:
			break;
		}
   }
	if (nbPeche) *peche /= (double) nbPeche;
	if (nbPlaisance) *plaisance /= (double) nbPlaisance;
	if (nbVoilier) *voilier /= (double) nbVoilier;
}

int cmpfunc (const void * a, const void * b) {
   return (int) ( *(double*)a - *(double*)b );
}

void calculMedianeTaxes(const Port* port, double* voilier, double* peche, double* plaisance) {
	size_t nbVoilier, nbPeche, nbPlaisance, idxVoilier, idxPeche, idxPlaisance;
	*voilier = *peche = *plaisance = 0;
	nbVoilier = nbPeche = nbPlaisance = idxVoilier = idxPeche = idxPlaisance = 0;
	for (size_t i = 0; i < port->nbBateau; ++i) {
		switch(port->listeBateau[i].bateau->typeBateau) {
			case T_PECHE:
				++nbPeche;
			break;
			case T_PLAISANCE:
				++nbPlaisance;
			break;
			case T_VOILIER:
				++nbVoilier;
			break;
			default:
			break;
		}
   }
	double* tabVoilier = (double*) calloc(nbVoilier, sizeof(double));
	double* tabPeche = (double*) calloc(nbPeche, sizeof(double));
	double* tabPlaisance = (double*) calloc(nbPlaisance, sizeof(double));
	if (tabVoilier == NULL || tabPeche == NULL || tabPlaisance == NULL) {
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < port->nbBateau; ++i) {
		switch(port->listeBateau[i].bateau->typeBateau) {
			case T_PECHE:
				tabPeche[idxPeche] = port->listeBateau[i].taxeTotale;
				++idxPeche;
			break;
			case T_PLAISANCE:
				tabPlaisance[idxPlaisance] = port->listeBateau[i].taxeTotale;
				++idxPlaisance;
			break;
			case T_VOILIER:
				tabVoilier[idxVoilier] = port->listeBateau[i].taxeTotale;
				++idxVoilier;
			break;
			default:
			break;
		}
	}
	qsort((void*)tabPeche, nbPeche, sizeof(double), cmpfunc);
	qsort((void*)tabPlaisance, nbPlaisance, sizeof(double), cmpfunc);
	qsort((void*)tabVoilier, nbVoilier, sizeof(double), cmpfunc);
	*voilier = nbVoilier % 2 ? tabVoilier[nbVoilier / 2] : (tabVoilier[nbVoilier / 2 - 1] + tabVoilier[nbVoilier / 2]) / 2.0;
	*peche = nbPeche % 2 ? tabPeche[nbPeche / 2] : (tabPeche[nbPeche / 2 - 1] + tabPeche[nbPeche / 2]) / 2.0;
	*plaisance = nbPlaisance % 2 ? tabPlaisance[nbPlaisance / 2] : (tabPlaisance[nbPlaisance / 2 - 1] + tabPlaisance[nbPlaisance / 2]) / 2.0;
	free(tabVoilier);
	free(tabPlaisance);
	free(tabPeche);
}


void viderPort(Port* port) {
   free(port->listeBateau);
   port->nbBateau = 0;
   port->capacite = 0;
   port->listeBateau = NULL;
}
