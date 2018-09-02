#include <stdio.h>
#include <stdlib.h>
#include "Strukture.h"


int Sirina;
int Visina;
SegmentZmije Zmija[100];
int DuzinaZmije = 3;
char izgubio = 'f';
Poen poen;
int Score = 0;
int Brzina;

void Stampanje(char Polje[Visina][Sirina])
{
	system("cls");
	int x;
	int y;
	printf("Poeni: %d poena\n",Score);
	for(x = 0;x<Visina;x++)
	{
			printf("%.*s\n", Sirina, Polje + x);
		
	}
}

void UnosXY()
{
	printf("!!! DIMENZIJE MORAJU BITI VECE ILI JEDNAKE 10X10 !!!\n\n");
	printf("Unesite sirinu polja\n");
	scanf("%d",&Sirina);
	printf("Unesite visinu polja\n");
	scanf("%d",&Visina);
	if(Sirina<10||Visina<10)
	{
		UnosXY();
	}
	printf("Unesite brzinu igre:\nnajteze: 50\nnajlakse: 1000\n");
	scanf("%d",&Brzina);
	check:
	if(Brzina >1000 || Brzina<50){
		printf("Uneti pogresni parametri, ponovite unos: ");
		scanf("%d",&Brzina);
		goto check;
	}
	system("cls");
	printf("Igra pocinje za: 3");
	Sleep(1000);
	system("cls");
	printf("Igra pocinje za: 2");
	Sleep(1000);
	system("cls");
	printf("Igra pocinje za: 1");
	Sleep(1000);
}

void PopunjavanjePolja(char Polje[Visina][Sirina])
{
	int x;
	int y;
	for(x = 0;x<Visina;x++)
	{
		for(y = 0;y<Sirina;y++)
		{
			Polje[x][y] = '.';
		}
		
	}
	for(x = 0;x<DuzinaZmije;x++)
	{
		Polje[Zmija[x].Y][Zmija[x].X] = '0';
	}
	Polje[poen.Y][poen.X] = '*';
}

void HvatanjeUnosa()
{
	if(kbhit())
	{
	switch(getch()) {
    case 'w':    // key up
    if(Zmija[0].KretanjeY != 1)
    {
        Zmija[0].KretanjeX = 0;
		Zmija[0].KretanjeY = -1;
	}
		break;
    case 's':    // key down
    if(Zmija[0].KretanjeY != -1)
    {
    	Zmija[0].KretanjeX = 0;
		Zmija[0].KretanjeY = 1;
	}
        break;
    case 'd':    // key right
    if(Zmija[0].KretanjeX != -1)
    {
    	Zmija[0].KretanjeX = 1;
		Zmija[0].KretanjeY = 0;
	}
		break;
    case 'a':    // key left
    if(Zmija[0].KretanjeX != 1)
    {
    	Zmija[0].KretanjeX = -1;
		Zmija[0].KretanjeY = 0;
	}
	    break;
	default:
		break;
}
}
}
void GenerisanjePoena(char Polje[Visina][Sirina])
{
	int posX;
	int posY;
	int brojac = 0;
	char uspeh = 't';
	int i,j;
	do
	{
		uspeh = 't';
		posX = (rand() % Sirina);
		posY = (rand() % Visina);
		for(i=0;i<DuzinaZmije;i++)
		{
			if(Zmija[i].X == posX && Zmija[i].Y == posY)
				uspeh = 'f';
			
		}
		brojac++;
	}while(brojac < 100 || uspeh=='f');
	if(uspeh == 'f')
	{
		for(i = 0;i<Visina;i++)
		{
			for(j = 0;j<Sirina;j++)
			{
				if(Polje[i][j]=='.')
				{
					poen.X = j;
					poen.Y = i;
				}
			}
		}
	}
	else
	{
	poen.X = posX;
	poen.Y = posY;
	}
}

void Kretanje()
{
	int x;
	
		for(x = DuzinaZmije-1;x>0;x--)
	{
		Zmija[x] = Zmija[x-1];
	}
	
	if((Zmija[0].X + Zmija[0].KretanjeX) >= Sirina)
		Zmija[0].X = 0;
	else if((Zmija[0].X + Zmija[0].KretanjeX)<0)
		Zmija[0].X = Sirina-1;
	else
		Zmija[0].X = Zmija[0].X + Zmija[0].KretanjeX;
	if((Zmija[0].Y + Zmija[0].KretanjeY)<0)
		Zmija[0].Y = Visina-1;
	else if((Zmija[0].Y + Zmija[0].KretanjeY)>=Visina)
		Zmija[0].Y = 0;
	else
		Zmija[0].Y = Zmija[0].Y + Zmija[0].KretanjeY;
}


void Provere(char Polje[Visina][Sirina])
{
	if(Zmija[0].X == poen.X && Zmija[0].Y == poen.Y)
	{
		Score += 10;
		DuzinaZmije += 1;
		Zmija[DuzinaZmije-1].X = Zmija[1].X;
		Zmija[DuzinaZmije-1].Y = Zmija[1].Y;
		GenerisanjePoena(Polje);
	}
	int i;
	for (i=1;i<DuzinaZmije;i++)
	{
		if((Zmija[i].X == Zmija[0].X) &&(Zmija[i].Y==Zmija[0].Y))
		{
			izgubio = 't';
		}
	}
}

void UltraAwesomeEndGameCinematic(char Polje[Visina][Sirina])
{

	int x,i;
	for(i=0;i<3;i++)
	{	
	Sleep(500);
	system("cls");
	Sleep(500);
	printf("Poeni: %d poena\n",Score);
	for(x = 0;x<Visina;x++)
	{		
			printf("%.*s\n", Sirina, Polje + x);
		
	}
	}
	for(i=Visina;i>=0;i--)
	{
		Sleep(200);
		system("cls");
		printf("Poeni: %d poena\n",Score);
		for(x = 0;x<i;x++)
	{
			printf("%.*s\n", Sirina, Polje + x);
		
	}
	}
	system("cls");
	printf("\n\n");
	printf("\t Igra je gotova, osvojili ste ukupno: %d poena\n",Score);
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { }
	fgetc(stdin);

	
}

int main()
{
	
	UnosXY();
	int i;
	char Polje[Visina][Sirina];
 
	
	Zmija[0].X = Sirina/2;
	Zmija[0].Y = Visina/2;
	Zmija[0].KretanjeX = 1;
	Zmija[0].KretanjeY = 0;
	GenerisanjePoena(Polje);
	while(izgubio == 'f')
	{
		Sleep(Brzina);
		HvatanjeUnosa();
		Kretanje();
		Provere(Polje);
		PopunjavanjePolja(Polje);
		Stampanje(Polje);
	}
	
	UltraAwesomeEndGameCinematic(Polje);
	
	
}


