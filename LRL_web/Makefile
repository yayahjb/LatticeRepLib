all: lrl_web.cgi

lrl_web.cgi: lrl_web.o do_posix_spawn.o
	g++ -g -o lrl_web.cgi lrl_web.o do_posix_spawn.o -l cgicc

lrl_web.o: lrl_web.cpp
	g++ -g -c lrl_web.cpp

do_posix_spawn.o: do_posix_spawn.c
	gcc -g -c do_posix_spawn.c

