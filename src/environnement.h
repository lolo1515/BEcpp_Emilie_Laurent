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

void initEnv();

#endif 
