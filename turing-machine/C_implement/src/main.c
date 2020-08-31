#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

/*Main table,     1st index,        1st state       Steps count*/
char TABLE[SIZE]; int INDEX=SIZE/2; char STATE='A'; unsigned long int STEPS=0;

              /*state, content*/
char transition(char s,int c);

void main(int argc,char **argv){

    TABLE[INDEX]='0';
    char new_state=transition(STATE,TABLE[INDEX]);
    while (1){
        new_state=transition(new_state,TABLE[INDEX]);
        if (new_state=='H') {
            printf("%li %c ",STEPS,new_state);
            for(int i=0;i<SIZE;i++) printf("%c",TABLE[i]);
                break; } }
    putchar('\n');
    return;}


char transition(char s,int c){
    /*new state, print*/
    char ns; char p; int move; STEPS++;
    switch(s) {
        case 'A':if (c=='0') {ns='B'; move=1; p='1';}
            else if (c=='1') {ns='H'; move=1; p='1';} break;

        case 'B':if (c=='0') {ns='C'; move=1; p='0';}
            else if (c=='1') {ns='B'; move=1; p='1';} break;

        case 'C':if (c=='0') {ns='C'; move=-1; p='1';}
            else if (c=='1') {ns='A'; move=-1; p='1';} break; }

    TABLE[INDEX]=p; INDEX+=move;
    if (TABLE[INDEX]==0){TABLE[INDEX]='0';}
    return ns; }