all:
	gcc main.c ./sources/caverna.c ./sources/utilitarios.c -o ./bin/exe
	./bin/exe