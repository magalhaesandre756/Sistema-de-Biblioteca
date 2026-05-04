#include <stdio.h>
#include <stdlib.h>
int cadastrarLivros() {
    FILE *livros;
    char Codigo[100];
    char Titulo[100];
    char autor[100];
    livros = fopen("livros.txt", "a");

}

int ConsultarLivros() {

}

int Emprestimo() {

}

int Devolucao() {

}

int Listagem() {

}


int menu(){
    int opcao;
    opcao = 0;

    while (opcao != 6 ) {
        printf("--- MENU ---\n");
        printf("1. Cadastro de livros \n");
        printf("2. Consulta de livros\n");
        printf("3. Emprestimo de livros\n");
        printf("4. Devolucao de livros\n");
        printf("5. Listagem do acervo\n");
        printf("6. Sair\n");
        printf("Escolha a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarLivros();
                break;
            case 2:
                ConsultarLivros();
                break;
            case 3 :
                Emprestimo();
                break;
            case 4:
                Devolucao();
                break;
            case 5:
                Listagem();
                break;
            case 6:
                break;

        }
    }
}


int main() {

    menu();


    return 0;
}
