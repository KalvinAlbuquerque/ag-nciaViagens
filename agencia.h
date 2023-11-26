#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM_MAX 50

/* 
* Header destinado a conter todos os protótipos de funções e estruturas que serão utilizadas na aplicação, 
* juntamente com a respectiva documentação de cada uma.
*/


/* Lista simplesmente encadeada de sítios turísticos. 
* Possui os seguintes atributos: 
* nome do sítio turístico,
* um contador para turistas do tipo 1 e do tipo 2 que visitaram esse sitio turístico,
* ponteiro para o próximo sítio turístico
*/
typedef struct SitioTuristico
{
    char nome[TAM_MAX];
    int countTurista1;
    int countTurista2;
    struct SitioTuristico * proximoSitioTuristico;

}SitioTuristico;

/* Lista duplamente encadeada de países.
* Possui os segunites atributos:
* nome do país,
* um ponteiro para a lista de sítios turísticos daquele país,
* um ponteiro para o próximo país
*/
typedef struct Pais
{
    char nome[TAM_MAX];
    SitioTuristico * listaSitiosTuristico;
    struct Pais * proximoPais;

}Pais;

/* Lista simplesmente encadeada de turistas.
* Possui os seguintes atributos:
* nome do cliente,
* tipo do cliente, podendo ser tipo um ou tipo dois. O tipo um será aquele cliente que possui
* um país de destino confirmado, enquanto o tipo dois necessitará de ajuda do sistema para decidir
* seu destino.
* O penúltimo atributo é o país de destino e
* um ponteiro para o próximo cliente. 
*/
typedef struct Turista
{
    char * nome;
    int tipo;
    Pais paisDestino;
    struct Turista * ProximoTurista;

}Turista;

/*
    FUNÇÕES PARA PAÍSES
*/

/* Função destinada a inserir um país na lista de países da aplicação. */
void inserirPais(Pais ** listaPaises, const char * nomePais);

/* Função destinada a listar todos os países cadastrados */
void listarPaises(Pais ** listaPaises);

/* Função destinada a iterar toda a lista de países para encontrar um país cujo nome é passado por
* parâmetro e retorná-lo 
*/
Pais * localizarPais(Pais ** listaPaises, const char * nomePais);


/* 
    FUNÇÕES PARA SÍTIOS TURÍSTICOS
*/

/* Função destinada a inserir um novo sitio turístico na lista de sítios turísticos
* de determinado país.
*/
void inserirNovoSitioTuristico(Pais * pais, const char * nomeSitioTuristico);

/* Função destinada a listar todos os guias turísticos de um determinado país passado
* por parâmetro
*/
void listarSitiosTuristicos(Pais * pais);


/*
    FUNÇÕES PARA TURISTAS/CLIENTES/USUÁRIOS
*/

/* Função responsável por cadastrar o turista */
void cadastrarTurista(Turista ** listaTurista, const char * nome, Pais paisDestino);

/* Função responsável por solicitar o nome do cliente cadastrado e retorná-lo */
char * solicitarNomeDoCliente();
//TODO: criar função para solicitar nome e pais de destino do turista. Caso não tenha, chama a funçao para decidir o pais de destino
/* Função destinada a printar o menu de escolhas do usuário*/
void exibirMenu();
/* 
    FUNÇÕES UTILITÁRIAS
*/

/* Função destinada a limpar tela.
* Pode ser utilizada tanto em sistemas windows como unix.
*/
void limparTela();

/* Função destinada a dar um pause na tela do usuário e esperar ele apertar enter para continuar */
void pause();

/* Função destinada a exibir um avião para enfeitar o menu */
void exibirAviao();

