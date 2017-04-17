/*
 * typeHuman.c
 *
 *  Created on: 2 Apr 2017
 *      Author: richie
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"crossops.h"

void HUMAN(struct Player *player){ // Assigns correct stats to Human type player max of 300


		int rngD = rand()%101 + 1;
		int rngL = rand()%101 + 1;
		int rngM = rand()%101 + 1;
		int rngS = rand()%101 + 1;
		int rngSt = rand()%101 + 1;

		int sum = rngD+rngL+rngM+rngS+rngSt;

		player->Life_Points = 100.0;
		player->Dexterity=rngD;
		player->Luck=rngL;
		player->Magic_Skills=rngM;
		player->Smartness=rngS;
		player->Strength=rngSt;

		printf("Sum of human is: %d\n",sum);
}
