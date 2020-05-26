#include "environnement.h"

static volatile int luminosite_environnement = 200;

static volatile int water_level = 3000;//niveau d'eau en mL 

static volatile int grain_level = 50;//niveau de grain en cM (il serait mesuré en réel avec un capteur à ultrason par exemple (moins cher que une balance)

int Poule::consoGrainTot = 0;
int Poule::consoEauTot = 0;

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
    //water_level = water_level-250 ;//pour simuler la consommation d'eau par les poules
	//Poule cot = *((Poule *)_arg);
    Poule::Boivent();
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
    //grain_level = grain_level-3 ;//pour simuler la consommation de grain par les poules
   // Poule cot = *((Poule *)_arg);
    Poule::Picorent();
    sleep(1);
  }
}

void initEnv(){
  pthread_t thLum;
  int A;
  if (pthread_create(&thLum, NULL, threadLum, (void *)&A))
  {
    cout<<"error thread lum"<<endl;
  }

  Poule::Run();
  
}

//poules 
//classe poule
Poule::Poule():faim(2), soif(100) {
	consoGrainTot+=2;
	consoEauTot+=100;
}

Poule::Poule(int grain, int eau):faim(grain), soif(eau) {
	consoGrainTot+=grain;
	consoEauTot+=eau;
}

void Poule::Run(){

  pthread_t thWat;
  pthread_t thGrain;

  Poule cotcot1(1, 110);
  Poule cotcot2(2, 140);
  Poule cotcot3;
  Poule cotcot4;
  Poule cotcot5;
  Poule cotcot6;

  if (pthread_create(&thWat, NULL, threadWater, (void *)&cotcot1))
  {
    cout<<"error thread water"<<endl;
  }
  if (pthread_create(&thGrain, NULL, threadGrain, (void *)&cotcot1))
  {
    cout<<"error thread grain"<<endl;
  }

}

void Poule::Picorent(){
	if (grain_level>=consoGrainTot){
    	cout<<"elles picorent"<<endl;
		grain_level-=consoGrainTot;
	}
	else {
		cout<<"elles ne peuvent pas picorer, elles attendent du grain"<<endl;
		grain_level=0;
	}
}

void Poule::Boivent(){
	if (water_level>=consoEauTot){
    	cout<<"elles boivent"<<endl;
		water_level-=consoEauTot;
	}
	else {
		cout<<"elles ne peuvent pas boire, elles attendent de l'eau"<<endl;
		water_level=0;
	}
}
