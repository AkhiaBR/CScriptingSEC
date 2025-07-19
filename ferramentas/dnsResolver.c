#include <stdio.h> // biblioteca padrão de entrada e saída do C
#include <netdb.h> // biblioteca para manipulação de banco de dados de rede
#include <arpa/inet.h> // biblioteca para manipulação de endereços IP

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("DNS Resolver.\n");
        printf("Modo de uso: ./dnsResolver <hostname>\n");
        return 1;
    } else {
        // alvo tem que ser obrigatoriamente um ponteiro porque gethostbyname só retorna ponteiro
        struct hostent *alvo = gethostbyname(argv[1]); // estrutura do tipo hostent (hostent = {h_name, h_aliases, h_addrtype, h_length, h_addr_list}) que armazena informações sobre o host consultado

        printf("IP: %s",inet_ntoa(*(struct in_addr*)alvo->h_addr_list)); // inet_ntoa converte o endereço IP de formato binário para uma string legível. *(struct in_addr*)alvo->h_addr_list é usado para acessar o primeiro endereço IP da lista de endereços associados ao host. h_addr_list é um array de ponteiros para endereços IP.
        return 0; // retorna 0 para indicar que o programa terminou com sucesso
    }
}