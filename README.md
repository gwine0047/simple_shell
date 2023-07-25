Custom Shell Program
This repository is an ALX PROJECT (https://intranet.alxswe.com/projects/235)This is a custom shell program built in the C programming language. It is designed to provide a command-line interface similar to a traditional shell, but with certain limitations. This README file will guide you through the features, limitations, and usage of the custom shell program.

Features
Command Execution: The custom shell program allows you to execute various commands available in your system, including built-in commands and external programs.



Limitations
Limited Built-in Commands: The custom shell program has a limited set of built-in commands compared to traditional shells. Currently supported built-in commands include cd (change directory) and exit (terminate the shell).

No Shell Variables: The custom shell program does not support the use of shell variables or environment variables. It only operates within its own scope.

Limited Error Handling: Error handling in the custom shell program is minimal. It may not provide detailed error messages or handle all possible error scenarios.

No Scripting Support: The shell does not support scripting capabilities such as conditional statements, loops, or functions.

 Usage
In order to run this program,

Clone This Repo

`` git clone git@github.com:gwine0047/simple_shell.git ``

compile it with

`gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o hsh`.
You can then run it by invoking `./hsh` in that same directory.

To exit the custom shell program, use the exit command or press Ctrl + C.


Command
Basicly every program in `$PATH`
It supports simple commands like `ls`

It handles Path `ls /tmp`

It handles commands with arguments like `ls -l` or `ls -l /var `

It handles command path also like `/bin/ls` and with options path like  `/bin/ls -l /var`

It handle comments **#**
## Examples Command
**Examples**

Username@your-regular-prompt:~$ ./hsh
$ pwd
/home/username/
$ ^D
Username@your-regular-prompt:~$
```
**Example 2**
```
Username@your-regular-prompt:~$ ./hsh
$ ls -l /tmp
-rw------- 1 username username    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 username username    0 Dec  5 12:09 unity_support_test.0
$ ^D
Username@your-regular-prompt:~$
```
### Exmples Builtin

**case env and exit**
```
Username@your-regular-prompt:~$ ./hsh
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$ exit
Username@your-regular-prompt:~$

```
**Case Exit Statue**
```
Username@your-regular-prompt:~$ ./hsh
$ exit 98
Username@your-regular-prompt:~$ echo $?
98
Username@your-regular-prompt:~$

```
Keep Exploring The echo Builtin and history ... Using The Help Builtin

### Also
* Handle Ctrl+C: your shell should not quit when the user inputs ^C
* If no argument is given to cd the command must be interpreted like cd $HOME
* handle the command cd -
* Handle variables replacement
* Handle the $? variable
* Handle the $$ variable
* Handle The Argument file like `./hsh test` Where test is a file filled with command and builtin to excute.
### List of functions and system calls we could use
List of allowed functions and system calls

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    fork (man 2 fork)
    free (man 3 free)
    fstat (man 2 fstat)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    kill (man 2 kill)
    lstat (man 2 lstat)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (man 2 stat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)

### Custom Function (Recreation of Standard Function in C)
 * _strncpy
 * _strlen
 * _putchar
 * _atoi
 * _puts
 * _strcmp
 * _isalpha
 * reverse_call
 * intlen
 * convert_to_char
 * _strcat
 * _strcpy
 * _strchr
 * _strncmp
 * _strdup
 * _memcpy
 * _calloc
 * _realloc
 * _getenv
 * _getline
 * _strtok

Contributions
Contributions to the custom shell program are welcome. If you find any bugs or have suggestions for improvements, please submit an issue or a pull request to the project repository.

License
This custom shell program is released under the MIT License. Feel free to modify and distribute it according to the terms of the license.

Disclaimer
This custom shell program is provided as-is, without any warranty or guarantee of its functionality or suitability for any purpose. Use it at your own risk.

Feel free to customize this README file according to your specific project requirements and additional features. Make sure to include accurate information and instructions to help users understand and utilize your custom shell program effectively.
