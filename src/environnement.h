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

#endif 
