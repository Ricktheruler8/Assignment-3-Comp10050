/*
 * reverseCapabilities.c
 *
 *  Created on: 2 Apr 2017
 *      Author: richie
 */
#include<stdio.h>
#include"crossops.h"


void ReverseModStr(struct Player *player){ // reverts capabilities used to stop capability stacking

	if(player->Dexterity <50){

		player->Strength += 10;
	}
	else if(player->Dexterity >=60){

		player->Strength -= 10;
	}
}
void ReverseModMag(struct Player *player){ // same ^

	if(player->Smartness > 60){

		player->Magic_Skills -= 10;
	}
	else if(player->Smartness<=50){

		player->Magic_Skills += 10;
	}
}
