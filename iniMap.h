#ifndef INITMAP
#define INITMAP
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 100
#define N 10
int hitNum;
#define NUM 10


typedef struct 
{
	int b, nbB;
	bool flag, marque;
}Case, *addr;


void iniMap(int * tab,int  ligne,int col);
void Afficher(int * tab);

#endif
