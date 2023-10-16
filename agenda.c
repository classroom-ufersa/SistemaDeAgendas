#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

// Função de comparação para qsort
int compararContatos(const void *a, const void *b)
{
    return strcmp(((Contato *)a)->nomeCtt, ((Contato *)b)->nomeCtt); //Compara um nome de contato com o outro para colocar em ordem alfabetica 
}

// Função para adicionar um contato mantendo a ordem alfabética
void adicionarContato(Agenda *agenda)
{
    if (agenda->numContatos < 100) // Foi definido um limite de 100 contatos
    { 
        //Recebe as informações sobre o contato, como o nome, idade, telefone e e-mail
        Contato novoContato;
        printf("Digite o nome: ");
        scanf("%s", novoContato.nomeCtt);
        printf("Digite a idade: ");
        scanf("%d", &novoContato.idade);
        printf("Digite o telefone: ");
        scanf("%s", novoContato.telefone);
        printf("Digite o email: ");
        scanf("%s", novoContato.email);

        // Adicionar o novo contato à lista
        agenda->contatos[agenda->numContatos] = novoContato;
        agenda->numContatos++;
        printf("Contato adicionado com sucesso.\n");

        // Ordenar a lista de contatos por ordem alfabética
        qsort(agenda->contatos, agenda->numContatos, sizeof(Contato), compararContatos);

        // Salvar os dados atualizados no arquivo
        salvarAgendaEditada(agenda);
    }
    else
    {
        printf("A agenda esta cheia. Remova um contato antes de adicionar mais.\n");
    }
}

// Função para remover um contato
void removerContato(Agenda *agenda, char nomeContato[])
{
    int i;
    int encontrado = 0;
    //Procura o contato pelo indice e compara o nome do contato
    for (i = 0; i < agenda->numContatos; i++)
    {
        if (strcmp(agenda->contatos[i].nomeCtt, nomeContato) == 0)
        {
            // Desloca os contatos posteriores para preencher o espaço
            for (int j = i; j < agenda->numContatos - 1; j++)
            {
                agenda->contatos[j] = agenda->contatos[j + 1];
            }
            agenda->numContatos--;

            // Atualize o arquivo após a remoção
            salvarAgendaEditada(agenda);

            encontrado = 1;
            printf("Contato removido com sucesso.\n");
            break;
        }
    }
    //Aparece essa informação caso contato não seja encontrado
    if (!encontrado)
    {
        printf("Nao existe contato com esse nome.\n");
    }
}
// Funçaõ para ler a agenda
void carregarAgenda(Agenda *agenda)
{
    FILE *arquivo = fopen("agenda.txt", "r");
    if (arquivo == NULL)
    {
        return; // Se o arquivo não existe, a agenda estará vazia
    }
    //Ler os dados que ja exisitem na agenda agenda
    fscanf(arquivo, "%s%d%d", agenda->nomeAgenda, &agenda->codigo, &agenda->numContatos);

    for (int i = 0; i < agenda->numContatos; i++)
    {
        Contato c;
        fscanf(arquivo, "%s%d%s%s", c.nomeCtt, &c.idade, c.telefone, c.email);
        agenda->contatos[i] = c;
    }

    fclose(arquivo);//Fecha o arquivo txt
}

// Função para listar todos os contatos
void listarContatos(const Agenda *agenda)
{
    if (agenda->numContatos > 0) //Se a agenda tiver >= 1 contato
    {
        printf("Contatos na agenda %s:\n", agenda->nomeAgenda);

        for (int i = 0; i < agenda->numContatos; i++)
        {
            Contato c = agenda->contatos[i];
            printf("Nome: %s\n", c.nomeCtt);
            printf("Idade: %d\n", c.idade);
            printf("Telefone: %s\n", c.telefone);
            printf("Email: %s\n", c.email);
            printf("------------------------------\n");
        }
    }
    else
    {
        printf("Ainda nao foi cadastrado contatos na agenda!!!\n"); //Caso a agenda esteja vazia
    }
}

//Função para salvar e atualizar informações na agenda, quando adiciona um contato, remove, edita ou exclui
void salvarAgendaEditada(const Agenda *agenda)
{
    FILE *arquivo = fopen("agenda.txt", "w"); //Abre o txt como modo de escrita
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de agenda.\n");
        return;
    }

    fprintf(arquivo, "\t%s.\nCodigo da agenda: %d.\nTotal de contatos:%d.\n", agenda->nomeAgenda, agenda->codigo, agenda->numContatos); //Escreva as infornmações sobre a agenda, nome da agenda, cod e total de contatos

    for (int i = 0; i < agenda->numContatos; i++)
    {
        Contato c = agenda->contatos[i];
        fprintf(arquivo, "\nNome: %s\nIdade: %d\nTelefone: %s\nEmail: %s\n", c.nomeCtt, c.idade, c.telefone, c.email); //Passa as informações sobre os contatos
    }

    fclose(arquivo); //Fecha o arquivo txt
}

// Função para buscar um contato pelo nome
int buscarContato(const Agenda *agenda, const char nomeBusca[])
{
    for (int i = 0; i < agenda->numContatos; i++)
    {
        if (strcmp(agenda->contatos[i].nomeCtt, nomeBusca) == 0)
        {
            return i; // Retorna o índice do contato encontrado
        }
    }
    return -1; // Retorna -1 se o contato não for encontrado
}

//Função para listar as informações do contato que foi pesquisado
void listarContatoBusca(const Contato *contato)
{
    printf("Nome: %s\n", contato->nomeCtt);
    printf("Idade: %d\n", contato->idade);
    printf("Telefone: %s\n", contato->telefone);
    printf("Email: %s\n", contato->email);
}

// Função para editar um contato
void editarContato(Agenda *agenda, const char nomeBusca[])
{
    int indice = buscarContato(agenda, nomeBusca); //Utiliza a função buscarContato para encontrar o indico do contato

    if (indice != -1)
    {
        //Encontra o contato pelo indice e ler as novas informações sobre o contato
        Contato *contato = &agenda->contatos[indice];
        printf("Novo nome: ");
        scanf("%s", contato->nomeCtt);
        printf("Nova idade: ");
        scanf("%d", &contato->idade);
        printf("Novo telefone: ");
        scanf("%s", contato->telefone);
        printf("Novo email: ");
        scanf("%s", contato->email);

        salvarAgendaEditada(agenda); // Atualiza o arquivo após a edição
        printf("Contato editado com sucesso.\n");
    }
    else
    {
        printf("Nao existe contato com esse nome.\n"); //informação caso o contato não seja encontrado
    }
}
