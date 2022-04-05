#include <stdio.h>
#include "personne.h"
#include "arbre.h"
#include<stdbool.h>
typedef char ch20[21];

char* afficherNoeud (Objet* objet) {
     char* p = (char*) objet;
     return p ;
  }
int comparerNoeud (char* objet1, char* objet2) {
  return strcmp (objet1, objet2);
}


 Arbre* creerArbreGene () {
  Noeud* racine =
    cNd ( "Samir",
          cNd ( "Kamal",
                cNd ( "Yassine",
                      NULL,
                      cNd ( "Hind", NULL, cF ("Yasmine") )
                    ),
                     cNd ( "Sarah", cF ("Karim"), NULL)
               ),
          NULL
        );
    //    printf("%s",racine->gauche->reference);
  return creerArbre (racine,afficherNoeud,comparerNoeud);

}
int menu () {
  printf ("\n\nGESTION D'UNE LISTE DE PERSONNES\n\n");
  printf ("0 Fin\n");
  printf ("1 creataion de l' arbre geneologique \n");
  printf ("2 parcours prefixe\n");
  printf ("3 parcours infixe\n");
  printf ("4 parcours postfixe\n");



  printf ("5 trouver un noeud\n");
  printf ("6 parcours en largeur\n");
  printf ("7 taille de l arbre\n");
  printf ("8 est feuille ?\n");
  printf ("9 nbr feuilles\n");
  printf ("10 liste feuilles\n");
  printf ("11 hauteur de l arbre\n");
  printf ("12 egalite entre 2 abrbres\n");
  printf ("Votre choix ? ");

  int cod; scanf ("%d", &cod) ;
  printf ("\n");
  return cod;
}
int main () {

Arbre* tree;
bool fini =false;
while (!fini){
    switch(menu()){
case 0 : {fini = true ; break;
}
case 1 : {
    tree= creerArbreGene();
}
    break;
case 2 :{

    prefixe(tree->racine,afficherNoeud);break;

    }
    case 3 : {infixe(tree->racine,afficherNoeud);break;

    }
    case 4 : {postfixe(tree->racine,afficherNoeud);break;

    }

    case 5 : {
        ch20 nom;
        printf("donner un nom: ");
        scanf("%s",nom);
        Noeud* noeud=afficherNoeud(trouverNoeud(tree->racine,nom,comparerNoeud));
        if(noeud==NULL){
            printf("cet element n'existe pas");}
        else {printf("l element %s existe",noeud->reference);}
        break;
        }
    case 6 : {enLargeur(tree->racine,afficherNoeud);
    break;
    }
    case 7 : {
        printf("la taille de l'arbre est :%d",taille(tree->racine));
    break;}
    case 8 : {
        ch20 nom;
        printf("donner un nom: ");
        scanf("%s",nom);
         Noeud* noeud=trouverNoeud(tree->racine,nom,comparerNoeud);
        if(noeud==NULL){
            printf("cet element n'existe pas");}
        else {
                bool a;

    a= estFeuille(noeud);
    if (a==true)
    printf("%s est une feuille",noeud->reference);
    else printf("%s n 'est une feuille",noeud->reference);      }
        break;

    break;
    }
    case 9 :{
        printf("nombre de feuilles est : %d",nbFeuilles(tree->racine));
    break;}
    case 10 : {
        listerFeuilles(tree->racine,afficherNoeud);
    break;}
    case 11 : {
    printf("l'hauteur de l'arbre est: %d ",hauteur(tree->racine));break;}
    case 12 : {
    printf("%d",egaliteArbre(tree->racine,tree->racine->droite,comparerNoeud));}
}}
return 0;
}


