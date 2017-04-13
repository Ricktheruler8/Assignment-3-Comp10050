/*
 * slotAdj.c
 *
 *  Created on: 13 Apr 2017
 *      Author: richie
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "crossops.h"

extern char Four[5], down[3], up[3], right[3], left[3], Two[4];

void slotAdj(struct slot ** board){

	for(size_t i = 1; i<6;i++){

		for(size_t j = 1; j<6; j++){

			strcpy(board[i][j].adj,Four);
		}
	}

	for(size_t i = 1;i < 6;i++){

		strcpy(board[0][i].adj,down);

		strcpy(board[6][i].adj,up);

		strcpy(board[i][0].adj,right);

		strcpy(board[i][6].adj,left);
	}

	strcpy(board[0][0].adj,Two);
	strcpy(board[0][6].adj,Two);
	strcpy(board[6][0].adj,Two);
	strcpy(board[6][6].adj,Two);

}
