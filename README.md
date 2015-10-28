# Trabalho 2 SO - Versionamento de arquivos

## Descrição 

Neste trabalho, os grupos irão implementar uma biblioteca de versionamento de arquivos sobre um sistema de arquivo do Linux. As funções providas pela biblioteca deverão ser usadas para abrir, fechar e remover arquivos com versionamento, tomando todos os cuidados em relação à sincronização do acesso aos arquivos.

## Interface a ser implementada

O arquivo <versionfs.h> define as chamadas (similares às chamadas tradicionais fopen, fclose, remove, etc.) que deverão ser implementadas na biblioteca no arquivo <versionfs.c> e acessíveis para os demais programas. A semântica está descrita de forma simplificada nos comentários do arquivo header, mas em termos gerais:

1. Um arquivo pode ter n-1 versões, onde n é um inteiro longo sem sinal.
2. A primeira versão é a versão 1.
3. Uma versão de um arquivo pode ser aberto por várias threads ou processos para leitura ao mesmo tempo.
4. Se uma versão do arquivo está sendo escrito, ele não pode ser aberto por outro processo ou thread na mesma versão e quem chamar a função deve ficar bloqueado.
5. A numeração de versões deve persistir entre reinicializações do sistema.
6. O arquivo original acessado não é mantido, mas sim um link soft para o mesmo no sistema de arquivos com versionamento (explicação em aula).

## Implementação

Sugere-se o uso de locks nos arquivos (flock()), a implementação de um daemon separado para tratar dos locks e versionamento ou ambos. Se for preciso executar um daemon, não esqueça de adicioná-lo ao init do Makefile para ser chamado antes de rodar o primeiro programa.

A comunicação com o daemon pode ser por memória compartilhada, pipes ou troca de mensagem, conforme o grupo preferir. Caso um daemon seja usado, deverá ser multithread.

Sugere-se o uso de subdiretórios ocultos para o usuário com números de versões para manter as diferentes versões de um arquivo. 

Código de inicialização na biblioteca pode ser chamado usando a seguinte construção do GCC:

__attribute__((constructor)) void init_me(void) {
}

## Testes

O programa de testes deve estressar as capacidades do serviço de versionamento, procurando casos extremos onde poderia se esperar falhas. Deve também estar bem documentado. 

## Cronograma



## Referências

* Anatomy of dynamic linux libraries - IBM. http://www.ibm.com/developerworks/library/l-dynamic-libraries/
* Ulrich Drepper. How To Write Shared Libraries. http://www.akkadia.org/drepper/dsohowto.pdf
* Program Library HOWTO. http://tldp.org/HOWTO/Program-Library-HOWTO/miscellaneous.html
