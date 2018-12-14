#include "jouer.h"
enum { DRAPEAU = 2, CLIQUE = 1 };
void drawMap(int * tab){
	int ligne, col;
	for (ligne = 0; ligne < N; ligne++)
	{
		for (col = 1; col < N; col++)
		{
			if (tab[ligne*N + col]>20)
				printf_s("F");	//pour des flags
			else{
				switch (tab[ligne*N + col])
				{
				case 9:
					printf_s("M");	//Mine
					break;
				case 10:
					printf_s("0");
					break;
				case 11:
					printf_s("1");
					break;
				case 12:
					printf_s("2");
					break;
				case 13:
					printf_s("3");
					break;
				case 14:
					printf_s("4");
					break;
				case 15:
					printf_s("5");
					break;
				case 16:
					printf_s("6");
					break;
				case 17:
					printf_s("7");
					break;
				case 18:
					printf_s("8");
					break;
				default:
					printf_s("*");
					break;
				}
			}
			printf_s("\t");
		}
		printf_s("\n");
	}
	
}

void playGame(int *tab,int flag){
	hitNum = 0;
	int ligne, col;
	int choix;
	
	printf_s("1 pour cliquer et 2 pour le drapeau(ajouter ou supprimer): \n");
	scanf_s("%d", &choix);
	printf_s("Entrer la linge et la colonne : \n");
	scanf_s("%d%d", &ligne, &col);
	switch (choix)
	{
	case CLIQUE:	//
		if (tab[ligne*N + col] == 0)
			Verifier(ligne, col, tab);
		else if (tab[ligne*N + col] < 9)
		{
			tab[ligne*N + col] += 10;
			hitNum++;	//Nb de case total visit��
		}
		else if (tab[ligne*N + col] >= 9 && tab[ligne*N + col] <= 18)
			printf_s("Cette case est d��j�� cliqu��, choisir la nouvelle case? \n");
			
		flag = tab[ligne*N + col];
		break;

	case DRAPEAU:	//marqu�� et drapeau
		if (tab[ligne*N + col] < 9)
			tab[ligne*N + col] += 30;	//Ajouter le drapeau
		else if (tab[ligne*N + col]>20)
			tab[ligne*N + col] -= 30; //Supprimer le drapeau
		    
		else if (tab[ligne*N + col] >= 9 && tab[ligne*N + col] <= 18)
			printf_s("Cette case est d��j�� cliqu��, choisir la nouvelle case? \n");	//La case affich��
		
		flag = tab[ligne*N + col];
		break;

	default: 
		printf_s("Vous devez entrer 1 ou 2 \n");
		break;
	}
}


void Verifier(int ligne, int col, int * tab){
	//Quand la case n'est pas cliqu��
	tab[ligne*N + col] += 10;
	hitNum++;
	for (int x = ligne - 1; x <= ligne + 1; x++)
	{
		for (int y = col - 1; y <= col + 1; y++)
		{
			if (x >= 0 && x <= N - 1 && y >= 1 && y <= N)
			{
				if (tab[x*N + y] <= 9)	//La case qui n'est pas cliqu��
				{
					if (tab[x*N + y] != 0)
					{
						tab[x*N + y] += 10;
						hitNum++;
					}
					else
						Verifier(x, y, tab);
				}
			}
		}
	}
}