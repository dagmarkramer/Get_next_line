INTRODUCTION
------------

this is a function which returns a line read from a file descriptor

returns the line that has just been read

if there is nothing else to read or if an error has occurred it should return NULL

main.c is not part of project

this was my 2nd Codam project


UTILISATION
------------

run 'gcc -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c && ./a.out file.txt' to compile and execute

use any buffer size or file
