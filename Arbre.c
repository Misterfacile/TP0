
#include <stdio.h>
#include <stdlib.h>

#include "Arbre.h"

int main(){
	noeud *arbre = NULL;
	noeud *nd = NULL;
	char car;
	char choix,rep;
	int pos;
	int sortie = 0;
	//Test
	printf("Etiquette de la racine : ");
	scanf("%c",&car);
	arbre = nouvNoeud(car);
	do{
		choixMenu();
		scanf("%c", &choix);
		switch(choix){
		case 'I': case 'i':	printf("\nInserer après quel noeud (on commence à 1) : ");
							scanf("%d",&pos);
							printf("Etiquette du nouvel noeud à inserer : ");
							fflush(stdin);
							scanf("%c",&car);
							nd = nouvNoeud(car);
							do{
								printf("\nInserer en fils gauche :\tG");
								printf("\nInserer en fils droit :\t\tD");
								printf("\nchoix > ");
								fflush(stdin);
								scanf("%c",&rep);
								switch(rep){
								case 'G': case 'g':	insererFG(nd,arbre,pos);
													sortie = 1;
													break;
								case 'D': case 'd':	insererFD(nd,arbre,pos);
													sortie = 1;
													break;
								default :			printf("\nChoix incorrect.\n");
								}
							}while(sortie!=1);
							break;
		case 'S': case 's':	printf("\nQuel est le numéro de création de l'arbre à supprimer : ");
							scanf("%d",&pos);
							nd = rechercheNoeud(arbre,pos);
							if (nd==arbre) //si on supprime racine, eviter d'afficher le tas liberé
								arbre=NULL;
							supprimeArbre(nd);
							printf("\n");
							break;
		case 'A': case 'a':	printf("\n***************** Affichage de l'arbre selon le format : EtiquetteNoeud(Père)(Branche Droite ou Gauche) *****************\n");
							parcoursPrefixe(arbre,'c');
							printf("\n");
							break;
		case 'Q': case 'q':	printf("\nAu revoir\n");
							break;
		default : printf("\nChoix incorrect.\n");
		}
	}while(choix != 'Q' && choix != 'q');
	free(arbre);
	free(nd);
	return EXIT_SUCCESS;
}
