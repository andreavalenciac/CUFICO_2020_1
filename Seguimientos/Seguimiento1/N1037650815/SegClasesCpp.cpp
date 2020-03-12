#include <iostream>
#include <cmath>
using namespace std;






class Particula{
public:
  int Carga;
  float X,Y,Z;
  float VX,VY,VZ;
  float M;
  void SetValues(float,float,float,float,float,float,float,int);
  float Pos_evol(float,float,float,float);
  
  
}Par1,Par2;

void Particula::SetValues(float x,float y,float z,float vx,float vy,float vz,float m, int C)
{
  X=x;
  Y=y;
  Z=z;
  VX=vx;
  VY=vy;
  VZ=vz;
  M=m;
  Carga=C;
  }


float Particula::Pos_evol(float ax, float ay , float az, float t){
  X=sin(t);
  Y=cos(t)-1;
  Z=t;
  return 0;
}

int main(){ 
    
    Par1.SetValues(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1);

   
    // cout << "Carga=" << Par1.Carga << ", x=" << Par1.X  << ", y=" << Par1.Y  << ", z=" << Par1.Z << ", vx="<< Par1.VX << ", vy="<< Par1.VY  << ", vz="<< Par1.VZ << ", M=" << Par1.M << endl;
    
    for (int i=0; i<10000; i++){
      Par1.Pos_evol(1.0,0.0,0.0,i/0.01
		    );

    
      cout <<  Par1.X <<","<< Par1.Y  <<","<< Par1.Z  << endl;}
  return 0;
}
