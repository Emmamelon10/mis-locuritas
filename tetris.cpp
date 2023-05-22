/*
Tablero: 20 altura x 10 ancho
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>

int piece,tablero[10][20],y=4,x=0;

void clean()
{
	int hor,ver;
	for(hor=0;hor<20;hor++)
	{
		for(ver=0;ver<10;ver++)
		{
			tablero[hor][ver]=32;
		}
	}
}

void imprimir()
{
	int hor,ver;
	printf("\n\n %d\n",x);
	for(hor=0;hor<20;hor++)
	{
		printf("|");
		for(ver=0;ver<10;ver++)
		{
			tablero[hor][ver]=32;		
			switch(piece)
			{
				case 0:
					tablero[x][y]=219;
					tablero[x+1][y]=219;
					tablero[x+2][y]=219;
					tablero[x+3][y]=219;
					break;
				case 1:
					tablero[x][y]=219;
					tablero[x][y+1]=219;
					tablero[x+1][y+1]=219;
					tablero[x+1][y+2]=219;
					break;
				case 2:
					tablero[x][y]=219;
					tablero[x+1][y]=219;
					tablero[x+2][y]=219;
					tablero[x+2][y+1]=219;
					break;
				case 3:
					tablero[x][y]=219;
					tablero[x][y+1]=219;
					tablero[x][y+2]=219;
					tablero[x+1][y+1]=219;
					break;
				case 4:
					tablero[x][y+1]=219;
					tablero[x][y+2]=219;
					tablero[x+1][y]=219;
					tablero[x+1][y+1]=219;
					break;
				case 5:
					tablero[x][y+1]=219;
					tablero[x+1][y+1]=219;
					tablero[x+2][y+1]=219;
					tablero[x+2][y]=219;
					break;
				case 6:
					tablero[x][y]=219;
					tablero[x][y+1]=219;
					tablero[x+1][y+1]=219;
					tablero[x+1][y]=219;
					break;
			}
			if(x>30)
			{
				x=x-32;
			}
			printf("%c%c",tablero[hor][ver],tablero[hor][ver]);
		}
		printf("|\n");
	}
}

void pieza()
{
	srand(time(NULL));
	piece=rand()%6;
}

main()
{
	clean();
	pieza();
	imprimir();
	printf("%d\n\n",piece);
	while()
}
