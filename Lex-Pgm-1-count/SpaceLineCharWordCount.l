%{
#include<stdio.h>
int wc=0, lc=0, cc=0;
%}

%%
[\n] { lc++; cc+=yyleng;}
[^\t\n ]+ { wc++;  cc+=yyleng;}
%%

void main() {
        printf("Enter the input:\n");
        yylex();
        printf("\nThe number of lines=%d\n", lc);
        printf("The number of words=%d\n", wc);
        printf("The number of characters are=%d\n", cc);
}
int yywrap() {
        return 1;
}
