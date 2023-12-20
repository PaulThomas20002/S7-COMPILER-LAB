#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i = 1, j = 0, tmpch = 90;
char str[100], left[15], right[15];
void findopr();
void explore();
void fleft(int);
void fright(int);
struct exp {
        int pos;
        char op;
}k[15];

void main() {
        printf("Input :");
        scanf("%s", str);
        printf("The intermediate code:\n");
        findopr();
        explore();
}
void findopr() {
        for (i = 0; str[i] != '\0'; i++)
                if (str[i] == '/') {
                        k[j].pos = i;
                        k[j++].op = '/';
                }
        for (i = 0; str[i] != '\0'; i++)
                if (str[i] == '*') {
                        k[j].pos = i;
                        k[j++].op = '*';
                }
        for (i = 0; str[i] != '\0'; i++)
                if (str[i] == '+') {
                        k[j].pos = i;
                        k[j++].op = '+';
                }
        for (i = 0; str[i] != '\0'; i++)
                if (str[i] == '-') {
                        k[j].pos = i;
                        k[j++].op = '-';
                }
}

void explore() {
        i = 0;
        while (i < j) {
                fleft(k[i].pos);
                fright(k[i].pos);
                str[k[i].pos] = tmpch--;
                printf("\t%c = %s%c%s\t\t", str[k[i].pos], left, k[i].op, right);
                printf("\n");
                i++;
        }
        fleft(1);
        fright(1);
        printf("\t%s = %s\n", left, right);
}

void fleft(int x) {
        x--;
        strcpy(left, "");
        while (str[x] != '+' && str[x] != '-' && str[x] != '*' && str[x] != '/' && str[x] != '=' && str[x] != '\0') {
                if (str[x] != '$') {
                        strncat(left, & str[x], 1);
                        str[x] = '$';
                }
                x--;
        }
}

void fright(int x) {
        x++;
        strcpy(right, "");
        while (str[x] != '+' && str[x] != '-' && str[x] != '*' && str[x] != '/' && str[x] != '\0' && str[x] != '=') {
                if (str[x] != '$') {
                        strncat(right, & str[x], 1);
                        str[x] = '$';
                }
                x++;
        }
}
