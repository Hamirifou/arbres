#include "piles.h"
#include <stddef.h>



Pile* creerPile(int type,char*(*afficher)(objet*),int (*comparer)(objet*,objet*)) {
  return creerliste(type,afficher,comparer);
}
bool pileVide (Pile* p) {
  return listeVide (p);
}
void empiler (Pile* p, objet* objet) {
  insererEnTeteDeListe (p, objet);}

objet* depiler (Pile* p) {
 if (pileVide (p)) {
    return NULL;
   } else {
    return extraireEnTeteDeListe (p);
   }}
void listerPile (Pile* p, void (*f) (objet*)) {
  listerListe (p);
void detruirePile (Pile* p) {
  detruireListe (p);}
}

