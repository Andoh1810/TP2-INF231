#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct nombre{
    int a;
    struct nombre *suiv;
}nombre;
nombre *l=NULL;
void insert_elt(int x){
    nombre *p=malloc(sizeof(nombre));
    scanf("%d",&x);
     p->a=x;
     p->suiv=NULL;
   if(l==NULL||l->a>=x){
    p->suiv=l;
    l=p;
    }else{
        nombre *liste=l;
    while(liste->suiv!=NULL && liste->suiv->a<x){
        liste=liste->suiv;
     }
        p->suiv=liste->suiv;
        liste->suiv=p;
    }
}
void afficher(){
    nombre *liste=l;
    while(liste!=NULL){
        printf("%d->",liste->a);
        liste=liste->suiv;
    }
    printf("NULL\n\n");
}
int main(){
    nombre *l=NULL;
    int val,choix;
    do{
        printf("que dsirez vous faire:\n");
        printf("1.Inserer un element dans la liste criee\n");
        printf("2.Afficher la liste\n");
        printf("0.QUITTER\n");
        printf("Faite votre choix:\t");
        scanf("%d",&choix);
        switch(choix){
            case 1: system("clear");
            printf("Entrer une valeur\t");
            insert_elt(val);
            break;
            case 2: system("clear");
            afficher();
            break;
            case 0: system("clear");
            printf("Exicting program...\n");
            break;
            default: printf("Choix invalide veuiller reessayer!!!\n");
        }
    }while(choix<3 || choix>0);
    return 0;
}