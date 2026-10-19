#include <stdio.h>

int main(){
    char palavra[100];
    int i = 0;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    while (palavra[i] != '\0') {
        printf("%c\n", palavra[i]);
        i++;
    }
    printf("quantidade de letras: %d\n", i);
return 0;
}