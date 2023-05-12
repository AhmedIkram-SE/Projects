#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#include <dos.h>
#define WORDS 10
#define WORDLEN 40
#define CHANCE 6

bool srand_called = false;

int i_rnd(int i) {
    if (!srand_called)
    {
        srand(time(NULL) << 10);
        srand_called = true;
    }
    return rand() % i;
}

void printBody(int mistakes, char* body)
{
    printf("\tMistakes :%d\n", mistakes);
    switch(mistakes)
    {
        case 6: body[6] = '\\'; break;
        case 5: body[5] = '/'; break;
        case 4: body[4] = '\\'; break;
        case 3: body[3] = '|'; break;
        case 2: body[2] = '/'; break;
        case 1: body[1] = ')', body[0] = '('; break;
        default: break;

    }

        printf("\t ___\n"
       "\t|         |\n"
       "\t|        %c %c\n"
       "\t|        %c%c%c\n"
       "\t|        %c %c\n"
       "\t|             \n"
       "\t|             ", body[0], body[1], body[2],
       body[3], body[4], body[5], body[6]);
}

void printWord(char* guess, int length)
{
    printf("\t");
    for (i = 0; i < length; ++i)
    {
        printf("%c ", guess[i]);
    }
    printf("\n\n");
}

int main()
{	system("color B0");
	printf("\n\t\t\t\t\t***\tProgramming Project\t***\n\n\t\t\t\t\t***\t     Group A\t\t***\n\n\t\t\t\t\t***\t  Group Members\t\t***\n\n\n\t\t\t\t\t->SP22-BSE-062 (AHMAD IKRAM)<-\n\t\t\t\t\t->SP22-BSE-099 (MUHAMMAD HARIS BIN NAWAZ)<-\n\t\t\t\t\t->SP22-BSE-117 (ALI HUSSNAIN)<-\n");
    int i,j=500;
	for(i=250;i<=500;i+=50)
	{if(i==500)
		{j=1000;}	
	Beep(i,j);}
    
    printf("\n\n\n\t\t\t\t\t\tTHE HANGMAN!!!!!!");
    Beep(700,1000);
    printf("\n\n\t Be aware you can be hanged!!.");
    Beep(400,500);
    printf("\n\n\t Rules are: ");
     Beep(400,500);
    printf("\n\n\t - 1: Maximum 6 mistakes are allowed.");
     Beep(400,500);
    printf("\n\n\t - 2: All alphabet are in lower case.");
     Beep(400,500);
    printf("\n\n\t - 3: All words are name of very popular Websites. eg. Google");
     Beep(400,1000);
    printf("\n\n\t - 4: If you enjoy continue, otherwise close it.");

    printf("\n\n\t Syntax : Alphabet");
    printf("\n\n\t Example : a \n\n");

char values[WORDS][WORDLEN] = {"netflix","google","yahoo","amazon","autodesk","bing","youtube","facebook","linkdn","adobe"};
char *body = malloc(CHANCE+1);

int id = i_rnd(WORDS);
char *word = values[id];
int len = strlen(word);
char *guessed = malloc(len);
char falseWord[CHANCE];
char guess;
bool found;
char* win;
int mistakes = 0;

memset(body, ' ', CHANCE+1);
memset(guessed, '_', len);


do {

found = false;
printf("\n\n");
printBody(mistakes, body);
printf("\n\n");
printf("\tFalse Letters : ");
if(mistakes == 0) printf("None\n");
    for (int i = 0; i < mistakes; ++i)
{
        printf("%c", falseWord[i]);
}
printf("\n\n");
printWord(guessed, len);
printf("\tGive me an alphabet in lower case : ");
do {scanf("%c",&guess);
 Beep(400,500);
} while ( getchar() != '\n' );
for (int i = 0; i < len; ++i)
{
    if(word[i] == guess)
    {
    found = true;
   // system("color F0");
	guessed[i] = guess;
    }
}
if(!found)
    {
      Beep(700,700);
	  falseWord[mistakes] = guess;
      mistakes += 1;
   	 /* if(mistakes==1)
		 system("color 90");	
	  if(mistakes==2)	 	
		system("color A0");
      if(mistakes==3)	 	
		system("color B0");
	  if(mistakes==4)
		system("color D0");
	  if(mistakes==5)
		system("color E0");
	  if(mistakes==6)
		system("color C0");*/
	}	
    win = strchr(guessed, '_');
}while(mistakes < CHANCE && win != NULL);

if(win == NULL) {
printf("\n");
printWord(guessed, len);
    Beep(150,500);//Syntax of Beep is,Beep(Frequency,Duration(miliseconds));1000miliseconds=1 second
    Beep(200,500);

    printf("\n\tCongrats! You were not hanged, the correct word is  : %s\n\n", word);

    int i,j=500;
	for(i=250;i<=600;i+=50)
	{if(i==600)
		{j=1000;}	
	Beep(i,j);}
	
} else
    {
        printf("\n");
        printBody(mistakes, body);
    Beep(500,500);
    Beep(400,500);

    printf("\n\n\tYou are HANGED!! Better try next time. Word was ''%s''\n\n", word);
	int i,j=500;
	for(i=350;i>=100;i-=50)
	{if(i==100)
		{j=1500;}	
	Beep(i,j);}
  
    }

free(body);
free(word);
free(guessed);


return 0;
}
