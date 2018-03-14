#include "alumno.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void binAlumno();
//sobrecarga de operadores
void writeAlumno();
int main() {
  //binAlumno();
  writeAlumno();
  return 0;
}
void writeAlumno(){
  Alumno* alumno2 = new Alumno("Enrique", "11641068", "Ing.Sistemas Computacionales", 18);
  cout<< *alumno2; // desreferenciarlo con * antes de la instancia 
  delete alumno2;
}

void binAlumno(){
  ofstream alumnos("alumno.bin", ios::binary);
  Alumno* alumno1 = new Alumno("Enrique", "11641068", "Ing.Sistemas", 18);
  alumno1->write(alumnos);
  alumnos.close();
}
