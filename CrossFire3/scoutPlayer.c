/*
 * scoutPlayer.c
 *
 *  Created on: 14 Apr 2017
 *      Author: richie
 */
#include <stdio.h>
#include <stdlib.h>
#include "crossops.h"

struct slot* currSlot = NULL;

bool explored[BOARD_SIZE][BOARD_SIZE];
int count =0;
const int far = 4;

void scoutPlayer(struct Player *player,struct slot *foundSlots, struct slot * upLeft, struct slot * upRight, struct slot * downLeft, struct slot * downRight){


	int row = player->pRow;
	int column = player->pCol;

	if(row >= BOARD_SIZE/2){
		if(column >= BOARD_SIZE/2)
			currSlot = reachDesiredElement(row,column,downRight);
		else

			currSlot = reachDesiredElement(row,column,downLeft);
	} else {

		if(column >= BOARD_SIZE/2)
			currSlot = reachDesiredElement(row,column, upRight);

		else currSlot = reachDesiredElement(row,column,upLeft);
	}

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE;j++){
			explored[i][j] = false;
		}
	}

	//printf("\n\nFunction findSlotsinvoked:\n");

	if(currSlot!= NULL){

		count = 0; // initialize count to 0 on every function call. Errors occurring with count stacking on each function call eventually going beyond memory bounds of foundSlots causing errors. Took a day to find this bug :(

		findSlots(far,0, currSlot, foundSlots, &count, explored);

		//printf("\nCOUNT: %d\n",count); was used to find bug in this function ^ above for details

		for(size_t i=0; i<count; i++){

			printf("\n%zd\n",i);

			if(foundSlots[i].counter == 1 && foundSlots[i].row != row && foundSlots[i].column != column){

				printf("\nEnemy found for attack\nLocation: (%d, %d)\nEnemy: player[%d]\n", foundSlots[i].row, foundSlots[i].column, foundSlots[i].Slot_Tag);
				fflush(stdout);

			}
		}
	}
}

