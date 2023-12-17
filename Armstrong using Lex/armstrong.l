%{
#include<string.h>
#include<math.h>
void check(char *);
%}
%%
[0-9]+ check(yytext);
%%

void main() {
        extern FILE * yyin;
        yyin = fopen("num", "r");
        yylex();
}

int yywrap() {
        return 1;
}
void check(char * a) {
        int num = 0, copy, rem, sum = 0;
        copy = atoi(a);
        num = copy;
        while (copy != 0) {
                rem = copy % 10;
                
                sum = sum + (rem * rem * rem);
                
                copy = copy / 10;
               
        }
        if (sum == num)
                printf("%d is armstrong \n", num);
        else
                printf("%d is not armstrong \n", num);
}
