// para rodar o programa, use o comando: gcc primeiroPrograma.c -o primeiroPrograma
// o comando acima compila o código (gcc) e gera um executável chamado primeiroPrograma (-o 'output')
// para executar o programa, use o comando: ./primeiroPrograma no terminal

#include <stdio.h> // biblioteca padrão de entrada e saída do C

int main (void) { // função principal do programa, esta função é o ponto de entrada do programa // void indica que não recebe argumentos e int indica que retorna um inteiro (return 0 no final)
    int porta = 80; // declara uma variável inteira chamada porta e inicializa com o valor 80
    char ip[] = "192.168.0.1"; // declara um array de caracteres chamado // caracteres = cada letra ou número é um caractere, e o array é uma sequência de caracteres
    float versao = 1.0; // declara uma variável do tipo float chamada versao e inicializa com o valor 1.0

    printf("PORT SCANNER\n"); // imprime a mensagem "Ola, mundo!" na tela
    printf("Versao: %.1f \n", versao); // imprime a versão do programa, %f é usado formatar a variavel versao que foi passada depois do texto // %.1f indica que queremos mostrar somente uma casa decimal do número float depois da virgula
    printf("Varrendo host: %s na porta: %d\n", ip, porta); // imprime o IP e a porta, %s é usado para strings (como ip) e %d para inteiros (como porta)
    return 0; // retorna 0 para indicar que o programa terminou com sucesso
}