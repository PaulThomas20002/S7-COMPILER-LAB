#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	FILE *input, *output;
	int l=1;
	int t=0;
	int j=0;
	int i,flag=0;
	char ch,str[20];
	input = fopen("input.txt","r");
	output = fopen("output.txt","w");
	char keyword[30][30] = {"include","void","return","for",".h","int","main","if","else","do","while", "stdio"};
	fprintf(output,"Line no. \t Token no. \t\t Token \t\t Lexeme\n\n");

	while(!feof(input)){
		i=0;
		flag=0;
		ch=fgetc(input);

		if((ch == '/')){
			if(ch=getc(input)=='/'){
				while(ch!='\n'){
					ch=getc(input);
				}
			}
			else{
				char c = '/';
				fprintf(output,"%7d\t\t %7d\t\t Operator\t\t %7c\n",l,t,c);
				ungetc(ch, input);
			}
		}
		else if( ch=='+' || ch== '-' || ch=='*' || ch == '=' ){
			fprintf(output,"%7d\t\t %7d\t\t Operator\t\t %7c\n",l,t,ch);
			t++;
		}

		else if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' || ch=='@' ||ch=='!' || ch=='%'){

			fprintf(output,"%7d\t\t %7d\t\t Punctuations\t %7c\n",l,t,ch);
			t++;
		}

		else if(isdigit(ch)){
			fprintf(output,"%7d\t\t %7d\t\t Literals\t\t %7c\n",l,t,ch);
			t++;
		}

		else if(isalpha(ch)){
			str[i]=ch;
			i++;
			ch=fgetc(input);

			while(isalnum(ch) && ch!=' '){
				str[i]=ch;
				i++;
				ch=fgetc(input);
			}
			str[i]='\0';
			
			for(j=0;j<=12;j++){
				if(strcmp(str, keyword[j])==0){
					flag=1;
					break;
				}
			}
			if(flag==1){
				fprintf(output,"%7d\t\t %7d\t\t Keyword\t\t %7s\n",l,t,str);
				t++;
			}
			else{
				fprintf(output,"%7d\t\t %7d\t\t Identifier\t\t %7s\n",l,t,str);
				t++;
				
			}
			flag = 0;
		}

		else if(ch=='\n'){
			l++;
		}
	}
	fclose(input);
	fclose(output);
	return 0;
	}
