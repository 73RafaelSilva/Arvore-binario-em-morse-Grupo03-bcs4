# Arvore-binario-em-morse-Grupo03-bcs4

Projeto educacional da matéria de Resolução de Problemas Esturados em Computação da criação de uma dinamica árvore binária que representa letras e números do Código Morse.

## Explixando atividade
A proposta causa um pouco de estranhameno na leitura, mas no fim das contas é relativamente simples, sendo um sistema com as seguintes caracteristicas
 - Existe uma arvore;
 - Cada nó representa um caracter;
 - baseado no código morse de entrada, a arvore chega no caracter correspondene;
 - '.' significa atual --> filho esquerda;
 - '-' significa atual --> filho direita;

## Estrutura da Arvore


A arvore deve possuir seus nós já mapeados existentes em código devidamente atribuído cada caracter e sua devida posção, onde, por exemplo, quatro movimentações seguidas a esquerda (...) devem resultar em um 'S', e o contrário, onde o sistema recebe um 'S', o sistema deve varrer a arvore em busca so S, encontrálo e fazer o caminho inverso indo até a raiz para retornar o "..." 

### nó

Todos os nós do projeto devem possúir: 

 - Valor do nó;
 - Ponteiro para o filho da esquerda;
 - Ponteiro para o filho da direita;
 - Ponteiro para o no pai
