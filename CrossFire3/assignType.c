/*
 * assignType.c
 *
 *  Created on: 2 Apr 2017
 *      Author: richie
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"crossops.h"

char str[5]="Ogre",str2[4]="Elf",str3[6]="Human",str4[7]="Wizard",str5[5]="ogre",str6[4]="elf",str7[6]="human",str8[7]="wizard"; // Used in AssignType function NOTE: see line 114

void AssignType(struct Player *player){ // Assigns type to player depending on type picked by player

	if(strcmp(player->Player_Type,str)==0 || strcmp(player->Player_Type,str5)==0){

		OGRE(player);
	}
	else if(strcmp(player->Player_Type,str2)==0 || strcmp(player->Player_Type,str6)==0){ // if player is elf

		ELF(player);
	}
	else if(strcmp(player->Player_Type,str3)==0 || strcmp(player->Player_Type,str7)==0){

		do{ // repeats HUMAN function if sum of capabilities is greater than 300
			HUMAN(player);
			printf("\n");
		}while(player->Dexterity + player->Luck + player->Magic_Skills + player->Smartness + player->Strength > 300);
	}
	else if(strcmp(player->Player_Type,str4)==0 || strcmp(player->Player_Type,str8) ==0){

		WIZARD(player);
	}
}

