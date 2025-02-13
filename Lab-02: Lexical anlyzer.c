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
            return false;
       }
        return true;
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
//check if the value is Integer - 22nd January, 2-25
bool isInteger(char* str){
    int i=0, len = strlen(str);
    if(len==0){
       return false;
    }

    if(str[0] == '-'){
        i = 1;
    }

    for(; i<len; i++){
        if(str[i]!='0' && str[i]!='1' && str[i]!='2' && str[i]!='3' && str[i]!='4'
        && str[i]!='5' && str[i]!='6' && str[i]!='7' && str[i]!='8' && str[i]!='9'){
            return false;
        }
    }
    return true;
}

//Check if it is Real Number (Factorial)
bool isRealNumber(char* str){
    int i, len = strlen(str);
    bool hasDecimal = false;
    if(len == 0){
        return false;
    }

    if(str[0]=='-'){
        i=1;
    }
    for(; i<len; i++){
        if(str[i]!='0' && str[i]!='1' && str[i]!='2' && str[i]!='3' && str[i]!='4'
        && str[i]!='5' && str[i]!='6' && str[i]!='7' && str[i]!='8' && str[i]!='9' && str[i]!='.'){
            return false;
        }
        if(str[i]=='.'){
            hasDecimal = true;
        }
    }
    return hasDecimal;
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

    bool isInt = isInteger(&str);
    printf("Integer: %d\n", isInt);

    bool isReal = isRealNumber(&str);
    printf("Real Number is: %d\n", isReal);
    return 0;
}
