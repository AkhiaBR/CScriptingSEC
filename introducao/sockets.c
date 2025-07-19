#include <sys/socket.h> // biblioteca para manipulação de sockets
#include <stdio.h> // biblioteca padrão de entrada e saída do C
#include <netinet/in.h> // biblioteca para manipulação de endereços de rede
#include <arpa/inet.h> // biblioteca para conversão de endereços IP
#include <unistd.h> // biblioteca para manipulação de chamadas de sistema POSIX

// exemplo de um struct:
// struct Pessoa {
//     char nome[50];
//     int idade;
// }; 


int main (void) {
    int meuSocket;
    int conexao;

    struct sockaddr_in alvo; // estrutura com nome alvo que armazena informacoes com campos ja definidos (sockaddr_in = {sin_family, sin_port, sin_addr}) para o endereço do socket

    meuSocket = socket(AF_INET, SOCK_STREAM, 0); // cria um socket, AF_INET indica que é um socket IPv4, SOCK_STREAM indica que é um socket de fluxo (TCP), 0 indica que o protocolo padrão será usado (TCP)

    alvo.sin_family = AF_INET; // define a família de endereços do socket como IPv4
    alvo.sin_port = htons(80); // define a porta do socket
    alvo.sin_addr.s_addr = inet_addr("192.168.7.1"); // define o endereço IP local do socket

    conexao = connect(meuSocket, (struct sockaddr *)&alvo, sizeof(alvo)); // tenta estabelecer uma conexão com o socket alvo, passando o endereço do socket e o tamanho da estrutura

    if (conexao == 0) { // verifica se a conexão foi bem-sucedida
        printf("PORTA ABERTA!\n");
    } else {
        printf("PORTA FECHADA.\n");
    }

    close(meuSocket); // fecha o socket para liberar os recursos alocados
    return 0; 
}