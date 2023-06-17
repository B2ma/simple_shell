#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stddef.h>
#include <error.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>


extern char **environ;
alias_t *aliases;
#define EOF_CUSTOM -2
char *cmdName;
#define TERMINATE -3
int history;

/**
  * struct list_s - A new struct type defining a linked list.
  * @ptr: pointer to directory path.
  * @next: A pointer to another struct list_s.
  */
typedef struct list_s
{
	char *ptr;
	struct list_s *next;
} list_t;
list_t *add_node_end(list_t **head, char *ptr);
list_t *locate_dir(char *path);

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @cmdName: builtin command.
 * @p_cmd_fn: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *cmdName;
	int (*p_cmd_fn)(char **argv, char **first);
} builtin_t;

/**
 * struct alias_s - aliases struct.
 * @cmdName: The name of the alias.
 * @cmdValue: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *cmdName;
	char *cmdValue;
	struct alias_s *next;
} alias_t;
alias_t *addAliasEnd(alias_t **head, char *cmdName, char *cmdValue);
void print_prompt(int signal);
int process_cmd(char file_path, int *execRet);
void getAlias(char *varName, char *cmdValue);
void printAlias(alias_t *aliases);
ssize_t getline_fn(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **strtok_fn(char *line, char *delim);
char *locate_cmd(char *cmd);
int execute_cmd(char **args, char **first);
void free_list(list_t *head);
int write_error(char **args, int err);
char *envError(char **args);
char *error1(char **args);
char *error2Exit(char **args);
void freeAliasList(alias_t *head);
void free_list(list_t *head);
char *error2Cd(char **args);
char *error2Syntax(char **args);
char *error126(char **args);
char *error127(char **args);
char *intToString(int number);
void lineHandler(char **stream, ssize_t read);
void var_substitute(char **args, int *execRet);
char *locate_args(char *stream, int *execRet);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
char **envCopy(void);
void envFree(void);
char **locate_env(const char *variable);
int _strncmp(const char *s1, const char *s2, size_t n);
int argsCaller(char **args, char **first, int *execRet);
int argsRunner(char **args, char **first, int *execRet);
int argsHandler(int *execRet);
int argsChecker(char **args);
void free_args(char **args, char **first);
char **aliases_substitute(char **args);
int (*loacte_builtin(char *cmd))(char **args, char **first);
int custom_exit(char **args, char **first);
int custom_env(char **args, char __attribute__((__unused__)) **first);
int custom_setenv(char **args, char __attribute__((__unused__)) **first);
int custom_unsetenv(char **args, char __attribute__((__unused__)) **first);
int custom_cd(char **args, char __attribute__((__unused__)) **first);
int custom_alias(char **args, char __attribute__((__unused__)) **first);
int custom_help(char **args, char __attribute__((__unused__)) **first);
void allHelp(void);
void aliasHelp(void);
void cdHelp(void);
void exitHelp(void);
void helpHelp(void);
void envHelp(void);
void setenvHelp(void);
void unsetenvHelp(void);
void historyHelp(void);

#endif
