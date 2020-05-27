#include "environnement.h"


/*Variable globale représentant la luminosité de l'environnement en lux 
il serait mesuré en réel avec une photorésistance
dans le simulateur, cette valeur oscille entre 0 et 2000 lux*/
static volatile int luminosite_environnement = 200;

/*Variable globale représentant le niveau d'eau en mL, 
il serait mesuré en réel avec un capteur digital type conduction par exemple 
(vrai si les deux électrodes sont dans l'eau, faux sinon)
dans le simulateur, cette valeur oscille entre 0 et 10000mL (capacité de l'abreuvoir)*/
static volatile int water_level = 3000;

/*Variable globale représentant niveau de grain en cM, 
il serait mesuré en réel avec un capteur à ultrason par exemple 
(moins cher que une balance)
dans le simulateur, cette valeur oscille entre 0 et 50cM de grain (capacité de la mangeoir)*/
static volatile int grain_level = 50;



/*cette fonction est appelé dans le main de board.cpp,
elle permet de lancer l'initialisaiton de tout le simulateur*/
void initEnv(){

  /*le thread suivant va permettre de faire évoluer le niveau de luminosité
  en fonction du temps 
  (sinusoidalement entre 0 et 2000 lux en 24s, cf commentaire threadLum)*/
  pthread_t thLum;
  int A;
  if (pthread_create(&thLum, NULL, threadLum, (void *)&A))
  {
    cout<<"error thread lum"<<endl;
  }

  Poule::Run();

}


//assesseur luminosite_environnement
int getLumEnv(){
  return luminosite_environnement;
}

/*ce thread va faire évoluer la luminosité de l'environnement
de 0 à 2000 lux en suivant une sinusoide de période 24s représentant les 24h d'une journée*/
void *threadLum(void *_arg){
  int A = 1000;//amplitude
  int t=0;
  int T = 24000; //periode signal en ms
  int Te=T/20;//periode échantillonage
  float pul = 2*M_PI/T;//pulsation
  while(1){
    luminosite_environnement = A+(int)(A*sin(pul*t));//on ajoute A ne offset pour que le signal évolue de 0 à 2000 et non de -1000 à 1000
    //cout<<"lum réel : "<<luminosite_environnement<<"val sin: "<<(A*sin(pul*t))<<endl;
    t=t+Te;
    sleep(1);
  }
}

//assesseur water_level
int getWaterEnv(){
  return water_level;
}

//mutateur water_level
void setWaterEnv(){
  water_level = 10000;
}

/*ce thread va faire évoluer le niveau d'eau de l'environnement
en appelant toutes les secondes (cad heure pour le simulateur)
la méthode de classe Boivent() (cf commentaire Boivent) */
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

//assesseur grain_level
int getGrainEnv(){
  return grain_level;
}

//mutateur grain_level
void setGrainEnv(){
  grain_level = 100;
}

/*ce thread va faire évoluer le niveau de grain de l'environnement
en appelant toutes les secondes (cad heure pour le simulateur)
la méthode de classe Picorrent() (cf commentaire Picorrent) */
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



//=====================classe poule====================//

/*les deux variables de classe suivante,
représente la consomation totale en grain et en eau de toutes les poules du poulailler 
(somme de la faim et de la soif de toute les poules créées)*/
int Poule::consoGrainTot = 0;
int Poule::consoEauTot = 0;

/*constructeur sans argument classe poule,
à noter ici que les attribut faim et soif de chaque poul créées
sont ajouté aux varible de classe consoGrainTot et consoEauTot */
Poule::Poule():faim(2), soif(100) {
	consoGrainTot+=2;
	consoEauTot+=100;
}

/*constructeur avec argument classe poule,
à noter ici que les attribut faim et soif de chaque poul créées
sont ajouté aux varible de classe consoGrainTot et consoEauTot */
Poule::Poule(int grain, int eau):faim(grain), soif(eau) {
	consoGrainTot+=grain;
	consoEauTot+=eau;
}


/*cette méthode permet d'initialiser la simulation de la présence de poule dans le poulailler*/
void Poule::Run(){
  /*les 2 threads suivant vont permettre de faire évoluer le niveau de grain et d'eau
	en fonction de la consommation des poules créées*/
  pthread_t thWat;
  pthread_t thGrain;

  //création de poules en précisant leurs attributs
  Poule cotcot1(1, 110);
  Poule cotcot2(3, 140);
  //création de poules sans préciser leurs attributs 
  Poule cotcot4;
  Poule cotcot5;
  Poule cotcot6;
  Poule cotcot7;
  Poule cotcot8;
  Poule cotcot9;
  Poule cotcot10;
  //création d'une poule fille qui a pour parent cotcot1 et cotcot2 grace à la surcharge de l'opérateur '+'
  Poule cotcotFille;
  cotcotFille = cotcot1+cotcot2;
  
  //Cette poule creer un stress sur la consommation d'eau et permet de tester l'"exception eau"
  //Poule cotcotAssoifé(3, 500); 

  //création des thread de gestion du grian et de l'eau
  if (pthread_create(&thWat, NULL, threadWater, (void *)&cotcot1))
  {
    cout<<"error thread water"<<endl;
  }
  if (pthread_create(&thGrain, NULL, threadGrain, (void *)&cotcot1))
  {
    cout<<"error thread grain"<<endl;
  }
}

/*cette méthode de classe est appelé périodiquement par le threadGrain, 
soustrait à grain_level (var global du niveau de grain) la valeur de consoGraintot (variable de classe)
si la quantité de grain ne suffit plus à la consommation des poules, la méthode lance une exception*/
void Poule::Picorent(){
	if (grain_level>=consoGrainTot){
    	//cout<<"elles picorent\n"<<endl;
		grain_level-=consoGrainTot;
	}
	else {
		grain_level=0;
		throw string("elles ne peuvent pas picorer, elles attendent du grain\n");	
	}
}

/*cette méthode de classe est appelé périodiquement par le threadWater, 
soustrait à water_level (var global du niveau d'eau) la valeur de consoEautot (variable de classe)
si la quantité de grain ne suffit plus à la consommation des poules, la méthode lance une exception*/
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

//ascesseur attribut faim
int Poule::getFaim(){
	return faim;
}

//ascesseur attribut eau
int Poule::getSoif(){
	return soif;
}

/*surcharge d'opérateur '+',
retourne une poule qui aura comme faim et soif une moyenne de la faim et de la soif de ses "parents".*/
Poule operator+(Poule Pa, Poule Pb)
{
    Poule pouleFille((int)(Pa.getFaim()+Pb.getFaim())/2,(int)(Pa.getSoif()+Pb.getSoif())/2);
	cout<<"la poule fille à une faim de: "<<pouleFille.getFaim()<<" et une soif de: "<<pouleFille.getSoif()<<endl;
    return pouleFille;
}
