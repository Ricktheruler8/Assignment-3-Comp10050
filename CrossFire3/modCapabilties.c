/*
 * modCapabilties.c
 *
 *  Created on: 2 Apr 2017
 *      Author: richie
 */
#include<stdio.h>
#include"crossops.h"


void ModStr(struct Player *player){ // modifies capabilities based on rules of game

	if(player->Dexterity <50){

		player->Strength -= 10;
	}
	else if(player->Dexterity >=60){

		player->Strength += 10;
	}
}
void ModMag(struct Player *player){ // same  as above^

	if(player->Smartness > 60){

		player->Magic_Skills += 10;
	}
	else if(player->Smartness<=50){

		player->Magic_Skills -= 10;
	}
}
