#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define S 8 //sachovnice bude dle ceskych norem 

int x,y,i,t=1;

void start(int *pole);
void print(int pole[][S]);
void getadress(char *ctah,int *itah);
void odstranit(char *pole, char znak);
void presun(int pole[][S], int *itah);
int check(int pole[][S], int *itah);
void prepnitah();

int main()
{
	char ctah[5];
	int pole[][S] = { //1 - Bile, 2 - Cerne
	{0,1,0,1,0,1,0,1,},	
	{1,0,1,0,1,0,1,0,},	
	{0,1,0,1,0,1,0,1,},
	{0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,},
	{2,0,2,0,2,0,2,0,},
	{0,2,0,2,0,2,0,2,},
	{2,0,2,0,2,0,2,0,},
	},
	itah[4];
	
	do
	{
		print(pole);
		printf("Zadejte tah: ");
		gets(ctah);
		getadress(ctah,itah);
		if(check(pole,itah)==1)
			printf("Neplatny tah");
		for(i=0;i<4;i++)		
			printf("%d\n",itah[i]);
		presun(pole,itah); 
		prepnitah();
		system("pause");
		system("CLS");		
	}while(1);

	
	system("pause");
	return 0;
}

int check(int pole[][S], int *itah){
	int p=0;
	
	if(sqrt(2)!=sqrt((pow(itah[3]-itah[1],2)+pow(itah[0]-itah[2],2)))&&sqrt(8)!=sqrt((pow(itah[3]-itah[1],2)+pow(itah[0]-itah[2],2)))) //vypocet velikosti vektoru. to jste neèekali co ? :D
		return 1;
	else
		if(itah[3]>=itah[1])
			return 1;
		else
			return 0;
	
	for(x=0;x<S;x++){
		for(y=0;y<S;y++){
			if(pole[x+2][y+(-2)]==0||pole[x-2][y+(-2)]==0)
				if(t==1)
					if(pole[x+1][y+(-1)]==2||pole[x-1][y+(-1)]==2)
						p=1;	
				else 
					if(pole[x+1][y+(-1)]==1||pole[x-1][y+(-1)]==1)
						p=1;
		}
	}
}
void prepnitah(){
	switch(t){		
		case 1: t==2; break;
		case 2: t==1; break;
	}
}
void presun(int pole[][S], int *itah){
	pole[itah[3]][itah[2]]= pole[itah[1]][itah[0]];
	pole[itah[1]][itah[0]]= 0;
}

void getadress(char *ctah,int *itah){
	
	odstranit(ctah,' ');
	
	for(i=0;ctah[i]!='\0';i++){
		if(ctah[i]>='a' && ctah[i]<='h'){
			itah[i] = ctah[i]-49;
		}
		else{
			itah[i]=ctah[i];
		}
		itah[i]=itah[i]-48;
	}	
	itah[1]=-itah[1]+8;//lineární rovnice f(x)=-x+8
	itah[3]=-itah[3]+8;
}

void print(int pole[][S]){
	for(x=0;x<S;x++){
		for(y=0;y<S;y++){
			printf("%d ",pole[x][y]);
		}
		printf("\n");
	}

}

void odstranit(char *pole, char znak){ //funkce z úkolù
	int i,x;
	for(i=0;pole[i]!='\0';i++)
	{
		if(pole[i]==znak)
		{
			for(x=i;pole[x]!='\0';x++)
			{
				pole[x]=pole[x+1];
			}
			i--;
		}
	}
}
