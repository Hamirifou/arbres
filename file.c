
#include "file.h"
#include <stddef.h>



File* creerFile(int type,char*(*afficher)(objet*),int (*comparer)(objet*,objet*)) {
  return creerliste(type,afficher,comparer);
}
bool fileVide (File* p) {
  return listeVide (p);
}
void emfiler (File* p, objet* objet) {
  insererEnTeteDeListe (p, objet);}

objet* defiler (File* p) {
 if (fileVide (p)) {
    return NULL;
   } else {
    return extraireEnFinDeListe (p);
   }}
void listerFile (File* p, void (*f) (objet*)) {
  listerListe (p);
void detruireFile (File* p) {
  detruireListe (p);}
}

