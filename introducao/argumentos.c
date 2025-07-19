#include <stdio.h> // biblioteca padrão de entrada e saída do C

// um ponteiro é uma variável que guarda o endereço de memória de outra variável

int main (int argc, char *argv[]) { // função principal do programa que recebe argumentos da linha de comando, int argc é o número de argumentos passados e char *argv[] é um array de strings que contém os argumentos passados, se nao tivesse o "*" o argv seria um array de char, ou seja, uma string, já que nao guardaria o endereço de memória de cada argumento
    if (argc<2) { // verifica se o número de argumentos é menor que 2, ou seja, se não foi passado nenhum argumento além do nome do programa
        printf("HOST SCANNER.\n");
        printf("Modo de uso: ./argumentos.c <IP>\n");
        return 1; // retorna 1 para indicar que houve um erro, neste caso, que o usuário não passou o IP como argumento
    }
    else {
        for (int i=0;i<=254;i++) { // loop que itera 10 vezes, i é a variável de controle do loop
            printf("Varrendo Host %s.%i\n",argv[1],i); // imprime a mensagem "Varrendo Host" seguida do IP passado como argumento e o número da iteração (i), %s é usado para strings (como argv[1]) e %i para inteiros (como i)
        }
        return 0; // retorna 0 para indicar que o programa terminou com sucesso
    }
}