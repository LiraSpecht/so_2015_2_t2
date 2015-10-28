#ifndef _VERSIONFS_
#define _VERSIONFS_
#include <stdio.h>
/** vfs_fopen abre um arquivo com uma determinada versão, similar a fopen.
  * Se arquivo já existir, estiver aberto  e for aberto para escrita, uma nova versão será criada com
  *   número de versão igual ao último número mais um. Deve falhar se número de versões
  *   excedido.
  * Cuidado com arquivos já abertos para evitar condições de corrida. Pedidos de aberturas para arquivos
  *   com uma determinada versão já aberta devem bloquear até o arquivo ser fechado pelo outro processo
  *   ou thread.
  *
  * \param filename nome do arquivo
  * \param mode modo de abertura
  * \param version versão a abrir, zero se última versão
  * \return file handle para arquivo, NULL se não for possível ou versão não existir
  */

FILE *
  verfs_fopen(const char *filename, const char *mode, unsigned long int version);

/** vfs_close fecha uma versão de arquivo aberto e libera sua escrita e leitura.
  * Se alguém estiver bloqueado esperando pelo arquivo, o primeiro da fila deve ser liberado.
  *
  * \param stream file handle da versão do arquivo a ser fechada
  * \return 0 se sucesso, EOF se não, com código de erro na variável errno de libc
  */
int
  vfs_fclose(FILE *stream);

/** vfs_fcloseall fecha todos os arquivos abertos pelo processo que chama a função.
  * Arquivos abertos por outros processos não devem ser afetados (usar PID!).
  */
void
  verfs_fcloseall(void);

/** vfs_getversions retorna o número de versões que um arquivo possui.
 *
 * \param filename nome do arquivo
 * \return número de versões (0 se nenhuma)
 */
 unsigned long int
  vfs_getversions(const char *filename);


/** vfs_removeversion apaga uma versão específica de um arquivo.
  * Cuidado com arquivos abertos para evitar condições de corrida. Pedidos de
  *   remoção de versões abertas devem bloquear até o arquivo ser fechado pelo
  *   outro processo ou thread.
  *
  * \param filename nome do arquivo
  * \param version versão a abrir, zero se última versão
  * \return 0 se sucesso, 1 se erro
  */

int
  verfs_removeversion(const char *filename, unsigned long int version);


/** vfs_remove apaga todas versões de um arquivo.
* Cuidado com arquivos abertos para evitar condições de corrida. Pedidos de
*   remoção de versões abertas devem bloquear até o arquivo ser fechado pelo
*   outro processo ou thread.
*
* \param filename nome do arquivo
* \return 0 se sucesso, 1 se erro
*/
int
  verfs_removeall(const char *filename);




#endif /* _VERSIONFS_ */
