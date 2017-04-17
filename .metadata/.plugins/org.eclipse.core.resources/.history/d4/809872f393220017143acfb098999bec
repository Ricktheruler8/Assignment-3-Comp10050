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
struct slot *foundSlotsNear;
struct slot *foundSlotsFar;
bool explored[BOARD_SIZE][BOARD_SIZE];
int count =0;
int near = 1;
int far = 5;
int nearTracker = 0;
int farTracker = 0;

void scoutPlayer(int row, int column, struct slot * upLeft, struct slot * upRight, struct slot * downLeft, struct slot * downRight){


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

	foundSlotsNear = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(struct slot ));
	//printf("\n\nFunction findSlotsinvoked:\n");

	if(currSlot!= NULL){

		findSlots(near,0, currSlot, foundSlotsNear, &count, explored);

		for(size_t i=0; i<count; i++){

			if(foundSlotsNear[i].counter == 0){

				//printf("There are no enemies for a near attack\n");
			}
			else if(foundSlotsNear[i].counter == 1){

				int enemy = foundSlotsNear[i].Slot_Tag;
				int enemyRow = foundSlotsNear[i].row;
				int enemyCol = foundSlotsNear[i].column;

				printf("Enemy found for near attack\nLocation: (%d, %d)\nEnemy: player[%d]", enemyRow,enemyCol,enemy);
				fflush(stdout);
			}
		}
	}
	//free(foundSlotsNear);

	foundSlotsFar = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(struct slot ));
		//printf("\n\nFunction findSlotsinvoked:\n");

		if(currSlot!= NULL){

			findSlots(far,2, currSlot, foundSlotsFar, &count, explored);

			for(size_t i=0; i<count; i++){

				if(foundSlotsFar[i].counter == 0){


					//printf("There are no enemies for a far attack\n");
				}
				else if(foundSlotsFar[i].counter == 1 && foundSlotsFar[i].row != row && foundSlotsFar[i].column != column){

					int enemy = foundSlotsFar[i].Slot_Tag;
					int enemyRow = foundSlotsFar[i].row;
					int enemyCol = foundSlotsFar[i].column;

					printf("Enemy found for far attack\nLocation: (%d, %d)\nEnemy: player[%d]\n", enemyRow,enemyCol,enemy);
					fflush(stdout);
				}
			}
		}
		//free(foundSlotsFar);
}

