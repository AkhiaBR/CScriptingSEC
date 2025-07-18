// para rodar o programa, use o comando: gcc primeiroPrograma.c -o primeiroPrograma
// o comando acima compila o código (gcc) e gera um executável chamado primeiroPrograma (-o 'output')
// para executar o programa, use o comando: ./primeiroPrograma no terminal

#include <stdio.h> // biblioteca padrão de entrada e saída do C

int main (void) { // função principal do programa, esta função é o ponto de entrada do programa // void indica que não recebe argumentos e int indica que retorna um inteiro (return 0 no final)
    printf("Hello, World!"); // imprime a mensagem "Ola, mundo!" na tela
    return 0; // retorna 0 para indicar que o programa terminou com sucesso
}