%{
#include<stdio.h>
#include<stdlib.h>
int flag=0;
%}

%%
[a-zA-Z0-9_]+@[a-zA-Z0-9_]+[.][a-zA-Z0-9_]+ { printf("%s is Valid Email ID", yytext); flag=1; }
%%

void main(){
yylex();
if(flag==1)
  printf("Accepted");
else
  printf("Not Accepted");
}
int yywrap(){
return 1;
} 
