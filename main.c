#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostra_boneco(int erro) {
    printf(" +-------+\n");
    printf(" |       %c\n", erro >= 1 ? 'O' : ' ');
    printf(" |      %c%c%c\n", 
           erro >= 3 ? '/' : ' ',
           erro >= 2 ? '|' : ' ',
           erro >= 4 ? '\\' : ' ');
    printf(" |      %c %c\n", 
           erro >= 5 ? '/' : ' ',
           erro >= 6 ? '\\' : ' ');
    printf(" |\n");
    printf("_|_\n\n");
}

int main() {
    int vida = 5;
    char dica[20];
    char frase[200];
    char palavra[20], lacuna[20] = {0};
    int tamanho, v = 0;
    char letra;
    
    
    
    
    printf("Digite a palavra secreta: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0'; 

    printf("Digite a dica: ");
    fgets(dica, sizeof(dica), stdin);
    dica[strcspn(dica, "\n")] = '\0'; 
    tamanho = strlen(palavra);

    while (vida > 0 && v == 0) {
        system("clear"); 

        printf("Dica: %s\n", dica);
        printf("Vida: %d\n", vida);
        
        mostra_boneco(5 - vida);
        
        printf("Quantidade de letras: %d\n", tamanho);

        for (int i = 0; i < tamanho; i++) {
            if (lacuna[i] == '\0') printf("_ ");
            else printf("%c ", lacuna[i]);
        }

        printf("\n\nDigite a letra: ");
        scanf(" %c", &letra);

        int count = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == letra && lacuna[i] != letra) {
                lacuna[i] = letra;
                count++;
            }
        }

        if (count == 0) {
            printf("Errou a letra.\n");
            vida--;
        } else {
            printf("Parabéns, acertou!\n");
        }

        if (strcmp(palavra, lacuna) == 0) {
            v = 1;
        }


        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
    }

    if (v == 1) {
        printf("\nParabéns! Você venceu com %d vidas restantes.\n", vida);
    } else {
        printf("\nVocê perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
