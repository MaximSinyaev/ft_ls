# ft_ls
This School 42 project is the first project from Unix-systems branch.
In this project main goal is to copy utility `ls` from Unix based systems.
This version of ls works like `ls -1`, flag -1 outputs each file/directory
 in its own row.
## Installation
Simply type `make && make clean` in directory with project to install this "demo"
ls version. (`make` for compile together all files and `make clean` to delete 
all binary *.o files)

After installing you can easily use it by `./ft_ls` command.

Flags that you can use with this `ft_ls` are:
`usage: ls [-ARSafglmrst1] [file ...]`
The meaning of flags is same as in original ls.

## Examples
Print content of current directory including hidden files in
list format and sort it by size:
```shell script
> ./ft_ls -laS                                                                                                                                                                                                             [±master ●]
total 256
-rwxr-xr-x   1 aolen  2019  52052 Dec  6 20:43 ft_ls
-rw-r--r--   1 aolen  2019   5014 Dec  6 20:32 complete_list_2.c
-rw-r--r--   1 aolen  2019   4828 Dec  6 20:32 complete_list.c
-rw-r--r--   1 aolen  2019   3624 Dec  6 20:32 ft_ls.c
-rw-r--r--   1 aolen  2019   3304 Dec  6 20:32 print_result.c
-rw-r--r--   1 aolen  2019   3200 Dec  6 20:32 ft_ls.h
-rw-r--r--   1 aolen  2019   3005 Dec  6 20:32 sort_args.c
-rw-r--r--   1 aolen  2019   2676 Dec  6 20:32 sort.c
-rw-r--r--   1 aolen  2019   2493 Dec  6 20:32 additional_funcs.c
-rw-r--r--   1 aolen  2019   2465 Dec  6 20:32 ft_itoa_base.c
-rw-r--r--   1 aolen  2019   2197 Dec  6 20:32 get_flags.c
-rw-r--r--   1 aolen  2019   1989 Dec  6 20:32 Makefile
-rw-r--r--   1 aolen  2019   1907 Dec  6 20:32 print_errors.c
-rw-r--r--   1 aolen  2019   1261 Dec  6 20:32 ft_strndup.c
-rw-r--r--   1 aolen  2019   1056 Dec  6 20:32 ft_strjoin_safe.c
drwxr-xr-x  23 aolen  2019    782 Dec  6 20:52 .
-rw-r--r--   1 aolen  2019    712 Dec  6 20:52 README.md
drwxr-xr-x  15 aolen  2019    510 Dec  6 20:52 .git
drwxr-xr-x  13 aolen  2019    442 Dec  6 20:32 ..
drwxr-xr-x   7 aolen  2019    238 Dec  6 20:48 .idea
drwxr-xr-x   7 aolen  2019    238 Dec  6 20:32 ft_printf
-rw-r--r--   1 aolen  2019     54 Dec  6 20:32 .gitignore
-rw-r--r--   1 aolen  2019     14 Dec  6 20:32 author
```
Print content of `/usr/bin` directory in list format excluding `.` and `..` 
sorted by time without owner username:
```shell script
> ./ft_ls -lgAt /usr/bin                                                                                                                                                                                                   [±master ●]
total 113864
-rwx------   1 wheel   4243472 Nov 17 15:52 macreport
lrwxr-xr-x   1 wheel        33 Aug 30 13:45 norminette -> ../share/norminette/norminette.rb
-rwxr-xr-x   1 wheel    145792 Jul 26 03:20 symbols
-rwxr-xr-x   1 wheel     84480 Jul 26 03:20 heap32
-r-sr-xr-x   1 wheel     76208 Jul 26 03:20 login
-rwxr-xr-x   1 wheel     73728 Jul 26 03:20 chsh
-rwxr-xr-x   1 wheel    159440 Jul 26 03:20 kextutil
-rwxr-xr-x   1 wheel     33776 Jul 26 03:20 hidutil
-rwxr-xr-x   1 wheel    247824 Jul 26 03:20 lsappinfo
...
```

