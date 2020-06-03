//
// Created by Maxime on 03.06.2020.
//

#include "Port.h"
#include <stdlib.h>

Port nouveauPort(size_t capacite) {
   Bateau* temp = NULL;
   if (capacite > 0) {
      temp = (Bateau*) calloc(capacite, sizeof(Bateau));
      if (temp == NULL) {
         //TODO A TESTER
         exit(EXIT_FAILURE);
      }
   }
   Port port = {
         .nbBateau = 0,
         .capacite = capacite,
         .listeBateau = temp
   };
   return port;
}

Bateau* ajouterBateau(Port* port, Bateau* bateau) {
   if (port->nbBateau >= port->capacite) {
      size_t tempCapacite = (port->capacite + 1) * 1.5;
      Bateau* temp = (Bateau*) realloc(
            port->listeBateau,
            tempCapacite * sizeof(Bateau)
      );
      if (temp == NULL) return NULL;
      port->capacite = tempCapacite;
      port->listeBateau = temp;
   }
   port->listeBateau[port->nbBateau] = *bateau;
   ++port->nbBateau;
   return bateau;
}

void afficherPort(const Port* port) {
   for (size_t i = 0; i < port->nbBateau; ++i) {
      afficherBateau(&port->listeBateau[i]);
   }
}

void viderPort(Port* port) {
   free(port->listeBateau);
   port->nbBateau = 0;
   port->capacite = 0;
   port->listeBateau = NULL;
}
