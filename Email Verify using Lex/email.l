%{
#include<stdio.h>
#include<stdlib.h>
int flag=0;
%}

%%
[a-z . 0-9]+@[a-z]+".com"|".in" { flag=1; }
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
