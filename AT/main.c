#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// J'ajoute ce commentaire pour ma formation en git
struct Cellule
{
    int Prio;
    char Car;
    struct Cellule *Next;
};
typedef struct Cellule *FaP;

FaP Inserer(FaP F, char x, int prio)
{
    FaP Nv;
    Nv = malloc(sizeof(FaP));
    Nv->Car = x;
    Nv->Prio = prio;
    Nv->Next = NULL;
    if (F)
    {
        Nv->Next = F;
    }
    return Nv;
}

FaP Extraite(FaP F)
{
    if (!F)
    {
        puts("La liste est vide");
        exit(EXIT_FAILURE);
    }
    FaP cp, q, max, maxAfter;
    char car;
    max = cp = F;
    q = F->Next;
    while (q)
    {
        if (max->Prio < q->Prio)
        {
            max = q;
            maxAfter = cp;
        }

        cp = cp->Next;
        q = q->Next;
    }
    if (max == F)
    {
        F = F->Next;
        free(max);
    }
    else
    {
        maxAfter->Next = max->Next;
        free(max);
    }

    return F;
}

void Afficher(FaP F)
{
    if (!F)
    {
        puts("La liste est vide");
        exit(EXIT_FAILURE);
    }
    for (; F; F = F->Next)
        printf("[%c][%d] ->", F->Car, F->Prio);
    puts("NULL\n");
}

int main(int argc, char const *argv[])
{
    FaP F = NULL;
    F = Inserer(F, 'x', 338);
    F = Inserer(F, 'a', 8);
    F = Inserer(F, 'z', 10);
    F = Inserer(F, 'b', 5);
    F = Inserer(F, 'c', 7);
    F = Inserer(F, 'd', 9);
    F = Inserer(F, 'f', 45);
    Afficher(F);
    Afficher(Extraite(F));

    return 0;
}
