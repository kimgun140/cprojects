#include<stdio.h>
#define MSG "I am symbolic sting constant."
#define MAXLENGTH 81
#define SLEN 40
#define LIM 5

int main(void){

// char words[MAXLENGTH] = "I am a string in an array";
// const char * pt1 = "Something is point at me";
// puts("Here are som stings:");
// puts(MSG);
// puts(words);
// puts(pt1);
// words[8] = 'p';
// puts(words);

// printf("%s,%p,%c\n","We","are",*"space farers");

const char *mytalents[LIM] = {
    "Adding numbers swiftly",
    "Multiplying accurately", " Stashing data",
    "Following instructions to the letter",
    "Understanding th C language"
};
char yourtalents[LIM][SLEN] = {
    "Walking in a straight line",
    "Sleeping", "Watching television",
    "Mailing letters", "Reading email"
};
int i;

puts("Let's compare talents.");
printf("%-36s %-25s\n", "My talents", "Your Talents");
for (i =0; i<LIM; i++)
    printf("%-36s %-25s\n",mytalents[i],yourtalents[i]);
printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",sizeof(mytalents),sizeof(yourtalents) );




return 0;
}