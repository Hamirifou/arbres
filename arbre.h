


typedef void Objet;
typedef struct noeud
{
     Objet* reference;
    struct noeud* gauche;
    struct noeud* droite;
}Noeud;

typedef struct
{

    Noeud* racine;
    char* (*afficher) (Objet*) ;
    int (*comparer) (Objet*, Objet*);
 } Arbre;
