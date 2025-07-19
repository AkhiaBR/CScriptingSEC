#include <stdio.h> // biblioteca padrão de entrada e saída do C
#include <netdb.h> // biblioteca para manipulação de banco de dados de rede
#include <arpa/inet.h> // biblioteca para manipulação de endereços IP

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("DNS Resolver.\n");
        printf("Modo de uso: ./dnsResolver <hostname>\n");
        return 1;
    } else {
        struct hostent *alvo = gethostbyname(argv[1]); // struct hostent é uma delimitacao de dados que contém informações sobre um host. *alvo é um ponteiro para essa estrutura, já que gethostbyname retorna muito mais informações do que apenas o IP. Se fosse *alvo[], teria vários ponteiros para várias estruturas, mas como é apenas *alvo, temos um único ponteiro que aponta para uma única estrutura hostent.

        printf("IP: %s",inet_ntoa(*(struct in_addr*)alvo->h_addr_list)); // inet_ntoa converte o endereço IP de formato binário para uma string legível. *(struct in_addr*)alvo->h_addr_list é usado para acessar o primeiro endereço IP da lista de endereços associados ao host. h_addr_list é um array de ponteiros para endereços IP.
        return 0; // retorna 0 para indicar que o programa terminou com sucesso
    }
}