#include "Outilcpy.h"
#include "CreaCarte.h"

int mat[T][T];
int carte[T][T];


void creerRoute5()
{
//Creation des routes
	int i;
	int j;

	
//routes verticales de gauche a  droite
	for(i=2;i<=5;i++)
	{	
		j = 1;
		mat[i][j]=1;
	}
	for(i=8;i<=10;i++)
	{
		j= 1;
		mat[i][j]=1;
	}		
	for(i=0;i<=9;i++)
	{
		j = 4;
		mat[i][j]=1;
	}
	for(i=4;i<=6;i++)
	{
		j = 6;
		mat[i][j]=1;
	}
	for(i=1;i<=4;i++)
	{
		j=8;
		mat[i][j]=1;
	}
	for(i=6;i<=9;i++)
	{
		j=9;
		mat[i][j]=1;
	}
	
//routes horizontales de haut en bas

	for(j=5;j<=7;j++)
	{
		i=1;
		mat[i][j] = 1;
	}
	mat[2][0]=1;
	for(j=9;j<=10;j++)
	{
		i=2;
		mat[i][j] = 1;
	}
	mat[4][7]=1;
	for(j=1;j<=3;j++)
	{
		i=5;
		mat[i][j] = 1;
	}
	mat[6][5]=1;
	mat[6][10]=1;
	for(j=2;j<=3;j++)
	{
		i=8;
		mat[i][j] = 1;
	}
	for(j=4;j<=9;j++)
	{
		i=9;
		mat[i][j] = 1;
	}
}


void carte5()
{
	initialisation(mat);
	initialisation(carte);

	creerRoute5();
	
	voisinRoute();
	placerBatiment();
}
