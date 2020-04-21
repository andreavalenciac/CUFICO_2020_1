#include <iostream>
#include <cmath>

 
class Particula{
public:
  int Carga;
  float X,Y,Z;
  float Vx,Vy,Vz;
  float M;
  void SetValues(float,float,float,float,float,float,float,int);
  float Pos_evol(float,float,float,float);
  
  
}Par1,Par2;

void Particula::SetValues(float x,float y,float z,float vx,float vy,float vz,float m, int C)
{
  X=x;
  Y=y;
  Z=z;
  Vx=vx;
  Vy=vy;
  Vz=vz;
  M=m;
  Carga=C;
}

float Particula::Pos_evol(float Fx,float Fy, float Fz,float t){
 
  X=X+(Vx*t)+(0.5*Fx*(t*t)/M);
  Y=Y+(Vy*t)+(0.5*Fy*(t*t)/M);
  Z=Z+(Vz*t)+(0.5*Fz*(t*t)/M);
  Vx=Vx+(Fx*t/M);
  Vy=Vy+(Fy*t/M);
  Vz=Vz+(Fz*t/M);

return 0;
}
int main(){

  float Bz=10.0;
  float k0=8.99e9;
  Par1.SetValues(0.0,0.0,0.0,0.0,0.0,0.0,10.0,1);
  Par2.SetValues(1.0,0.0,0.0,0.0,0.0,0.0,10.0,-1);
  for (int i=0; i<10; i++){

    
      
    float Fx1=Par1.Vy*Bz-k0*(Par1.X-Par2.X)/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),3/2);
    float Fy1=-Par1.Vx*Bz-k0*(Par1.Y-Par2.Y)/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),3/2);
    float Fz1=-k0*(Par1.Z-Par2.Z)/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1/2);

    
    float Fx2=Par2.Vy*Bz+k0*(Par2.X-Par1.X)/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),3/2);
    float Fy2=-Par2.Vx*Bz+k0*(Par2.Y-Par1.Y)/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),3/2);
    float Fz2=k0*(Par2.Z-Par1.Z)/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1/2);
    
    Par1.Pos_evol(Fx1,Fy1,Fz1,0.01);
    Par2.Pos_evol(-Fx2,-Fy2,-Fz2,0.01);

    
    std::cout << Par1.X << " " << Par1.Y  << " " << Par1.Z  << " " <<    Par2.X << " " << Par2.Y  << " " << Par2.Z  << std::endl;
  }
  return 0; }	




