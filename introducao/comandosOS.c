#include <stdio.h> // biblioteca padrão de entrada e saída do C
#include <stdlib.h> // biblioteca padrão de funções utilitárias do C

int main (void) {
    printf("PORTAS TCP ABERTAS: \n"); // imprime a mensagem "PORTAS TCP ABERTAS:" na tela
    system("netstat -an | grep LISTEN"); // executa o comando netstat para listar as portas TCP abertas e filtra a saída para mostrar apenas as linhas que contêm "LISTEN"
    return 0;
}