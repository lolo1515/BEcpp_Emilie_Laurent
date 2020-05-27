#Présentation:
Ce code à été dévellopé par Emilie ESTIVAL et Laurent DEVEZ
dans le cadre du BE de Programmation Orienté Objet de 4°année AE-SE à l'INSA TOULOUSE

Il permet de simuler grossièrement un poullailer et les poules qui s'y trouvent. 
Le poulailler est constitué d'un abreuvoir(water_level), d'une mangeoire(grain_level), 
d'un environnement extérieur(luminosite_environnement) et de poules.
La luminosité de l'environnement oscille sinuosidallement entre 0 et 2000lux
Le niveau d'eau évolue entre 0 et 10000mL en fonction des poules qui se trouvent dans le poulailler.
Le niveau de grain évolue entre 0 et 50cM en fonction des poules qui se trouvent dans le poulailler.

#Utilisation:

Pour compiler et lancer le programme, il vous suffit d'éxécuter le script bash compile_linux.sh,
via la commande: ./compile_linux.sh

Pour ajouter ou retirer des poules du poulailler, veuillez modifier la méthode run() de la classe poule.
Elle se trouve dans environnement.cpp.
Recompileze et relancez avec ./compile_linux.sh
