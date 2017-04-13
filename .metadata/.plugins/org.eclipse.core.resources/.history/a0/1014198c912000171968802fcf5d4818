/*

 * checkAdjSlot.c
 *
 *  Created on: 13 Apr 2017
 *      Author: richie
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "crossops.h"

char Four[5] = "four", down[3] = "DT", up[3] = "UT", right[3] = "RT", left[3] = "LT", Two[4] = "two";

void checkAdjSlot(struct slot **board, int prow, int pcol){

	if(strcmp(board[prow][pcol].adj,Four)==0){

		printf("\nYou have four adjacent slots, possible moves are: ");
		printf("Up (%d, %d, %s), ", prow-1,pcol, board[prow-1][pcol].Slot_Type);
		printf("Down (%d, %d, %s), ", prow+1,pcol,board[prow+1][pcol].Slot_Type);
		printf("Left (%d, %d, %s), ",prow,pcol-1,board[prow][pcol-1].Slot_Type);
		printf("Right (%d, %d, %s)",prow,pcol+1,board[prow][pcol+1].Slot_Type);
	}
	else if(strcmp(board[prow][pcol].adj,up)==0){

		printf("\nYou have three adjacent slots, possible moves are: ");
		printf("Up (%d, %d, %s), ", prow-1,pcol,board[prow-1][pcol].Slot_Type);
		printf("Left (%d, %d, %s), ",prow,pcol-1, board[prow][pcol-1].Slot_Type);
		printf("Right (%d, %d, %s)",prow,pcol+1, board[prow][pcol+1].Slot_Type);
	}
	else if(strcmp(board[prow][pcol].adj,down)==0){

		printf("\nYou have three adjacent slots, possible moves are: ");
		printf("Down (%d, %d, %s), ", prow+1,pcol, board[prow+1][pcol].Slot_Type);
		printf("Left (%d, %d, %s), ",prow,pcol-1, board[prow][pcol-1].Slot_Type);
		printf("Right (%d, %d, %s)",prow,pcol+1, board[prow][pcol+1].Slot_Type);
	}

	else if(strcmp(board[prow][pcol].adj,left)==0){

		printf("\nYou have three adjacent slots, possible moves are: ");
		printf("Up (%d, %d, %s), ", prow-1,pcol, board[prow-1][pcol].Slot_Type);
		printf("Left (%d, %d, %s), ",prow,pcol-1, board[prow][pcol-1].Slot_Type);
		printf("Down (%d, %d, %s)", prow+1,pcol, board[prow+1][pcol].Slot_Type);
	}
	else if(strcmp(board[prow][pcol].adj,right)==0){

		printf("\nYou have three adjacent slots, possible moves are: ");
		printf("Up (%d, %d, %s), ", prow-1,pcol, board[prow-1][pcol].Slot_Type);
		printf("Left (%d, %d, %s), ",prow,pcol-1, board[prow][pcol-1].Slot_Type);
		printf("Right (%d, %d, %s)",prow,pcol+1, board[prow][pcol+1].Slot_Type);
	}
	else if(strcmp(board[prow][pcol].adj,Two)==0 && prow == 0 && pcol == 0){

		printf("\nYou have two adjacent slots, possible moves are: ");
		printf("Down (%d, %d, %s), ", prow+1,pcol, board[prow+1][pcol].Slot_Type);
		printf("Right (%d, %d %s)",prow,pcol+1, board[prow][pcol+1].Slot_Type);
	}
	else if(strcmp(board[prow][pcol].adj,Two)==0 && prow == 0 && pcol == 6){

		printf("\nYou have two adjacent slots, possible moves are: ");
		printf("Down (%d, %d, %s), ", prow+1,pcol, board[prow+1][pcol].Slot_Type);
		printf("Left (%d, %d, %s), ",prow,pcol-1, board[prow][pcol-1].Slot_Type);
	}
	else if(strcmp(board[prow][pcol].adj,Two)==0 && prow == 6 && pcol == 0){

		printf("\nYou have two adjacent slots, possible moves are: ");
		printf("Right (%d, %d, %s)",prow,pcol+1, board[prow][pcol+1].Slot_Type);
		printf("Up (%d, %d, %s), ", prow-1,pcol, board[prow-1][pcol].Slot_Type);
	}
	else if(strcmp(board[prow][pcol].adj,Two)==0 && prow == 6 && pcol == 6){

		printf("\nYou have two adjacent slots, possible moves are: ");
		printf("Left (%d, %d, %s), ",prow,pcol-1, board[prow][pcol-1].Slot_Type);
		printf("Up (%d, %d, %s), ", prow-1,pcol, board[prow-1][pcol].Slot_Type);
	}
}
