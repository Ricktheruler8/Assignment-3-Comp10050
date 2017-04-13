/*
 * typeElf.c
 *
 *  Created on: 2 Apr 2017
 *      Author: richie
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"crossops.h"


void ELF(struct Player *player){ // Assigns correct stats to elf type player

	int max=100,min=60,minM=51,maxM=79,minS=70,maxS=100;

	int rngD = rand()%100 + 1;
	int rngL = rand()%(max-min)+min;
	int rngM = rand()%(maxM-minM)+minM;
	int rngS = rand()%(maxS-minS)+minS;
	int rngSt = rand()%50 + 1;

	player->Life_Points = 100.0;
	player->Dexterity = rngD;
	player->Luck = rngL;
	player->Magic_Skills = rngM;
	player->Smartness = rngS;
	player->Strength = rngSt;

}
