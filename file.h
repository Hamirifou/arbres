#include "list.h"

typedef Liste File;
File* creerFile  (int type,char*(*afficher)(objet*),int (*comparer)(objet*,objet*)) ;
bool fileVide (File* p);
void  emfiler (File* p, objet* objet);
objet * defiler (File* p);
void listerFile (File* p, void (*f) (objet*));
void detruireFile (File* p);
