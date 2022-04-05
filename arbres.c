
#include "arbre.h"
#include"list.h"
#include <stddef.h>

Noeud* cNd (Objet* objet, Noeud* gauche, Noeud* droite){
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->reference = objet;
    nouveau->gauche = gauche;
    nouveau->droite= droite;
    return nouveau;
}


Noeud* cF (Objet* objet){
return cNd (objet, NULL, NULL);

}

void initArbre (Arbre* arbre, Noeud* racine,
     char* (*afficher) (Objet*), int (*comparer) (Objet*, Objet*))
     {


    arbre->racine = racine;
   arbre->afficher = afficher;
   arbre->comparer = comparer ;

     }

Arbre* creerArbre (Noeud* racine, char (*afficher) (Objet),
               int (*comparer) (Objet*, Objet*))
    {
    Arbre* arbre =(Arbre*)malloc(sizeof(Arbre));
    initArbre (arbre, racine, afficher, comparer);
    return arbre;
    }

    void prefixe (Noeud* racine, char* (*afficher) (Objet*))
   {

     if (racine != NULL)
   {
      printf ("%s \n", afficher (racine->reference));
      prefixe (racine->gauche,afficher);
      prefixe (racine->droite,afficher);
   }
   }


   void infixe (Noeud* racine, char* (*afficher) (Objet*))
   {
        if (racine != NULL)
        {
        infixe (racine->gauche, afficher);
        printf ("%s ", afficher (racine->reference));
        infixe (racine->droite, afficher);
        }
   }

  void postfixe (Noeud* racine, char* (*afficher) (Objet*))
  {

      if (racine != NULL)
      {
         postfixe (racine->gauche, afficher);
       postfixe (racine->droite, afficher);
       printf ("%s ", afficher (racine->reference));
      }
  }


  Noeud* trouverNoeud (Noeud* racine, Objet* objet,
                       int (*comparer) (Objet*, Objet*))
  {

     Noeud* pNom;
   if (racine == NULL)
   {
       pNom = NULL;
   }

   else if (comparer (racine->reference, objet) == 0)
      {
          pNom = racine;
      }

   else

   {
       pNom = trouverNoeud (racine->gauche, objet, comparer);
      if (pNom == NULL) pNom = trouverNoeud (racine->droite, objet,comparer);
   }
   return pNom;
  }

void enLargeur (Noeud* racine, char* (*afficher) (Objet*))
{

    Liste* li = creerliste (NULL,afficher,NULL);
    insererEnFinDeLISTE (li, racine);
    while (!listeVide(li) )
    {

        Noeud* extrait = (Noeud*) extraireEnFinDeListe (li);
        printf ("%s\n",afficher(extrait->reference));

        if (extrait->gauche != NULL) insererEnTeteDeListe(li,extrait->gauche);
        if (extrait->droite != NULL) insererEnTeteDeListe(li,extrait->droite);
}

}

int taille (Noeud* racine){
   if (racine == NULL){
                    return 0;}
    else
      {
          return 1 + taille (racine->gauche) + taille (racine->droite);
}
      }
bool estFeuille (Noeud* racine){
    return (racine->gauche==NULL) && (racine->droite==NULL) ;}

int nbFeuilles (Noeud* racine){
    if (racine == NULL)
         return 0;
    else if ( estFeuille (racine) )
         return 1;
    else
         return nbFeuilles (racine->gauche) + nbFeuilles (racine->droite);
}
void listerFeuilles (Noeud* racine, char* (*afficher) (Objet*)){
    if (racine != NULL){
       if (estFeuille (racine)){
            printf ("%s ", afficher (racine->reference));}
        else{
            listerFeuilles (racine->gauche, afficher);
            listerFeuilles (racine->droite, afficher);
}}}

int hauteur (Noeud* racine){
    if (racine == NULL)
         return 0;
    else{
            if(hauteur (racine->gauche)>hauteur (racine->droite))
         return 1 + hauteur (racine->gauche) ;
            else
                return 1 + hauteur (racine->droite);

    }}

bool egaliteArbre (Noeud* racinel, Noeud* racine2,int (*comparer) (objet*, Objet*))
{

    bool resu = false;
    if ( (racinel==NULL) && (racine2==NULL) )
        resu = true;
    else if ( (racinel!=NULL) && (racine2!=NULL) )
       if (comparer (racinel->reference, racine2->reference) == 0)
           if (egaliteArbre (racinel->gauche, racine2->gauche, comparer) )
                resu = egaliteArbre (racinel->droite, racine2->droite, comparer);
    return resu;
}

