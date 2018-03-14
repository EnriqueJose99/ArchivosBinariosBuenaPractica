#include "alumno.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void binAlumno();
//sobrecarga de operadores
void writeAlumno();

void addAlumno();
void readAlumno();
int main() {
  //binAlumno();
  writeAlumno();
  readAlumno();

  addAlumno();
  return 0;
}
void writeAlumno(){
  Alumno* alumno2 = new Alumno("Enrique", "11641068", "Ing.Sistemas Computacionales", 18);
  cout<< *alumno2; // desreferenciarlo con * antes de la instancio
  delete alumno2;
}
void addAlumno(){
  Alumno* alumno3 = new Alumno("Enrique", "1212121", "computacion", 33);
  Alumno* alumno4 = new Alumno("enerr", "4444", "dcdc", 56);
  int edad = *alumno3 + *alumno4;
  cout<<"La edad total de los dos alumnos es de: "<< edad<<endl;
  delete alumno3;
  delete alumno4;
}

void binAlumno(){
  ofstream alumnos("alumno.bin", ios::binary);
  Alumno* alumno1 = new Alumno("Enrique", "11641068", "Ing.Sistemas", 18);
  alumno1->write(alumnos);
  alumnos.close();
}
void readAlumno(){
  Alumno* alumno =new Alumno();
  cin >> *alumno;
  cout<< "Los datos son: "<<endl<<*alumno;
  delete alumno;
}
