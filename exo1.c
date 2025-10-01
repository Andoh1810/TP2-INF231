#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct nombre{
    int a;
    struct nombre *suiv;
}nombre;
nombre *l=NULL;
void insertete(int x){
    nombre *p=malloc(sizeof(nombre));
    scanf("%d",&x);
    p->a=x;
    p->suiv=l;
    l=p;
}
void afficher(){
    nombre *liste=l;
    while(liste!=NULL){
        printf("%d->",liste->a);
        liste=liste->suiv;
    }
    printf("NULL\n");
}
int recherche(int val){
    nombre *liste=l;
    int ind=0;
if(liste==NULL){
    system("clear");
    printf("aucun element present dans la liste\n");
    return ind;
}
while(liste!=NULL){
    if(liste->a==val){
        ind=1;
        return ind;
    }else{
        ind=0;
    }
    liste=liste->suiv;
}
return ind;
}
void supprimer_occ(int val){
    nombre *next=l;
    nombre *prec=NULL;
    while(next!=NULL){
        if(next->a==val){
            nombre *tmp=next;
            if(prec==NULL){
                l=next->suiv;
                next=l;
            }else{
                prec->suiv=next->suiv;
                next=next->suiv;
            }
            free(tmp);
        }else{
            prec=next;
            next=next->suiv;
        }

    }
}
int main(){
    char rep[3];
    nombre *l=malloc(sizeof(nombre));
    int n,b,choix,ind;
    l=NULL;
    do{
        printf("Que desirez vous faire:\n");
        printf("1. insertion en tete de liste simple\n");
        printf("2.afficher la liste\n");
        printf("3.rechercher une valeur \n");
        printf("4.supprimer une valeur avec toutes ses occurences dans la liste\n");
        printf("0. QUITTER\n");
        printf("faite votre choix\t");
        scanf("%d",&choix);
        switch(choix){
            case 1: system("clear");
            printf("entrer un entier:\n");
            insertete(n);
            break;
            case 2: system("clear");
            afficher();
            break;
            case 3: system("clear");
            printf("Enrez la valeur a rechercher\t");
            scanf("%d",&b);
            ind=recherche(b);
            if(ind==1){
                printf("valeur trouvee dans la liste...\n");
            }else{
                printf("valeur introuvable...\n");
            }
            break;
            case 4: system("clear");
            printf("Enrez la valeur a supprimer\t");
            scanf("%d",&b);
            ind=recherche(b);
            if(ind==1){
                printf("valeur trouvee dans la liste...\n");
                supprimer_occ(b);
                system("clear");
                printf("valeur supprimer avec succes....\n");
                afficher();
            }else{
                printf("valeur introuvable...\n");
            }
            break;
            case 0: system("clear");
            printf("exicting program....\n");
            break;
             default: printf("choix invalide ..veuillez reesayer");
        }
        printf("\n voulez vous continuer? (O/N)\t");
        scanf("%s",rep);

    }while(choix<5||strcmp(rep,"O")==0||strcmp(rep,"o")==0||strcmp(rep,"oui")==0||strcmp(rep,"OUI")==0||strcmp(rep,"Oui")==0);
 return 0;
}