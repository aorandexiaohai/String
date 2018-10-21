gcc -std=c99 cstring.c -c -g
gcc -std=c99 main.c -I../CSTLPlus/container/ -c -g
gcc -std=c99 -g -I../String ../CSTLPlus/container/map.c -c
gcc -std=c99  cstring.o main.o map.o -o main.exe  -g