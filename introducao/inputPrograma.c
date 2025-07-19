// para rodar o programa, use o comando: gcc primeiroPrograma.c -o primeiroPrograma
// o comando acima compila o código (gcc) e gera um executável chamado primeiroPrograma (-o 'output')
// para executar o programa, use o comando: ./primeiroPrograma no terminal

#include <stdio.h> // biblioteca padrão de entrada e saída do C

int main (void) { // função principal do programa, esta função é o ponto de entrada do programa // void indica que não recebe argumentos e int indica que retorna um inteiro (return 0 no final)
    char text[16]; // declara um array de caracteres chamado text

    printf("Digite seu nome: "); // solicita ao usuário que digite seu nome
    // scanf("%s", &text); // lê a entrada do usuário e armazena na variável text (&text é usado para atribuir o input à variável) // %s é usado para strings
    fgets(text, sizeof(text), stdin); // lê a entrada do usuário e armazena na variável text, fgets é mais seguro que scanf para strings // stdin é o fluxo de entrada padrão (teclado)

    printf("Seu nome é: %s", text); // imprime o nome digitado pelo usuário, %s é usado para strings

    return 0; // retorna 0 para indicar que o programa terminou com sucesso
}