#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

//check is Delimiter
bool isDelimiter(char ch){
    if(ch == ' ' || ch == '+' || ch == '-'|| ch == ',' || ch == ';'|| ch == ':' ||
     ch == '>'|| ch == '<' || ch == '{' || ch == '}' || ch == '[' || ch == ']' ||
     ch == '^'){
        return true;
     }
     return false;
}
//check is Operator
bool isOperator(char ch){
    if(ch == '+' || ch == '-'|| ch == '*' || ch == '/'|| ch == '%'){
        return true;
     }
     return false;
}
//check is valid or not
bool validIdentifier(char* str){
    if(str[0]=='0'||str[0]=='1'||str[0]=='2'||str[0]=='3'||str[0]=='4'||str[0]=='5'
       ||str[0]=='6'||str[0]=='7'||str[0]=='8'||str[0]=='9'
       ||isDelimiter(str[0])==true)
       {
            return false;
       }
}
//check keywords
bool isKeyword(char* str){
    if(!strcmp(str,"if") || !strcmp(str,"else") || !strcmp(str,"break") || !strcmp(str,"case")
       || !strcmp(str,"char") || !strcmp(str,"const") || !strcmp(str,"continue") || !strcmp(str,"default"))
       {
           return true;
       }
       return false;
}

int main()
{
    char str[100];
    printf("Enter the line of code: \n");
    scanf("%[^\n]", str);

    bool deli = isDelimiter('.');
    printf("%d\n", deli);

    bool operat = isOperator('*');
    printf("%d\n", operat);

    bool valid = validIdentifier(&str);
    printf("%d\n", valid);

    bool keywd = isKeyword(&str);
    printf("%d\n", keywd);

    return 0;
}

//TASK for the Next Class ==> Complete the code with proper understanding

