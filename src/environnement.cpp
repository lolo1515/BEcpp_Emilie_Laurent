#include "environnement.h"

static volatile int luminosite_environnement = 200;//luminosité de l'environnement en lux 

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
    try {
		Poule::Boivent();
	} catch (string const& error){
		cout<<"Error=> "<<error<<endl;
	}
	sleep(1);
  }
}

int getGrainEnv(){
  return grain_level;
}

void setGrainEnv(){
  grain_level = 100;
}

void *threadGrain(void *_arg){
  while(1){
    try {
		Poule::Picorent();
	} catch (string const& error){
		cout<<"Error=> "<<error<<endl;
	}
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
  Poule cotcot2(3, 140);
  Poule cotcotFille;
  cotcotFille = cotcot1+cotcot2;
  Poule cotcot4;
  Poule cotcot5;
  Poule cotcot6;
  Poule cotcot7;
  Poule cotcot8;
  Poule cotcot9;
  Poule cotcot10;

  if (pthread_create(&thWat, NULL, threadWater, (void *)&cotcot1))
  {
    cout<<"error thread water"<<endl;
  }
  if (pthread_create(&thGrain, NULL, threadGrain, (void *)&cotcot1))
  {
    cout<<"error thread grain"<<endl;
  }
}


void Poule::Picorent(){// throw(string){
	if (grain_level>=consoGrainTot){
    	//cout<<"elles picorent\n"<<endl;
		grain_level-=consoGrainTot;
	}
	else {
		//cout<<"elles ne peuvent pas picorer, elles attendent du grain\n"<<endl;
		grain_level=0;
		throw string("elles ne peuvent pas picorer, elles attendent du grain\n");
		
	}
}


void Poule::Boivent(){// throw(string){
	if (water_level>=consoEauTot){
    	//cout<<"elles boivent\n"<<endl;
		water_level-=consoEauTot;
	}
	else {
		//cout<<"elles ne peuvent pas boire, elles attendent de l'eau\n"<<endl;
		water_level=0;
		throw string("elles ne peuvent pas boire, elles attendent de l'eau\n");
		
	}
}

int Poule::getFaim(){
	return faim;
}

int Poule::getSoif(){
	return soif;
}

//retourne une poule qui aura comme faim et soif une moyenne de la faim et de la soif de ses "parents".
Poule operator+(Poule Pa, Poule Pb)
{
    Poule pouleFille((int)(Pa.getFaim()+Pb.getFaim())/2,(int)(Pa.getSoif()+Pb.getSoif())/2);
	cout<<"la poule fille à une faim de: "<<pouleFille.getFaim()<<" et une soif de: "<<pouleFille.getSoif()<<endl;
    return pouleFille;
}
