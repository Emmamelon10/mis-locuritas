/*
Tablero: 20 altura x 10 ancho
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<unistd.h>

int piece,tablero[10][20],y=4,x,j,teclas,a;

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
	int a,b;
	for(a=0;a<20;a++)
	{
		printf("|");
		for(b=0;b<10;b++)
		{
			tablero[b][a]=32;
			switch(piece)
			{
				case 0:
					tablero[y][x]=219;
					tablero[y][x+1]=219;
					tablero[y][x+2]=219;
					tablero[y][x+3]=219;
			 		break;
				case 1:
					tablero[y][x]=219;
					tablero[y+1][x]=219;
					tablero[y+1][x+1]=219;
					tablero[y+2][x+1]=219;
					break;
				case 2:
					tablero[y][x]=219;
					tablero[y][x+1]=219;
					tablero[y][x+2]=219;
					tablero[y+1][x+2]=219;
					break;
				case 3:
					tablero[y][x]=219;
					tablero[y+1][x]=219;
					tablero[y+2][x]=219;
					tablero[y+1][x+1]=219;
					break;
				case 4:
					tablero[y+1][x]=219;
					tablero[y+2][x]=219;
					tablero[y][x+1]=219;
					tablero[y+1][x+1]=219;
					break;
				case 5:
					tablero[y+1][x]=219;
					tablero[y+1][x+1]=219;
					tablero[y+1][x+2]=219;
					tablero[y][x+2]=219;
					break;
				case 6:
					tablero[y][x]=219;
					tablero[y+1][x]=219;
					tablero[y+1][x+1]=219;
					tablero[y][x+1]=219;
					break;
					
					
				case 7:
					tablero[y][x]=219;
					tablero[y+1][x]=219;
					tablero[y+2][x]=219;
					tablero[y+3][x]=219;
					break;
				case 8:
					tablero[y][x]=219;
					tablero[y][x+1]=219;
					tablero[y+1][x+1]=219;
					tablero[y+1][x+2]=219;
					break;
				case 9:
					tablero[y][x]=219;
					tablero[y+1][x]=219;
					tablero[y+2][x]=219;
					tablero[y+2][x+1]=219;
					break;
					
			}
			printf("%c",tablero[b][a]);
			printf("%c",tablero[b][a]);
		}
		printf("|\n");
	}
	printf("+--------------------+\n");
}

void pieza()
{
	srand(time(NULL));
	piece=rand()%6;
	y=4;
	x=0;
}

main()
{
	for(a=0;a<10;a++)
	{
		tablero[a][20]=7;
	}
	pieza();
	while(teclas!=27)
	{
			j++;
			if(j%4==0)
			{
				x++;	
			}
		system("cls");
		printf("\n%d\n",piece);
		if(kbhit())
		{
			teclas=getch();
			switch(teclas)
			{
				case 80:
					x++;
					break;
				case 77:
					y++;
					break;
					
				case 75:
					y--;
					break;
				case 122:
					piece+=7;
					if(piece==15||piece==14)
					{
						piece-=14;
					}
					break;
			}
			printf("%d",teclas);
		}
		imprimir();
	}
}
