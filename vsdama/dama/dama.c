#include <stdio.h>
#include <stdlib.h>
//Kamen na [0] pozici je nemyslitelny
int i, t = 1, k=0;

typedef struct{
	int x;
	int y;
	int barva;
	int exist;
}kamen;

void innit(kamen kameny[]);
void print(kamen kameny[]);
void adresa(char *ctah, int *itah);
void odstranit(char *pole, char znak);
void presun(kamen kameny[], char *ctah);
int indexk(kamen kameny[], int x, int y);
void vypis(kamen kameny[]) {
	int x;
	scanf("%d", &x);
	printf("%d %d %d %d %d", x, kameny[x].x, kameny[x].y, kameny[x].barva, kameny[x].exist);
}

int main()
{
	char ctah[5];
	kamen kameny[24];
	innit(kameny);
	while(1) {
		print(kameny);
		printf("\n");
		fgets(ctah, 5, stdin);
		presun(kameny, ctah);
		printf("\n");
		getchar();
		system("CLS"); 
	}
	return 0;
}
int indexk(kamen kameny[], int x, int y) {
	for (i = 1; i <= 24; i++) {
		if (kameny[i].x == x &&
			kameny[i].y == y) {
			return i;
		}
	}
	return 0;
}
void print(kamen kameny[]) {
	int x, y;
	for (y = 8; y > 0; y--) {
		for (x = 1; x <= 8; x++) {
			k = indexk(kameny, x, y);
			if (k == 0) {
				printf("0 ");
			}
			else {
				printf("%d ", kameny[k].barva);
			}
		}
		printf("\n");
	}
}
void innit(kamen kameny[]) {
	for (i = 1; i <= 24; i++) {
		kameny[i].exist = 1;
		if (i <= 12) {
			kameny[i].barva = 1;
			if (i <= 4) {
				kameny[i].x = 2 * i - 1;
				kameny[i].y = 1;
			}
			if (i >= 5 && i <= 8) {
				kameny[i].x = 2 * i - 8;
				kameny[i].y = 2;
			}
			if (i >= 9) {
				kameny[i].x = 2 * i - 17;
				kameny[i].y = 3;
			}
		}
		else {
			kameny[i].barva = 2;
			if (i <= 16) {
				kameny[i].x = 2 * i - 24;
				kameny[i].y = 6;
			}
			if (i >= 17 && i <= 20) {
				kameny[i].x = 2 * i - 33;
				kameny[i].y = 7;
			}
			if (i >= 21) {
				kameny[i].x = 2 * i - 40;
				kameny[i].y = 8;
			}
		}
	}
}
void presun(kamen kameny[], char* ctah) {
	int itah[4];
	adresa(ctah, itah);
	printf("%d %d %d %d", itah[0], itah[1], itah[2], itah[3]);
	k = indexk(kameny,itah[0], itah[1]);
	if (k != 0) {
		kameny[k].x = itah[2];
		kameny[k].y = itah[3];
	}
}
void adresa(char* ctah, int* itah) {

	odstranit(ctah, ' ');

	for (i = 0; ctah[i] != '\0'; i++) {
		if (ctah[i] >= 'a' && ctah[i] <= 'h') {
			itah[i] = ctah[i] - 48;
		}
		else {
			itah[i] = ctah[i];
		}
		itah[i] = itah[i] - 48;
	}
}
void odstranit(char* pole, char znak) { //funkce z úkolů
	int i, x;
	for (i = 0; pole[i] != '\0'; i++) {
		if (pole[i] == znak) {
			for (x = i; pole[x] != '\0'; x++) {
				pole[x] = pole[x + 1];
			}
			i--;
		}
	}
}
