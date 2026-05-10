#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cadastrarLivros() {
    FILE *livros;
    char Codigo[100];
    char Titulo[100];
    char autor[100];
    livros = fopen("livros.txt", "a");
    if (livros == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 0;
    }
    printf("Digite o Codigo do livro:\n");
    scanf("%s", Codigo);

    printf("Digite o Titulo do livro:\n");
    scanf(" %[^\n]", Titulo);

    printf("Digite o Autor do livro:\n");
    scanf(" %[^\n]", autor);

    fprintf(livros, "%s;%s;%s;disponivel\n", Codigo, Titulo, autor);
    fclose(livros);
    return 1;

}

int ConsultarLivros() {
    FILE *livros;

    char codigoBusca[100];

    char Codigo[100];
    char Titulo[100];
    char autor[100];
    char status[100];

    int encontrado = 0;

   livros = fopen("livros.txt", "r");
    if (livros == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 0;
    }
    printf("Digite o Codigo do livro:\n");
    scanf("%s", codigoBusca);

    while (fscanf(livros, " %99[^;];%99[^;];%99[^;];%99[^\n]\n", Codigo, Titulo, autor, status) == 4) {
        if (strcmp(codigoBusca, Codigo) == 0) {
            printf("\n Livro encontrado! \n");
            printf("Codigo: %s \n", Codigo);
            printf("Titulo: %s \n", Titulo);
            printf("Autor: %s \n", autor);
            printf("Status: %s \n", status);

            encontrado = 1;
            break;
        }

    }
    if (encontrado == 0) {
        printf("\n Livro nao encontrado! \n");
    }

    fclose(livros);

    return 1;



}

int Emprestimo() {
    FILE *livros;
    FILE *temporario;

    char codigoBusca[100];

    char Codigo[100];
    char Titulo[100];
    char autor[100];
    char status[100];

    int encontrado = 0;
    int emprestado = 0;

   livros = fopen("livros.txt", "r");
    if (livros == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    temporario = fopen ("temporario.txt", "w");
    if (temporario == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        fclose(livros);
        return 0;
    }
    printf("Digite o Codigo do livro que sera emprestado:\n");
    scanf("%s", codigoBusca);

    while (fscanf(livros, " %99[^;];%99[^;];%99[^;];%99[^\n]\n", Codigo, Titulo, autor, status) == 4) {

        if (strcmp(Codigo, codigoBusca) == 0) {
            encontrado = 1;

            if (strcmp(status, "disponivel") == 0) {
                fprintf(temporario, "%s;%s;%s;emprestado\n", Codigo, Titulo, autor);
                emprestado = 1;
            } else {
                fprintf(temporario, "%s;%s;%s;%s\n", Codigo, Titulo, autor, status);
                printf("Este livro ja esta emprestado.\n");
            }

        } else {
            fprintf(temporario, "%s;%s;%s;%s\n", Codigo, Titulo, autor, status);
        }
    }

    fclose(livros);
    fclose(temporario);

    remove("livros.txt");
    rename("temporario.txt", "livros.txt");

    if (encontrado == 0) {
        printf("Livro nao encontrado.\n");
    } else if (emprestado == 1) {
        printf("Livro emprestado com sucesso.\n");
    }

    return 1;



}

int Devolucao() {
    FILE *livros;
    FILE *temporario;

    char codigoBusca[100];

    char Codigo[100];
    char Titulo[100];
    char autor[100];
    char status[100];

    int encontrado = 0;
    int emprestado = 0;

    livros = fopen("livros.txt", "r");
    if (livros == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    temporario = fopen ("temporario.txt", "w");
    if (temporario == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        fclose(livros);
        return 0;
    }
    printf("Digite o Codigo do livro que sera emprestado:\n");
    scanf("%s", codigoBusca);

    while (fscanf(livros, " %99[^;];%99[^;];%99[^;];%99[^\n]\n", Codigo, Titulo, autor, status) == 4) {

        if (strcmp(Codigo, codigoBusca) == 0) {
            encontrado = 1;

            if (strcmp(status, "emprestado") == 0) {
                fprintf(temporario, "%s;%s;%s;disponivel\n", Codigo, Titulo, autor);
                emprestado = 1;
            } else {
                fprintf(temporario, "%s;%s;%s;%s\n", Codigo, Titulo, autor, status);
                printf("Este livro ja esta disponivel.\n");
            }

        } else {
            fprintf(temporario, "%s;%s;%s;%s\n", Codigo, Titulo, autor, status);
        }
    }

    fclose(livros);
    fclose(temporario);

    remove("livros.txt");
    rename("temporario.txt", "livros.txt");

    if (encontrado == 0) {
        printf("Livro nao encontrado.\n");
    } else if (emprestado == 1) {
        printf("Livro devolvido com sucesso.\n");
    }

    return 1;



}

int Listagem() {
    FILE *livros;

    char Codigo[100];
    char Titulo[100];
    char autor[100];
    char status[100];

    livros= fopen("livros.txt", "r");
    if (livros == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 0;
    }
    while (fscanf(livros, " %99[^;];%99[^;];%99[^;];%99[^\n]\n", Codigo, Titulo, autor, status)== 4) {
        printf("Codigo: %s\n", Codigo);
        printf("Titulo: %s\n", Titulo);
        printf("Autor: %s\n", autor);
        printf("Status: %s\n", status);

    }
    fclose(livros);
    return 1;

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