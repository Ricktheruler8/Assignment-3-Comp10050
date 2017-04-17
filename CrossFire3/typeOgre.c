/*
 * typeOgre.c
 *
 *  Created on: 2 Apr 2017
 *      Author: richie
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"crossops.h"


void OGRE(struct Player *player){ // Assigns correct stats to ogre type player

	int max=101,min=80; // min and max values used for random numbers

	int rngD = rand()%(max-min)+min;
	int rngL = rand()%31 + 1;
	int rngS = rand()%21 + 1;
	int rngSt = rand()%(max-min)+min;

	player->Life_Points = 100.0;
	player->Dexterity = rngD;
	player->Luck = rngL;
	player->Magic_Skills = 0;
	player->Smartness = rngS;
	player->Strength = rngSt;
}
