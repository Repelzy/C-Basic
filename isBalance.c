#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100000

int isBalanced(char *s) {
    int len = strlen(s);
    for (int i = 1; i < len; i++) {
        if (abs(s[i] - s[i-1]) != abs(s[len-i-1] - s[len-i])) {
            return 0;
        }
    }
    return 1;
}

int main(){
	int t;
    char s[MAX_LENGTH + 1];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        
        if (isBalanced(s)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}
