g++ -std=c++11 cstring.c -c -g
g++ -std=c++11 main.c -I../CSTLPlus/container/ -c -g
g++ -std=c++11 -g -I../String ../CSTLPlus/container/map.c -c
g++ -std=c++11  cstring.o main.o map.o -o main.exe  -g