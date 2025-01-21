#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

//check is Delimiter
bool isDelimiter(char ch){
    if(ch == ' ' || ch == ',' || ch == ';' || ch == ':' || ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
    ch == '[' || ch == ']' || ch == '"' || ch == '#' ||ch == '+' || ch == '-'|| ch== '*' || ch== '/'|| ch== '%'||
    ch == '<'|| ch == '>' || ch== '<=' || ch== '>=' || ch== '==' || ch== '!=' || ch == '&&'|| ch == '||' ||
    ch == '!' || ch == '&' || ch == '^' || ch == '~' || ch == '<<' || ch== '>>' || ch== '=' || ch== '+=' ||
    ch== '-=' || ch== '*=' || ch== '/=' || ch== '.' || ch== '->')
    {
        return true;
    }
     return false;
}
//check is Operator
bool isOperator(char ch){
    if(ch == '+' || ch == '-'|| ch== '*' || ch== '/'|| ch== '%'|| ch == '<'|| ch == '>' || ch== '<=' || ch== '>=' ||
       ch== '==' || ch== '!=' || ch == '&&'|| ch == '||' || ch == '!' || ch == '&' || ch == '^' || ch == '~' ||
       ch == '<<' || ch== '>>' || ch== '=' || ch== '+=' || ch== '-=' || ch== '*=' || ch== '/=')
       {
            return true;
    }
     return false;
}
//check is valid or not
bool isValidIdentifier(char* str){
    if(str[0]=='0'||str[0]=='1'||str[0]=='2'||str[0]=='3'||str[0]=='4'||str[0]=='5'||str[0]=='6'||str[0]=='7'
       ||str[0]=='8'||str[0]=='9' || str[0]=='_' || isDelimiter(str[0])==true)
       {
            return true;
       }
	return false;
}
//check keywords
bool isKeyword(char* str){
    if(!strcmp(str,"if") || !strcmp(str,"else") || !strcmp(str,"break") || !strcmp(str,"case")
       || !strcmp(str,"char") || !strcmp(str,"const") || !strcmp(str,"continue") || !strcmp(str,"default") || !strcmp(str,"do")
       || !strcmp(str,"double") || !strcmp(str,"else") || !strcmp(str,"enum") || !strcmp(str,"extern") || !strcmp(str,"float")
       || !strcmp(str,"for") || !strcmp(str,"goto") || !strcmp(str,"inline") || !strcmp(str,"int") || !strcmp(str,"long")
       || !strcmp(str,"register") || !strcmp(str,"return") || !strcmp(str,"short") || !strcmp(str,"static") || !strcmp(str,"struct")
       || !strcmp(str,"switch") || !strcmp(str,"typedef") || !strcmp(str,"union") || !strcmp(str,"unsigned") || !strcmp(str,"void")
       || !strcmp(str,"volatile") || !strcmp(str,"while"))
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


    printf("Output: \n");
    bool deli = isDelimiter(str);
    printf("Delimiter: %d\n", deli);

    bool operat = isOperator(str);
    printf("Operator: %d\n", operat);

    bool valid = isValidIdentifier(&str);
    printf("Identifier/Operator: %d\n", valid);

    bool keywd = isKeyword(&str);
    printf("Keyword: %d\n", keywd);

    return 0;
}
