#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    srand(time(NULL));
    int i, quantidade;
    char palavra, letra;
    char lista[6][20] = {
        "pinguim", "dinossauro", "jaguatirica", "toupeira", "tamanduá", "porco"
    };
    
    
    
    return 0;
}



//teste
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mostraForca(int error){
    printf("+-------+");
    printf("|       %c", error >= 1 ? 'O' : '_');
}

int main(){
    char  palavras[5][20] = {
        "celular",
        "maripousa",
        "normas",
        "fantasia",
        "heroi"
    };  
    char letra, resposta[20];
    int erro = 0, acerto = 0;
    int tamanho, escolha;
    
    srand(time(NULL));
    escolha = rand() % 5;
    char palavra[20];
    
    strcpy(palavra, palavras[escolha]);
    
    tamanho = strlen(palavra);
    
    for(int i = 0; i < tamanho; i++){
        resposta[i] = '-';
    }
    resposta[tamanho] = '\0';
    
    printf("jogo da forca\n");
    
    while(erro < 6 && acerto < tamanho){
        printf("palavras: \n");
        for(int i = 0; i < tamanho; i++){
            printf("%c",resposta[i]);
        }
        printf("\nnumero de tentativas restante: %d\n", 6 -  erro);
        printf("digite uma letra: ");
        scanf("%c", &letra);
    }

    for(int i = 0; i < tamanho; i++){
        if(palavra[i] == letra &&resposta[i] == '-' ){
            resposta[i] = letra; 
            acerto++;
            acerto = 1 ;
        }
    }
    if(!acerto){
        printf("nao acertou.\n");
    }else{
        printf("acertouuuuuuu.\n");
    }
    if(acerto == tamanho){
        printf("parabens acertou: %s\n", palavra);
    }else{
        printf("perdeu! a palavra era : %s\n", palavra);
    }

    return 0;
}
