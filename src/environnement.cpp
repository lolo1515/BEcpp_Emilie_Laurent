#include "environnement.h"

static volatile int luminosite_environnement = 200;

int getLumEnv(){
  return luminosite_environnement;
}


void *threadLum(void *_arg){
  int A = 1000;//*((int *)_arg);
  int t=0;
  int T = 24000; //periode signal en ms
  int Te=T/20;
  float pul = 2*M_PI/T;//pulsation
  while(1){
    luminosite_environnement = A+(int)(A*sin(pul*t));
    cout<<"lum réel : "<<luminosite_environnement<<"val sin: "<<(A*sin(pul*t))<<endl;
    t=t+Te;
    sleep(1);
  }
}

void initEnv(){
  pthread_t thLum;
  int A = 1000;
  if (pthread_create(&thLum, NULL, threadLum, (void *)&A))
  {
    cout<<"error thread lum"<<endl;
  }
}
