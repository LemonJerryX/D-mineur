#include "iniMap.h"
#include "jouer.h"

int main() {
	enum { PLAY = 1, RESTART = 2, Self = 3 };	//Self pour d¨¦finir le map par moi-m¨ºme
	int * tab;
	tab = (int*)malloc(sizeof(int)*(MAX + 1));
	int flag= 0;
	int ligne, col;
	printf_s("Entrer la linge et la colonne : \n");
	scanf_s("%d%d", &ligne, &col);
	iniMap(tab, ligne, col);
	while (PLAY)	//Ce qu'on choisit
	{
		drawMap(tab);
		playGame(tab, flag);
		if (flag == 9)
		{
			drawMap(tab);
			printf_s("You lose!");
			break;
		}
		else if (100 - hitNum == NUM)
		{
			drawMap(tab);
			printf_s("You win");
			break;
		}
	}
	system("pause");
	free(tab);
	
	return 0;
}




/*
int main(){

	int * tab;
	int *flag;
	int *ligne, *col;
	flag = 0;
	tab = (int*)malloc(sizeof(int)*(MAX + 1));
	printf_s("Entrer la linge et la colonne : \n");
	scanf_s("%d%d", &ligne, &col);
    iniMap(tab,ligne,col);
		while (1)	//Ce qu'on choisit
		{
			drawMap(tab);
			playGame(tab,flag);
			if (flag == 9)
			{
				drawMap(tab);
				printf_s("You lose!");
				break; 
			}
			else if (100 - hitNum == NUM)
			{
				drawMap(tab);
				printf_s("You win");
				break;
			}
	

	}
	getchar();
	free(tab);
	return 0;
}
*/