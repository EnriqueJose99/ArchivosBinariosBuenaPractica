#include "alumno.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Alumno::Alumno(){

}
Alumno::Alumno(string pNombre, string pCuenta, string pCarrera, int pEdad){
  nombre = pNombre;
  cuenta = pCuenta;
  carrera = pCarrera;
  edad = pEdad;
}
void Alumno::write(ofstream& out){
  //nombre
  int size = nombre.size();
  out.write(reinterpret_cast<char*>(&size),sizeof(int));
  out.write(nombre.data(), size);

  //cuenta
  size = cuenta.size();
  out.write(reinterpret_cast<char*>(&size), sizeof(int));
  out.write(cuenta.data(), size);

  //carrera
  size =  carrera.size();
  out.write(reinterpret_cast<char*>(&size), sizeof(int));
  out.write(carrera.data(), size);

  //edad es int
  out.write(reinterpret_cast<char*>(&edad), sizeof(int));
}

void Alumno::read(ifstream& in){
  int size;
  in.read(reinterpret_cast<char*>(&size), sizeof(int));
  //buffer de nombre
  char nameBuffer[size];
  in.read(nameBuffer, size);
  nombre = nameBuffer;

  //cuenta
  in.read(reinterpret_cast<char*>(&size), sizeof(int));
  char cuentaBuffer[size];
  in.read(cuentaBuffer, size);
  cuenta = cuentaBuffer;

  //carrera
  in.read(reinterpret_cast<char*>(&size), sizeof(int));
  char carreraBuffer[size];
  in.read(carreraBuffer, size);
  carrera = carreraBuffer;

  //edad
  in.read(reinterpret_cast<char*>(&size), sizeof(int));

}
