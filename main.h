#ifndef _MAIN_H
#define _MAIN_H

#define DIVIDERS " \t\a\\n\r"
#define BUFFER_SIZE 1024

extern char **environ;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h>
#include <stddef.h>
#include <fcntl.h>
#include <linux/limits.h>

typedef struct inbuiltt
{
    char *command;
    int (*function)(char **command_tokens, int state);
} builtin;

/*prompt, command collation and manipulation*/
void print_prompt();
int *fill(void *ptr, int nil, unsigned int size);
void hash(char *input);
char *_getline();
char *transfer(char *to, char *from, unsigned int size);
int command_history(char **command_tokens, int state);
char **parsing(char *command);
void command_exit(char **command_tokens, char *command, int count, char **argv);

/*Memory management*/
void *_realloc(void *pointer, unsigned int old_size, unsigned int new_size);


/*checks*/
int alpha_check(int ch);
int _atoi(char *str);
void command_exit_file(char **command_tokens, char *line, FILE *file_desc);

/*Handlers*/
void write_error(char **argv, int count, char** command_tokens);
char *convert_to_char(unsigned int number);
void reverse_call(char *array, int length);
int length_of_int(int number);


/*Strings*/
void write_in(const char *ch);
int _putchar(char ch);
int _strlen(const char *str);
int _strcmp(char *first, char *second);
char *_strcat(char *to, char *from);
char *_strchr(char *string, char ch);
char *_strdup(char *str);
int _strncmp(const char *first, const char *second, size_t n);
char *_strcpy(char *to, char *from);
void _puts(char *str);

int command_inbuilt(char **command_tokens, int state);
int if_inbuilt(char **command_tokens);
int change_dir (char **command_tokens, __attribute__((unused))int state);

void _free(char **command_tokens, char *command);
char *_getenv(char *file);
int echo_display(char **command_tokens);

void execute_file_command(char *line, int count, FILE *file_ptr, char **commands);
void file_command(char *name, char **commands);
void print_negative(int num);
void print_positive(unsigned int num);
char *create_path(char *command_token, char *token);
int command_path(char **command_tokens);
void print_error(char *command, int count, char **argv);


int execute_command(char **command_tokens, char *command, int count, char **argv);
int store_history(char *command);
int command_env(__attribute__((unused))char **command_tokens, __attribute__((unused))int state);
int command_echo(char **command_tokens, int state);
int command_help(char **command_tokens, __attribute__((unused))int state);
#endif