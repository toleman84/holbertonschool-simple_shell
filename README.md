## Readme File

The README should explain the following:
•	What the Shell does (1 point)
•	How to compile it (1 point)
•	How to use it (./hsh [arg...] or something like that is expected) (1 point)


## SHELL

The Unix Shell is a command line interpreter (C.L.I), providing a command line user interface. The user uses the keyboard, to type some commands into the operating system. Basically, a shell does have three steps:

    •	Initialization:
    The shell reads the inputs and executes the configuration files.

    •	Interpretation:
    During this step, the shell uses the stdin inputs, to analyze and execute the program.

    •	Terminate:
    In this last step, all the commands have been executed, this is the last step before the end of the program, therefore any memory storage is going to be freed, and the shell will be terminated.


## COMPILATION

Shell will be compiled this way:
```gcc
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Execute

To execute commands, the shell uses a prompt.
The prompt open’s up and displays the following static signal:
```
#cisfun$
```
waiting for the user’s inputs.

Some commands lines such as:

* ls,
* ls  -l,
* /tmp,
* pwd,

can be passed to improve the efficiency of our simple_shell.
To exit the simple_shell program, type in:
*   exit, or
*   ctrl + D.


## Valgrind


•	Valgrind will report memory leaks of memory, (memory allocation without freeing the buffer at the end of the process). We can manage this because the process will not crash.

    •	And memory errors are more sensitive situations and must be solved in a short time.
    Because a lack of memory allocation size can generate a loss of information,linked to the use of uninitialized memory or Reading/Writing memory after it has been freed or Reading/Writing off the end of malloc used. (https://en.wikipedia.org/wiki/Valgrind).

## How to install Valgind  


    sudo apt install valgind

    how to run valgrind

        --leak-check=full (show details about the leaks)
        --show-leak-kinds=all (full report about the leaks)
        --track-origins=yes (find origin of uninitialized values)
        --verbose (Give informations about unusual behavoir of the program)
        --log-file=valgind-out.txt (To write a file)



## HSH 

We will use HSH, the Haskell shell infrastructure.
HSH will be used for testing purposes, in interactive mode, and non-interactive mode.
shell should work like this:
#####   in interactive mode:
```hsh
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
#####   0In non-interactive mode:
```hsh
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
```
```shell
$ cat test_ls_2
/bin/ls
/bin/ls
```
```shell
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```


## Tasks

### 0. README, man, AUTHORS
•	Write a README
•	Write a man for your shell.
•	You should have an AUTHORS file at the root of your repository, listing all individuals have contributed content to the repository. Format, see Docker

### 1. Betty would be proud

Write a beautiful code that passes the Betty checks

### 2. Simple shell 0.1

Write a UNIX command line interpreter.
Usage: simple_shell Shell should:

Display a prompt and wait for the user to type a command.
A command line always ends with a new line.

The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections, or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.

If an executable cannot be found, print an error message and display the prompt again.

Handle errors.

You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:
use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
execve will be the core part of your Shell, don’t forget to pass the environ to it…
```shell
julien@ubuntu:~/shell$ ./shell
#cisfun$ ls
./shell: No such file or directory
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#cisfun$ exit
./shell: No such file or directory
#cisfun$ ^C
julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ julien@ubuntu:~/shell$
```

### 3. Simple shell 0.2
>Simple shell 0.1 +
*   Handle command lines with arguments


### 4. Simple shell 0.3
>Simple shell 0.2 +
 Handle the PATH

*  fork must not be called if the command doesn’t exist

```shell
julien@ubuntu:~/shell$ ./shell_0.3
:) /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls -l /tmp
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
:) ^C
julien@ubuntu:~/shell$
```
### 5. simple shell 0.4

>Simple shell 0.3 +
*   Implement the exit built-in, that exits the shell.
*   Usage: exit.
*   You don’t have to handle any argument to the built-in exit.


### 6. Simple shell 1.0
>Simple shell 0.4 +
*   Implement the env built-in, that prints the current environment

```shell
julien@ubuntu:
~/shell$ ./simple_shell
$ env
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
julien@ubuntu:~/shell$
```

### 7. What happens when you type `ls -l *.c` in the shell

*   Write a blog post describing step by step what happens when you type      ls -l *.c   and hit Enter in a shell.
    Try to explain every step you know of, going in as much details as you     can, give examples and draw diagrams when needed

*   You should merge your previous knowledge of the shell with the            specifics of how it works under the hoods (including syscalls).

*   Have at least one picture, at the top of the blog post. Publish your     blog post on Medium or LinkedIn. Share your blog post at least on         LinkedIn

*   Only one blog post by team. The blog post must be done and published      before the first deadline (it     will be part of the manual review).

*   Please, remember that these blogs must be written in English to           further your technical ability in a variety of settings
    When done, please add all urls below (blog post, LinkedIn post, etc.)


### 8. Test suite
>advanced
Contribute to a test suite for your shell.
This is a task shared by everyone in the class.

Every team (who contributed) will get the same score for this task (The repository owner will not get more points)

You have to be pro-active and agree on one and unique repository to use for the test suite
Please provide the link to the repository you contributed to

Your contribution must be relevant (Correcting typos is nice and always appreciated on the open source sphere, but we won’t consider this a contribution at this point, unless it fixes a bug)
Guidelines for your test suite repository:

The test suite should cover every tasks from 0. to 20.
The test suite should cover every regular cases (many different examples) and possible edge cases

The entire class should work on the same test suite. Use only one repository (don’t forget the README.md file)

Start adding tests ASAP and not just before the deadline in order to help everyone from day 0.

You can take (or fork) inspiration from this example, but it is not mandatory to follow this format/way
Adopt a style and be consistent. You can, for example, follow this style guide.

If you choose a style that already exists, add it to the README.md in a style section. If you write your own, create a Wiki page attached to the project and refer to it in the README.md style section.

If you choose to use this code, make sure to update the style accordingly
You should have an AUTHORS file, listing all individuals having contributed content to the repository. Format, see Docker
Go teams!

### 9. Simple shell 0.1.1
>advanced
Simple shell 0.1 +
Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call.
You will need to use static variables
. You are not allowed to use getline
You don’t have to:  be able to move the cursor.


### 10. Simple shell 0.2.1
>advanced
Simple shell 0.2 +
You are not allowed to use strtok


Repository Description

-
--
---

General

-

---
---

Output
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)


---
---

Authors

Nahuel Silva -

Gustavo Ponce Marsiglia -

--

