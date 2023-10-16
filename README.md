# Sistema De Agendas
Projeto 06 - Sistema de agendas.
Este é um sistema de agenda simples usando listas, que permite ao usuário realizar operações com contatos, como adicionar, remover, listar, editar e buscar informações de contatos. O sistema também oferece funcionalidades para salvar e carregar os dados da agenda em um arquivo de texto. Esta documentação fornece uma visão geral das TADs (Tipos Abstratos de Dados) e como usar o sistema.

## agenda.h
É a TAD que possui duas Struct, que são Agenda e Contato, como tambám os protótipos de todas as funções que tem no nosso progama. 

````
typedef struct agenda
{
    char nomeAgenda[50];
    int codigo;
    int numContatos;
    Contato *contatos;
} Agenda;
````

-nomeAgenda: Uma string que representa o nome da agenda.
-codigo: Um número inteiro que identifica a agenda.
-numContatos: Um número inteiro que indica a quantidade de contatos na agenda.
-contatos: Um ponteiro para uma matriz de Contato que contém os detalhes dos contatos.

````
typedef struct contato
{
    char nomeCtt[50];
    int idade;
    char telefone[15];
    char email[50];
} Contato;
````

-nomeCtt: Uma string que representa o nome do contato.
-idade: Um número inteiro que representa a idade do contato.
-telefone: Uma string que representa o número de telefone do contato.
-email: Uma string que representa o endereço de e-mail do contato.

## agenda.c
É a TAD que possui todas as funções e o que ela vai executar dentro do nosso progama.
### Funções
#### 1. adicionarContato(Agenda *agenda)
Permite adicionar um novo contato à agenda. Verifica se a agenda não está cheia (limite de 100 contatos) e solicita as informações do novo contato. Em seguida, ordena a lista de contatos em ordem alfabética e salva os dados atualizados no arquivo.

#### 2. removerContato(Agenda *agenda, char nomeContato[])
Permite remover um contato da agenda com base no nome fornecido como argumento. Desloca os contatos posteriores para preencher o espaço vago e atualiza o arquivo após a remoção.

#### 3. carregarAgenda(Agenda *agenda)
Carrega os dados da agenda a partir do arquivo "agenda.txt" se o arquivo existir. Preenche o nome da agenda, o código, o número de contatos e os detalhes de cada contato.

#### 4. listarContatos(const Agenda *agenda)
Lista todos os contatos na agenda, exibindo seus nomes, idades, números de telefone e endereços de e-mail.

#### 5. salvarAgendaEditada(const Agenda *agenda)
Salva os dados da agenda no arquivo "agenda.txt". Escreve o nome da agenda, o código, o número de contatos e os detalhes de cada contato no arquivo.

#### 6. buscarContato(const Agenda *agenda, const char nomeBusca[])
Busca um contato na agenda com base no nome fornecido como argumento. Retorna o índice do contato encontrado ou -1 se o contato não for encontrado.

#### 7. listarContatoBusca(const Contato *contato)
Lista as informações de um único contato, incluindo nome, idade, número de telefone e endereço de e-mail.

##### 8. editarContato(Agenda *agenda, const char nomeBusca[])
Permite editar as informações de um contato existente na agenda com base no nome do contato fornecido como argumento. Atualiza o arquivo após a edição.

## main.c
A TAD main.c é a funçaõ principal do nosso programa, responsavel por chamar todas as funções e executar as manipulações no arquivo de texto.
O limite máximo de contatos é de 100, conforme especificado na alocação de memória na main.c, pidem o limiti ser alterado dentro do codigo.

# Uso do Sistema
1. Compile os arquivos "agenda.h", "agenda.c" e "main.c" respectivamente, usando um compilador C.
2. Execute o progama resultante.
3. Use o menu iunterativopara realizar as operações desejadas.
4. Os dados da agenda serão salvos automaticamente no arquivo "agenda.txt" e carregados na proxima inicialização.
