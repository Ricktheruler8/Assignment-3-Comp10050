/*
 * typeWizard.c
 *
 *  Created on: 2 Apr 2017
 *      Author: richie
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"crossops.h"


void WIZARD(struct Player *player){ // Assigns correct stats to wizard type player

	int minM=80,maxM=100,minL=50,maxL=100;

	int rngD = rand()%100 + 1;
	int rngL = rand()%(maxL-minL)+minL;
	int rngM = rand()%(maxM-minM)+minM;
	int rngS = rand()%100 + 1;
	int rngSt = rand()%20 + 1;

	player->Life_Points = 100.0;
	player->Dexterity=rngD;
	player->Luck=rngL;
	player->Magic_Skills=rngM;
	player->Smartness=rngS;
	player->Strength=rngSt;
}
