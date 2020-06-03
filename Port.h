//
// Created by Maxime on 03.06.2020.
//
#ifndef LABO5_PORT_H
#define LABO5_PORT_H

#include <inttypes.h>
#include <stdio.h>
#include "Bateau.h"

typedef struct Port {
   size_t nbBateau;
   size_t capacite;
   Bateau* listeBateau;
} Port;

Port nouveauPort(size_t capacite);

Bateau* ajouterBateau(Port* port, Bateau* bateau);

void afficherPort(const Port* port);

void detruirePort(Port* port);


#endif //LABO5_PORT_H
