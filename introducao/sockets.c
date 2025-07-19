#include <sys/socket.h>     // manipulação de sockets
#include <stdio.h>          // entrada e saída padrão
#include <netinet/in.h>     // manipulação de endereços de rede IPv4
#include <arpa/inet.h>      // conversão de endereços IP (string <-> binário)
#include <unistd.h>         // chamadas POSIX (ex: close)

// exemplo de uma struct:
// struct Pessoa {
//     char nome[50];
//     int idade;
// };

int main(void) {
    int meuSocket;
    int conexao;

    // 'alvo' guarda os dados do endereço do servidor (IP + porta)
    // struct sockaddr_in tem os campos: sin_family, sin_port, sin_addr
    struct sockaddr_in alvo;

    // cria o socket
    // AF_INET = IPv4, SOCK_STREAM = TCP, 0 = protocolo padrão (TCP)
    meuSocket = socket(AF_INET, SOCK_STREAM, 0);

    // define os campos do endereço alvo:

    alvo.sin_family = AF_INET;               // família IPv4
    alvo.sin_port = htons(80);               // porta 80, convertida para ordem de bytes de rede (big-endian)
    alvo.sin_addr.s_addr = inet_addr("192.168.7.1"); // IP convertido para formato binário

    // tenta conectar ao endereço 'alvo' usando o socket 'meuSocket'
    // (struct sockaddr *)&alvo converte o ponteiro para o tipo genérico esperado // o ponteiro &alvo é passado para o ponteiro de struct sockaddr, que é o tipo genérico usado para endereços de rede
    // sizeof(alvo) informa o tamanho da estrutura em bytes (necessário para a função)
    conexao = connect(meuSocket, (struct sockaddr *)&alvo, sizeof(alvo));

    if (conexao == 0) { // connect retorna 0 se conectou com sucesso
        printf("PORTA ABERTA!\n");
    } else {
        printf("PORTA FECHADA.\n");
    }

    close(meuSocket); // fecha o socket, liberando recursos
    return 0;
}

// -- explicação linha 34: 

// 'alvo' é uma struct sockaddr_in com campos para endereço IPv4:
// sin_family, sin_port, sin_addr, etc.

// Na memória, 'alvo' ocupa um bloco contíguo de bytes, por exemplo:

// Endereços de memória (exemplo hipotético):
// 0x1000: sin_family (2 bytes)
// 0x1002: sin_port   (2 bytes)
// 0x1004: sin_addr   (4 bytes)
// ...

// 'alvo' representa o conteúdo desses campos (os valores armazenados)

// '&alvo' pega o endereço do primeiro byte da struct (ex: 0x1000)

// Visualização:

//       +------------------------------+
// alvo: | sin_family | sin_port | sin_addr | ...
//       +------------------------------+
//        ↑
//        |
//      &alvo  -> aponta para o início da struct (sin_family)

// Quando fazemos:
// (struct sockaddr *)&alvo

// Estamos dizendo para o compilador:
// "Trate esse endereço &alvo como um ponteiro para struct sockaddr"

// Isso é necessário porque a função connect() espera um
// ponteiro genérico para struct sockaddr, e sockaddr_in é uma
// estrutura mais específica para IPv4.

// Passar o endereço da struct e seu tamanho (sizeof(alvo)) permite
// que o sistema operacional saiba onde ler os dados do endereço e
// quantos bytes ele deve considerar para essa estrutura.

// Se não passássemos o tamanho correto, a conexão pode falhar
// porque o SO não saberia interpretar corretamente o endereço.

// Em resumo:
//   - 'alvo' é uma variável do tipo struct sockaddr_in (estrutura com dados do endereço)
//   - '&alvo' é um ponteiro para essa estrutura (endereço na memória)
//   - '(struct sockaddr *)&alvo' converte esse ponteiro para o tipo esperado por connect()
