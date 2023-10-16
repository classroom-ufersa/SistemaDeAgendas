#include "agenda.c" 
#include "agenda.h"

int main()
{
    Agenda minhaAgenda; //Criando uma variavel minhaAgenda do tipo agenda
    strcpy(minhaAgenda.nomeAgenda, "SCHEDULE"); //repassando e copiando um nome para a agenda
    minhaAgenda.codigo = 1234; //Definindo codigo para a agenda
    minhaAgenda.numContatos = 0; //Inciando o tatal de contatos com ZERO contatos
    minhaAgenda.contatos = (Contato *)malloc(100 * sizeof(Contato)); // Alocando dinamicamente memória para o campo contatos usando malloc,
                                                                     //assumindo um limite de 100 contatos.

    // Carregar a agenda a partir do arquivo (se existir)
    carregarAgenda(&minhaAgenda);
    //Definindo variaveis que vão servir para armazenar o nome que deseja remover, editar ou buscar
    char nomeRemover[50];
    char nomeEditar[50];
    char nomeBusca[50];
    int opcao;

    //Inficiando o loop para apresentar o menu de opções 
    do
    {
        system("cls");
        printf("Menu da Agenda:\n");
        printf("1. Adicionar contato\n");
        printf("2. Remover contato\n");
        printf("3. Listar contatos cadastrados\n");
        printf("4. Editar contato\n");
        printf("5. Buscar contato\n");
        printf("6. Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        //Dentro do loop a estrutura switch que vai servir para realizar diferentes ações
        switch (opcao)
        {
        case 1: //Opção para adicionar um contato na agenda, chando a função adicionarContato
            adicionarContato(&minhaAgenda);
            system("pause");
            break;
        case 2: //Opção para remover um contato da agenda, que passa para a função removerContato o nome para ser removido
            printf("Digite o nome do contato para ser removido: ");
            scanf("%s", nomeRemover);
            removerContato(&minhaAgenda, nomeRemover);
            system("pause");
            break;
        case 3: //opção para listar os contatos que foram cadastrados naquela rodada
            listarContatos(&minhaAgenda);
            system("pause");
            break;
        case 4: //Opção para editar um contato ja existente da agenda, chamando a função editarContato
            printf("Digite o nome do contato para ser editado: ");
            scanf("%s", nomeEditar);
            editarContato(&minhaAgenda, nomeEditar);
            system("pause");
            break;
        case 5: //Opção para buscar um contato na agenda, nome é buscado pelo indice
            printf("Digite o nome do contato para ser buscado: ");
            scanf("%s", nomeBusca);
            int indice = buscarContato(&minhaAgenda, nomeBusca);
            if (indice != -1)
            {
                system("cls");
                printf("Contato encontrado:\n");
                listarContatoBusca(&minhaAgenda.contatos[indice]); 
            }
            else
            {
                printf("Nao existe contato com esse nome.\n");
            }
            system("pause");
            break;
        case 6://Opção sair, aparece a mendagem quando sai do progama
            system("cls");
            printf("Pronto, voce saiu da agenda!\nAte mais.");
            break;
        default: //Apresenta a mensagem caso seja digitado uma opção que não seja de 1 á 6.
            printf("Opcao invalida, tente novamente.\n");
            system("pause");
        }
    } while (opcao != 6); //Loop até ser digitado uma opção coerente entre as fornecidas

    // Liberar a memória alocada para os contatos
    free(minhaAgenda.contatos);

    return 0;
}