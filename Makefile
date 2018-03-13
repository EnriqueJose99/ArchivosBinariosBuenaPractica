output: main.o alumno.o
	g++ main.o alumno.o -o output

main.o: main.cpp alumno.h
	g++ -c main.cpp

alumno.o: alumno.cpp alumno.h
	g++ -c alumno.cpp
