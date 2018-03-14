#ifndef ALUMNO_H
#define ALUMNO_H
#include <string>
#include <fstream>
#include <ostream>
using namespace std;
class Alumno{
private:
  string nombre, cuenta, carrera;
  int edad;
public:
  Alumno();
  Alumno(string, string, string,int);

  void write(ofstream&);
  void read(ifstream&);
  int getEdad(){return edad;}
  int operator+(Alumno&);
  //bool operator==(Alumno&); y asi con algunos operadores


  friend ostream& operator << (ostream&, const Alumno&);
  friend istream& operator >> (istream&, Alumno&);
};
#endif
