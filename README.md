Readme File

--

Repository Description

--

General


--

Compilation
Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


--

Output
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)


--

Testing

Your shell should work like this in interactive mode:

	$ ./hsh
	(Eshell) $ /bin/ls
	hsh main.c shell.c
	(Eshell) $
	(Eshell) $ exit
	$


But also in non-interactive mode:

	$ echo "/bin/ls" | ./hsh
	hsh main.c shell.c test_ls_2
	$
	$ cat test_ls_2
	/bin/ls
	/bin/ls
	$
	$ cat test_ls_2 | ./hsh
	hsh main.c shell.c test_ls_2
	hsh main.c shell.c test_ls_2
	$


--

Examples

	ls [OPTIONS]... - list directory contents.

	(Eshell) $ ls
	AUTHORS  execmd.c  get_location.c  hsh  main.c  main.h  man_1_simple_shell  README.md


	echo [SHORT-OPTION]... [STRING]... - display a line of text.

	(Eshell) $ echo Hello World
	Hello World


	pwd [OPTION]... - print name of current/working directory.

	(Eshell) $ pwd
	/holbertonschool-simple_shell


	Ctrl + D [OPTIONS..] - exit the program.

	(Eshell) $ ^D
	(Eshell) $ Exiting shell....


--

Authors
Nahuel Silva -
Gustavo Ponce Marsiglia -
