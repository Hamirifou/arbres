#include "list.c"
#include "list.h"

#include "personne.h"
#include "listpersonne.c"
#include <stdio.h>
#include <iostream>
int main () {
 Liste* lp = creerliste (0, ecrirePersonne, comparerPersonne);
 bool fini = faux;
 while (!fini) {
    switch (menu () ) {
    case 0:
      fini = vrai;
      break;
    case 1 : {
      printf ("Nom de la personne à créer ? ");
      ch15 nom; scanf ("%s", nom);
      printf ("Prénom de la personne à créer ? ");
      ch15 prenom; scanf ("%s", prenom);
      Personne* nouveau = creerPersonne (nom, prenom);
      insererEnTeteDeListe (lp, nouveau);
       } break;
       case 2 : {
  printf ("Nom de la personne à créer ? ");
  ch15 nom; scanf ("%s", nom);
  printf ("Prénom de la personne à créer ? ");
  ch15 prenom; scanf ("%s", prenom) ;
  Personne* nouveau = creerPersonne (nom, prenom) ;
  insererEnFinDeListe (lp, nouveau);
   } break;
case 3 : {
  Personne* extrait = (Personne*) extraireEnTeteDeListe (lp);
  if (extrait != NULL) {
    printf ("Élément %s %s extrait en tête de liste",
            extrait->nom, extrait->prenom) ;
   } else {
    printf ("Liste vide");
  } }break;
  case 4 : {
  Personne* extrait = (Personne*) extraireEnFinDeListe (1p);
 if (extrait != NULL) {
    printf ("Élément %s %s extrait en fin de liste",
            extrait->nom, extrait->prenom);
   } else {
    printf ("Liste vide");
   }} break;
case 5 : {
  printf ("Nom de la personne à extraire ? ");
  ch15 nom; scanf ("%s", nom);
  Personne* cherche = creerPersonne (nom, "?");
  Personne* pp (Personne*) chercherUnobjet (lp, cherche);
 if (extraireUnobjet (lp, pp)) {
    printf ("Élément %s %s extrait de la liste", pp->nom, pp->prenom);
  }

   } break;
   case 6:
  listerListe (lp);
  break;
case 7 : {
  printf ("Nom de la personne recherchée ? ");
  ch15 nom; scanf ("%s", nom);
  Personne* cherche = creerPersonne (nom, "?");
  Personne* pp (Personne*) chercherUnObjet (lp, cherche);
  if (pp != NULL) {
    printf ("%s %s trouvée dans la liste\n", pp->nom, pp->prenom) ;
   } else {
    printf ("%s inconnue dans la liste\n", nom);
   }} break;
case 8:
  detruireListe (lp);
  break;

  }
 }
return 0;
}

