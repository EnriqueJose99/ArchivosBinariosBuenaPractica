#include "alumno.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void binAlumno();
int main() {
  binAlumno();
  return 0;
}

void binAlumno(){
  ofstream alumnos("alumno.bin", ios::binary);
  Alumno* alumno1 = new Alumno("Enrique", "11641068", "Ing.Sistemas", 18);
  alumno1->write(alumnos);
  alumnos.close();
}
