#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* capitalizeFirst(char *str){
    str[0] = toupper(str[0]);
    for(int i = 1; i < strlen(str); ++i){
        str[i] = tolower(str[i]);
    }
    return str;
}

int removeSpecialChar(char *str){
    int idx = 0;
    int hasLetter = 0;
    for(int i = 0; str[i] != '\0'; i++){
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' '){
            str[idx++] = c;
            if (c != ' ') hasLetter = 1;
        }
    }
    str[idx] = '\0'; 
    return hasLetter;
}

int main(){
    int t;
    scanf("%d", &t);
    getchar(); 
    char a[t][100]; 
    for (int i = 0; i < t; i++) {
        char s[100];
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = 0; 
        if (removeSpecialChar(s)) {
            char res[100] = "";
            char *token = strtok(s, " ");
            while(token != NULL){
                strcat(res, capitalizeFirst(token));
                token = strtok(NULL, " ");
                if(token != NULL){
                    strcat(res, " ");
                }
            }
            strcpy(a[i], res);
        } else {
            strcpy(a[i], "NULL");
        }
    }
    
    for (int i = 0; i < t; i++) {
        printf("%s\n", a[i]);
    }
    return 0;
}
