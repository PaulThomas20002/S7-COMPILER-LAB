%{
#include<stdio.h>
%}

%%
#.* { printf("\n %s \t Preprocessor directive", yytext); }
"//".*\n { printf("\n"); }
"/*".\n { printf("\n "); }
"void"|"int"|"char"|"if"|"else"|"for"|"do"|"while"|"switch"|"case"|"break"|"return"|"main" { printf("\n %s \t keyword", yytext); }
[a-zA-Z][a-zA-Z0-9]* { printf("\n %s \t Identifier \t", yytext); }
"("|")"|";"|","|"}"|"{"|"\"" { printf("\n %s \t Punctuation\t", yytext); }
[0-9]+ { printf("\n %s Literals\t", yytext); }
"+"|"-"|"*"|"/"|"="|"<="|"=="|">="|"<"|">"|"=" { printf("\n %s \t Operator\t", yytext); }
[ \t\n] { /* skip spaces and tabs */ }
%%

void main() {
        FILE * f;
        f = fopen("input.c", "r");
        yyin = f;
        if (!yyin) {
                printf("could not open the file");
                exit(0);
        } else
                printf("File opened\n");
        yylex();
}
int yywrap() {
        return 1;
}
