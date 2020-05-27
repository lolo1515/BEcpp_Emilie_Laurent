# Présentation:
Ce code à été dévellopé par Emilie ESTIVAL et Laurent DEVEZ
dans le cadre du BE de Programmation Orienté Objet de 4°année AE-SE à l'INSA TOULOUSE

Il permet de simuler grossièrement un poullailer et les poules qui s'y trouvent. 
Le poulailler est constitué d'un abreuvoir(water_level), d'une mangeoire(grain_level), 
d'un environnement extérieur(luminosite_environnement) et de poules.
La luminosité de l'environnement oscille sinuosidallement entre 0 et 2000lux
Le niveau d'eau évolue entre 0 et 10000mL en fonction des poules qui se trouvent dans le poulailler.
Le niveau de grain évolue entre 0 et 50cM en fonction des poules qui se trouvent dans le poulailler.

# Utilisation:

Pour compiler et lancer le programme, il vous suffit d'éxécuter le script bash compile_linux.sh,
via la commande: `./compile_linux.sh`

Pour ajouter ou retirer des poules du poulailler, veuillez modifier la méthode Run() de la classe poule.
Elle se trouve dans environnement.cpp.
```cpptools
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
```
Recompilez et relancez avec: 
`./compile_linux.sh`
