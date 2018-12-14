#include "iniMap.h"

void Afficher(int * tab){
	for (int i = 1; i <= MAX; i++){
		if (i % N == 0 && i != 0)
			printf(" %d\n", tab[i]);
		else
			printf(" %d\t", tab[i]);	//Pour chaque ��l��ment
	}
}

void iniMap(int * tab,int ligne,int col)
{	
	
	for (int i = 1; i <= MAX; i++){
		tab[i] = 0;	//Tous sont 0
	}

	srand((unsigned)time(NULL));	////hazard,unsigned n'a pas -
	//placer bombe -1

	int j = 0;
	while (  j < NUM)//nb de mines
	{
		//creer 10 lieu pour bombe
		int x = rand() % (N - 1);	//ligne
		int y = rand() % N;  //col
		if (0 == tab[x*N + y])//si ajouter un mine i++
		{
			if ((x <= ligne - 3) || (x >= ligne + 3) || (y <= col - 3) || (y >= col + 3))//on ne mettre pas le bomb dans un region 5*5
			{
				tab[x*N + y] = -1;
				j++;
			}
		}
		
	      /*  if (x >= 0 && x < N && y >= 1 && y <= N){
					if (0 == tab[x*N + y])//si ajouter un mine i++
					{
						tab[x] = -1;
						j++;
					}
					if ((y<col + 2 && y>col - 2) && (x<ligne + 2 && x>ligne - 2)&& (x >= 0 && x < N && y >= 1 && y <= N) )//on ne mettre pas le bomb dans un region 5*5
					{
						tab[x] = -1;
						j--;
					}
	        }*/
	}
	
	//creer map
	//passer par tout les lieu de la carte,on +1 pour autour case de bombs


	for (int ligne = 0; ligne < N; ligne++){
		for (int col = 1; col <= N; col++){	//On partit �� Tab[1]
			if (tab[ligne*N + col] == -1)
			{
				for (int x = ligne - 1; x <= ligne + 1; x++)
				{
					for (int y = col - 1; y <= col + 1; y++)
					{
						if (x >= 0 && x < N && y >= 1 && y <= N && tab[x*N + y] != -1)
						{
							tab[x*N + y]++;
						}
					}
				}
				
			}
		}
	}

}





