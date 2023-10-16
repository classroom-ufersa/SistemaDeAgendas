#ifndef AGENDA_H
#define AGENDA_H

//Estrutura para armazenar e manipular informações dos contatos
typedef struct contato
{
    char nomeCtt[50];
    int idade;
    char telefone[15];
    char email[50];
} Contato;

//Estrutura para armazenar informações sobre a agenda
typedef struct agenda
{
    char nomeAgenda[50];
    int codigo;
    int numContatos;
    Contato *contatos;
} Agenda;

//Função que vai comparar os contatos e listar na ordem alfabetica
int compararContatos(const void *a, const void *b);

//Função para adicionar contatos na lista
void adicionarContato(Agenda *agenda);

//Funçaõ para remover contatos da lista
void removerContato(Agenda *agenda, char nomeContato[]);

//Função que carrega os dados de um arquivo de texto se ele já existir (agenda.txt)
void carregarAgenda(Agenda *agenda);

//Função para salvar e atualizar informações na agenda, quando adiciona um contato, remove, edita ou exclui
void salvarAgendaEditada(const Agenda *agenda); 

//Função que serve para buscar um contato na agenda
int buscarContato(const Agenda *agenda, const char nomeBusca[]);

//Função que lista todos os contatos cadastrados
void listarContatoBusca(const Contato *contato);

//Função que serve para editar um contato
void editarContato(Agenda *agenda, const char nomeBusca[]);

//Função para listar um unico contato que foi pesquisado
void listarContatos(const Agenda *agenda);

#endif
