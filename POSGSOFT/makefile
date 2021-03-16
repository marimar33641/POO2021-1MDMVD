all: compilar

compilar: criterio jurado director acta estudiante  folderActas universidad menu main
		g++ -o a criterio.o jurado.o director.o acta.o estudiante.o   folderActas.o universidad.o menu.o main.o
criterio: criterio.cpp criterio.h
		g++ -c criterio.cpp
jurado: jurado.cpp jurado.h
		g++ -c jurado.cpp
director: director.cpp director.h
		g++ -c director.cpp
acta: acta.cpp acta.h
		g++ -c acta.cpp
estudiante: estudiante.cpp estudiante.h
		g++ -c estudiante.cpp

folderActas: folderActas.cpp folderActas.h
		g++ -c folderActas.cpp
universidad: universidad.cpp universidad.h
		g++ -c universidad.cpp
menu: menu.cpp menu.h
		g++ -c menu.cpp
main: main.cpp 
		g++ -c main.cpp