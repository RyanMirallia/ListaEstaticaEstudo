#include <stdio.h>
#include "biblioteca.h"

int main(){
    Lista biblioteca;
    int opcao, codigo;

    inicializar_lista(&biblioteca);

    do {
        printf("\n===== Sistema de Biblioteca =====\n");
        printf("1. Inserir livro\n");
        printf("2. Remover livro\n");
        printf("3. Exibir todos os livros\n");
        printf("4. Sair\n");
        printf("Escolha uma opcaoo: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_livro(&biblioteca);
                break;
            case 2:
                printf("digite o codigo do livro que deseja remover: ");
                scanf("%d", &codigo);
                remover_livro(&biblioteca, codigo);
                break;
            case 3:
                exibir_lista(&biblioteca);
                break;
            case 4:
                printf("Saindo\n");
                break;
            default:
                printf("opcao invalida\n");
        }
    } while (opcao != 4);

    return 0;
}