#include <unistd.h>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
  //=========projet===========
// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(1, INPUT);
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);


/*=========question===========
// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(4,INPUT);

  pinMode(0,OUTPUT);
  pinMode(3,OUTPUT);*/



}

// la boucle de controle arduino
void Board::loop(){
 //==================projet==================
	
	//déclaration des variables dans lesquelles seront stockées les retours des capteurs
	int lum =0;
	int water = HIGH;
	int grain = 50;
    //déclaration du buffer qui nous servira pour communiquer les informations intrinsèque au poulailler (niveau eau et grain)
	char buf[100];

		//prise des différentes mesures 
		lum = analogRead(1);
		water = digitalRead(3);
		grain = analogRead(5);

		//optionnel, pour débogage
		cout<<"lum: "<<lum<<" lux\n";
		cout<<"grain: "<<grain<<" cM\n"<<endl;

		
		if (lum<400){
			cout<<"il fait nuit\n";
			digitalWrite(2,LOW);		
		}
        /*si la luminosité est supérieur au seuil de 450 lum, on ouvre la porte,
		 l'histérisis est présent car sinon la commande de la porte oscillerai au seuil de luminosité*/
		else if (lum>450){
			cout<<"il fait jour\n";
			digitalWrite(2,HIGH);
		}
	
		/*si le capteur d'eau est conducteur (etat HIGH) cela veut dire que le niveau d'eau dans l'abreuvoir est suffisant,
		 donc on arrete la pompe */
		if(water==HIGH){
			cout<<"il y'a de l'eau\n";
			digitalWrite(4, LOW);
		}
		/*si le capteur d'eau n'est pas conducteur (etat LOW) cela veut dire que le niveau d'eau dans l'abreuvoir est insuffisant,
		 donc on démarre la pompe */
		else{
			cout<<"il y'a pas d'eau, elles ont tout bu\n";
			digitalWrite(4, HIGH);
		}


		//si le niveau de grain dans la mangeoir est supérieur au seuil de 11cm, on ferme la trappe à grain,
        if (grain>11){
			cout<<"il y'a du grain\n"<<endl;
			digitalWrite(6,LOW);		
		}
		/*si le niveau de grain dans la mangeoir est inférieur au seuil de 10cm, on ouvre la trappe à grain,
		l'histérisis est présent car sinon la commande de la trappe oscillerai au seuil de niveau de grain*/
		else if (grain<10){
			cout<<"il n y'a plus de grain, tout a été mangé\n"<<endl;
			digitalWrite(6,HIGH);
		}

			
		/*on communique les informations intrinsèque au poulailler (niveau eau et grain),
		à l'utilisateur par un écran LCD accessible par un bus I2C*/
		sprintf(buf,"niveau grain: %d cM\n", grain);
		bus.write(1,buf,100);
		sprintf(buf,"niveau eau: %s", (water==HIGH)?"OK\n":"trop bas\n");
		bus.write(1,buf,100);

		sleep(1);


//==============question===============
  /*char buf[100];
  int temp = 0;
  int lum = 0;
  int bout = 0;
  static int cpt=0;
  static int bascule=0;
  int i=0;


  for(i=0;i<10;i++){
    //lecture sur la pin 1 : capteur de temperature
    temp=analogRead(1);
    lum=analogRead(2);
    sprintf(buf,"temperature: %d; luminosity: %d",temp, lum);
    Serial.println(buf);
    if(cpt%5==0){
      // toutes les 5 fois on affiche sur l ecran la temperature
      sprintf(buf,"t: %d; l=%d",temp,lum);
      bus.write(1,buf,100);
    }
    cpt++;
    sleep(1);
  }
 
  bout=digitalRead(4);
  // on eteint ou on allume la LED selon l'état du bouton
  if(bout){
    digitalWrite(3,HIGH);
  }
  else{
	digitalWrite(3,LOW);
  }


// on eteint et on allume la LED
  if(bascule){
    digitalWrite(0,HIGH);
    //digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(0,LOW);
	//digitalWrite(3,LOW);
  }
  bascule=1-bascule;*/



  
}


