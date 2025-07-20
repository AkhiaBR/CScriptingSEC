#include <stdio.h> 
#include <sys/socket.h> // biblioteca para manipulação de sockets
#include <netdb.h> // biblioteca para manipulação de banco de dados de rede
#include <unistd.h> // biblioteca para chamadas POSIX (ex: close)
#include <netinet/in.h>     // manipulação de endereços de rede IPv4
#include <arpa/inet.h>   

int main (int argc, char *argv[]) {
    int meuSocket;
    int conexao;

    int porta; 
    int inicio = 0;
    int final = 65535; // portas válidas vão de 0 a 65535
    char *destino; // tem "*" porque é uma string, ou seja, um array de caracteres
    destino = argv[1];

    struct sockaddr_in alvo; 

    for (porta = inicio; porta <= final; porta++) {
        meuSocket = socket(AF_INET, SOCK_STREAM, 0);
        alvo.sin_family = AF_INET; // família IPv4
        alvo.sin_addr.s_addr = inet_addr(destino); // converte o IP de string para binário
        alvo.sin_port = htons(porta); // converte a porta para big-endian

        conexao = connect(meuSocket, (struct sockaddr *)&alvo, sizeof(alvo));

        if (conexao == 0) { // connect retorna 0 se conectou com sucesso
            printf("Porta %d aberta\n", porta);
        } else {
            printf("Porta %d fechada\n", porta);
        }

        close(meuSocket); // fecha o socket, liberando recursos
    }

    return 0;
}