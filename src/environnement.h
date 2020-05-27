#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <pthread.h>
#include <cmath>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int getLumEnv();

void *threadLum(void *_arg);

int getWaterEnv();

void setWaterEnv();

void *threadWat(void *_arg);

int getGrainEnv();

void setGrainEnv();

void *threadGrain(void *_arg);

void initEnv();

class Poule{
private : 
  int faim;
  int soif;
  static int consoGrainTot;
  static int consoEauTot;
public :
  Poule();
  Poule(int grain, int eau);
  static void Run();
  static void Picorent();// throw(string);
  static void Boivent();// throw(string);
  int getFaim();
  int getSoif();

};

  Poule operator+(Poule Pa, Poule Pb);
  //retourne une poule qui aura comme faim et soif une moyenne de la faim et de la soif de ses "parents".




#endif 
