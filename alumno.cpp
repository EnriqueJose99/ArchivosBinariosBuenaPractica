#include "alumno.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Alumno::Alumno(){
  //carrera = "Ing.Sistemas Computacionales";
  //edad = 18;
}

Alumno::Alumno(string pNombre, string pCuenta, string pCarrera, int pEdad){
  nombre = pNombre;
  cuenta = pCuenta;
  carrera = pCarrera;
  edad = pEdad;
}
int Alumno::operator+(Alumno& rightValue){
  return this -> edad+rightValue.getEdad();
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

ostream& operator<<(ostream& out, const Alumno& student){
  out<<student.nombre<<", "<<student.cuenta<<", "<<student.carrera<<", "<<student.edad<<endl;
  return out;
}

istream& operator>>(istream& in, Alumno& student){
  string buffer;
  //leer una linea de archivo
  getline(in, buffer);
  string parse = " ";
  int parse1 = 0;
  int cont = 0;
  for (int i = 0; i < buffer.size(); i++) {
    if (buffer[i] != ',') {
      parse+=buffer[i];

      /* code */
    }else{
      switch (cont) {
        case 0:
          student.nombre = parse;
          parse = "";
          break;
        case 1:
          student.cuenta = parse;
          parse ="";
        case 2:
          student.carrera = parse;
          parse = "";
        case 3:
          student.edad = parse1;
          parse1 = 0;

      }
      cont++;
    }
  }
}
