#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
	char fornavn[30];
	char efternavn[30];
	unsigned int alder;
};

void indtast(struct data *dt); //funktions prototype
void udskriv(struct data *dt);
void gem(struct data *dt);
void hent(struct data *dt);

int main()
{
	char choice[5];
	int ch;

	struct data Dat; //vi opretter Dat af typen struct data

	do
	{
		printf("Indtast data : 1 \n");
		printf("Vis data     : 2 \n");
		printf("Gem data     : 3 \n");
		printf("Hent data    : 4 \n");
		printf("Afslut       : 5 \n");
		printf("Indtast tal for operation :");
		gets(choice);
		ch=atoi(choice);

		switch(ch)
		{
			case 1: 	indtast(&Dat);
				break;
			case 2: 	udskriv(&Dat);
				break;
			case 3:	gem(&Dat);
				break;
			case 4: 	hent(&Dat);
		}
	}while(ch!=5);


	return 0;
}

void indtast(struct data *dt)
{
	char tmp[5];

	if(strlen(dt->fornavn)>0&&strlen(dt->efternavn)>0)
	{
		printf("Data allerede indtastet\n");
		printf("Vil du overskrive ? tast j/n + <enter>");
		gets(tmp);
		if(strcmp("n",tmp)==0)
			return;
	}

	printf("Indtast fornavn ");
	gets(dt->fornavn);
	printf("Indtast efternavn ");
	gets(dt->efternavn);
	printf("Indtast alder ");
	gets(tmp);
	dt->alder=atoi(tmp);
}

void udskriv(struct data *dt)
{
	if(strlen(dt->fornavn)==0||strlen(dt->efternavn)==0)
	{
		printf("Ingen data at vise\n");
		return;
	}
	printf("Fornavn   : %s\n",dt->fornavn);
	printf("Efternavn : %s\n",dt->efternavn);
	printf("Alder     : %d\n",dt->alder);
}

void gem(struct data *dt)
{
	if(strlen(dt->fornavn)==0||strlen(dt->efternavn)==0)
	{
		printf("Ingen data at gemme\n");
		return;
	}
	FILE *fp=fopen("data.bin","wb"); //fil åbnes som write binær (wb)
	if(fp)
	{
		fwrite(dt,sizeof(struct data),1,fp);
		fclose(fp);
		printf("Data gemt\n");
	}
	else
		printf("Data blev ikke gemt !\n");
}

void hent(struct data *dt)
{
	FILE *fp=fopen("data.bin","rb"); //fil åbnes som read binær (rb)
	if(fp)
	{
		fread(dt,sizeof(struct data),1,fp);
		fclose(fp);
	printf("Data hentet\n");
	}
	else
		printf("Data blev ikke hentet !\n");
}
