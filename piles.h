#include "list.h"

typedef Liste Pile;
Pile* creerPile  (int type,char*(*afficher)(objet*),int (*comparer)(objet*,objet*)) ;
bool pileVide (Pile* p);
void  empiler (Pile* p, objet* objet);
objet * depiler (Pile* p);
void listerPile (Pile* p, void (*f) (objet*));
void detruirePile (Pile* p);

