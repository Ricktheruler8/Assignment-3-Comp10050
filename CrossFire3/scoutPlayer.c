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
int near = 1;
int far = 5;
void scoutPlayer( int * enemyNcount, int * enemyFcount, struct Player *player,struct slot *foundSlots, struct slot *foundSlotsFar, struct enemy *foundEnemies, struct slot * upLeft, struct slot * upRight, struct slot * downLeft, struct slot * downRight){


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

	/*struct enemy{

		int enemyRow;
		int enemyCol;
		int enemyTag;
		int near_Far;
	};*/

	if(currSlot!= NULL){


			count = 0; // initialize count to 0 on every function call. Errors occurring with count stacking on each function call eventually going beyond memory bounds of foundSlots causing errors. Took a day to find this bug :(

			findSlots(near, 0, currSlot, foundSlots, &count, explored);

			printf("\nCOUNT: %d\n",count);// was used to find bug in this function ^ above for details

			for(size_t i=0; i<count; i++){


				if(foundSlots[i].counter == 1){ //&& foundSlots[i].row != row && foundSlots[i].column != column){ //&& ((foundSlotsFar[i].row == row+1) || (foundSlotsFar[i].column == row-1) || (foundSlotsFar[i].column == column+1) || (foundSlotsFar[i].column == column-1))){

					printf("\nEnemy found for near attack\nLocation: (%d, %d)\nEnemy: player[%d]\n", foundSlots[i].row, foundSlots[i].column, foundSlots[i].Slot_Tag);
					fflush(stdout);

					foundEnemies[i].enemyRow = foundSlots[i].row;
					foundEnemies[i].enemyCol = foundSlots[i].column;
					foundEnemies[i].enemyTag = foundSlots[i].Slot_Tag;
					foundEnemies[i].near_Far = 1;
					enemyNcount += 1;
				}
			}

			count = 0; // initialize count to 0 on every function call. Errors occurring with count stacking on each function call eventually going beyond memory bounds of foundSlots causing errors. Took a day to find this bug :(

			findSlots(far, 1, currSlot, foundSlotsFar, &count, explored);

			printf("\nCOUNT: %d\n",count);// was used to find bug in this function ^ above for details

			for(size_t i=0; i<count; i++){


				if(foundSlotsFar[i].counter == 1 && foundSlotsFar[i].row != row && foundSlotsFar[i].column != column && (foundSlotsFar[i].row > row+1 || foundSlotsFar[i].column < row-1 || foundSlotsFar[i].column > column+1 || foundSlotsFar[i].column < column-1)){

					printf("\nEnemy found for far attack\nLocation: (%d, %d)\nEnemy: player[%d]\n", foundSlotsFar[i].row, foundSlotsFar[i].column, foundSlotsFar[i].Slot_Tag);
					fflush(stdout);

					foundEnemies[i].enemyRow = foundSlots[i].row;
					foundEnemies[i].enemyCol = foundSlots[i].column;
					foundEnemies[i].enemyTag = foundSlots[i].Slot_Tag;
					foundEnemies[i].near_Far = 2;
					enemyFcount += 1;

				}
			}
	}
}

