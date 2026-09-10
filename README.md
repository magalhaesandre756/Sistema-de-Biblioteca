# Sistema de Biblioteca

Sistema de gerenciamento de biblioteca desenvolvido em C, com persistência 
dos dados em arquivo `.txt` e menu interativo via terminal.

## Funcionalidades

- **Menu interativo** — interface via terminal com opções de cadastro, 
  consulta, empréstimo, devolução, listagem e saída.
- **Cadastro de livros** — registra novos livros (código, título, autor) 
  no arquivo `.txt`.
- **Consulta de livros** — busca um livro pelo código digitado; percorre 
  o arquivo com um laço `while` e retorna código, título, autor e status 
  (emprestado ou disponível).
- **Empréstimo** — registra o empréstimo de um livro; caso já esteja 
  emprestado, o sistema avisa que ele já foi retirado.
- **Devolução** — marca o livro novamente como disponível.
- **Listagem** — exibe todos os livros cadastrados no arquivo.

## Tecnologias

C, CMake

## Como executar

\`\`\`
mkdir build && cd build
cmake ..
make
./Avaliacao
\`\`\`

## O que aprendi

Manipulação de arquivos em C (leitura e escrita em `.txt`), uso de arquivo 
temporário para atualizar registros (leitura completa, reescrita em 
`temporario.txt` e substituição do arquivo original via `remove`/`rename`), 
estruturas de repetição para busca de registros, e lógica condicional para 
controle de status.
