#include "environnement.h"

static volatile int luminosite_environnement = 200;

static volatile int water_level = 3000;//niveau d'eau en mL 

static volatile int grain_level = 50;//niveau de grain en cM (il serait mesuré en réel avec un capteur à ultrason par exemple (moins cher que une balance)

int getLumEnv(){
  return luminosite_environnement;
}


void *threadLum(void *_arg){
  int A = 1000;
  int t=0;
  int T = 24000; //periode signal en ms
  int Te=T/20;
  float pul = 2*M_PI/T;//pulsation
  while(1){
    luminosite_environnement = A+(int)(A*sin(pul*t));
    //cout<<"lum réel : "<<luminosite_environnement<<"val sin: "<<(A*sin(pul*t))<<endl;
    t=t+Te;
    sleep(1);
  }
}

int getWaterEnv(){
  return water_level;
}

void setWaterEnv(){
  water_level = 10000;
}

void *threadWater(void *_arg){
  while(1){
    water_level = water_level-250 ;//pour simuler la consommation d'eau par les poules
    sleep(1);
  }
}

int getGrainEnv(){
  return grain_level;
}

void setGrainEnv(){
  grain_level = 50;
}

void *threadGrain(void *_arg){
  while(1){
    grain_level = grain_level-3 ;//pour simuler la consommation de grain par les poules
    sleep(1);
  }
}

void initEnv(){
  pthread_t thLum;
  pthread_t thWat;
  pthread_t thGrain;
  int A;
  if (pthread_create(&thLum, NULL, threadLum, (void *)&A))
  {
    cout<<"error thread lum"<<endl;
  }
  if (pthread_create(&thWat, NULL, threadWater, (void *)&A))
  {
    cout<<"error thread water"<<endl;
  }
  if (pthread_create(&thGrain, NULL, threadGrain, (void *)&A))
  {
    cout<<"error thread grain"<<endl;
  }
}
