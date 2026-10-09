# Arvore-binario-em-morse-Grupo03-bcs4

Projeto educacional da matéria de Resolução de Problemas Esturados em Computação da criação de uma dinamica árvore binária que representa letras e números do Código Morse.

## Explixando atividade
A proposta causa um pouco de estranhameno na leitura, mas no fim das contas é relativamente simples, sendo um sistema com as seguintes caracteristicas
 - Existe uma arvore;
 - Cada node representa um caracter;
 - baseado no código morse de entrada, a arvore chega no caracter correspondene;
 - '.' significa atual --> filho esquerda;
 - '-' significa atual --> filho direita;

## Estrutura da Arvore


A arvore deve possuir seus nodes já mapeados existentes em código devidamente atribuído cada caracter e sua devida posção, onde, por exemplo, quatro movimentações seguidas a esquerda (...) devem resultar em um 'S', e o contrário, onde o sistema recebe um 'S', o sistema deve varrer a arvore em busca so S, encontrálo e fazer o caminho inverso indo até a raiz para retornar o "..." 

### node

Todos os nodes do projeto devem possúir: 

 - Valor do node;
 - Ponteiro para o filho da esquerda;
 - Ponteiro para o filho da direita;
 - Ponteiro para o no pai


 # Arvore-binario-em-morse-Grupo03-bcs4

Projeto desenvolvido para a disciplina de Resolução de Problemas Estruturados em Computação, focado na implementação de uma árvore binária dinâmica em linguagem C para tradução bidirecional (codificação e decodificação) entre texto alfanumérico e Código Morse.

---

## Escopo do Projeto

O sistema opera com base em uma árvore binária dinâmica populada em memória a partir de 64 caracteres do padrão Base64 (letras maiúsculas, letras minúsculas, numerais e símbolos especiais). 

A navegação respeita a topologia tradicional:
- **Ponto (`.`):** navega para o node filho à esquerda.
- **Traço (`-`):** navega para o node filho à direita.
- **Espaço simples (` `):** delimita o término de uma letra/símbolo.
- **Barra (`/`):** atua como separador entre palavras completas.

Cada node da estrutura armazena o caractere correspondente, ponteiros para os ramos esquerdo e direito e um ponteiro para o node pai, viabilizando o percurso inverso durante a codificação. O fluxo do sistema conta com um menu interativo com limpeza de terminal e suporte tanto para digitação em console quanto para leitura em arquivos de texto.

---

## Funções dos Arquivos

- **`arvore.h` / `arvore.c`**: Implementa a estrutura da árvore dinâmica, suas alocações, percursos recursivos, codificação, decodificação e exibição hierárquica.
- **`morse.h` / `morse.c`**: Define e expõe a tabela global `TABELA_MORSE` contendo o mapeamento dos 64 caracteres e seus respectivos códigos Morse.
- **`plantacao.h` / `plantacao.c`**: Constrói a raiz inicial e povoa a árvore chamando as inserções a partir da tabela de conversão.
- **`fileservice.h` / `fileservice.c`**: Gerencia a abertura, leitura e processamento seguro dos arquivos de texto `.txt`.
- **`main.c`**: Concentra o fluxo interativo do usuário, menus com subníveis e chamadas de interface no terminal.

---

## Listagem das Funções

### `arvore.c`
- `criar_node(char caracter)`: Aloca dinamicamente a memória de um novo node, zera seus ponteiros e atribui o caractere informado.
- `inserir(MorseNode *raiz, const char *codigo, char caracter)`: Percorre a árvore criando os nodes necessários à esquerda (`.`) ou direita (`-`) e vincula o node pai.
- `buscar_node(MorseNode *raiz, char caracter)`: Realiza uma busca em pré-ordem na árvore para localizar o node correspondente ao caractere desejado.
- `subir_arvore(MorseNode *atual, char *buffer, int *pos)`: Sobe recursivamente pelo ponteiro do node pai identificando se a origem foi à esquerda ou direita para compor o código.
- `inverter_string(char *str)`: Inverte os caracteres de uma string no próprio vetor para ajustar a ordem gerada na subida da árvore.
- `codificar_caractere_pela_arvore(MorseNode *raiz, char c, char *buffer_saida)`: Localiza o caractere na árvore, reconstrói seu caminho Morse e entrega a sequência em formato textual.
- `decodificar_simbolo(MorseNode *raiz, const char *codigo)`: Navega a partir da raiz seguindo os pontos e traços de uma sequência individual e devolve o caractere encontrado.
- `decodificar_texto_morse(MorseNode *raiz, const char *linha, char *resultado, char *erros)`: Processa uma linha inteira em Morse, tratando espaços entre letras, barras de palavras e separando eventuais caracteres inválidos.
- `codificar_texto_para_morse(MorseNode *raiz, const char *texto)`: Converte uma frase completa em texto para sua representação em código Morse separada por espaços e barras.
- `imprimir_arvore_rec(MorseNode *node, int nivel, char direcao)`: Realiza o percurso em ordem simétrica invertida para desenhar a hierarquia horizontal dos nodes no console.
- `exibir_arvore(MorseNode *raiz)`: Configura e inicia a impressão visual completa da estrutura da árvore no terminal.
- `liberar_arvore(MorseNode *raiz)`: Desaloca recursivamente toda a memória alocada dinamicamente para os nodes da árvore.

### `morse.c`
- `obter_codigo_morse(char c)`: Realiza busca sequencial na tabela global e retorna o código Morse estático do caractere informado.

### `plantacao.c`
- `plantar_arvore_morse(void)`: Cria o node raiz e insere todos os registros da tabela de mapeamento dentro da árvore.

### `fileservice.c`
- `decodificar_arquivo_morse(MorseNode *raiz, const char *caminho_arquivo)`: Abre um arquivo com sequência Morse, decodifica seu conteúdo e exibe na tela.
- `codificar_arquivo_texto(MorseNode *raiz, const char *caminho_arquivo)`: Abre um arquivo de texto comum e exibe a codificação resultante em Morse no terminal.

### `main.c`
- `limpar_tela(void)`: Executa o comando de limpeza de tela compatível com Windows e sistemas Unix/Linux.
- `limpar_buffer(void)`: Esvazia o buffer de entrada do teclado para evitar resíduos de quebras de linha nas leituras.
- `menu_terminal(MorseNode *raiz)`: Apresenta o submenu para execução de operações interativas via digitação direta.
- `menu_arquivos(MorseNode *raiz)`: Apresenta o submenu responsável pelo acionamento das rotinas de leitura de arquivos.
- `main(void)`: Ponto de entrada do programa que inicializa a árvore, dispara os menus e executa a liberação de memória ao encerrar.

---

## Como Compilar

Para compilar todo o projeto integrando os módulos via GCC, execute no terminal:

```bash
gcc -Wall -Wextra main.c arvore.c morse.c plantacao.c fileservice.c -o programa_morse

Para executar o binário que será gerado, basta rodar no terminal 

./programa_morse

## Responsáveis pelo projeto

  ### Instituição

    - Pontifícia Universidade Católica do Paraná (PUCPR)

  ### Turma

    - Bacharelado em CiberSegurança (BCS04) - Escola Politécnica - Campus Curitiba

  ### Responsável Dicente 

    - Aramis Hornung Moraes

  ### Acadêmicos

    - Arthur de Mattos Colodel
    - Erick Portes Damasceno Santos
    - Lucas Lauxen Motta
    - Rafael Luiz da Silva



