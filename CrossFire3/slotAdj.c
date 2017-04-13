/*
 * slotAdj.c
 *
 *  Created on: 13 Apr 2017
 *      Author: richie
 */

#include<stdio.h>
#include<stdlib.h>
#include "crossops.h"

void slotAdj(struct slot ** board){

	for(size_t i = 1; i<6;i++){

		for(size_t j = 1; j<6; j++){

			board[i][j].adj = 4;
		}
	}

	for(size_t i = 1;i < 6;i++){

		board[0][i].adj = 3;

		board[6][i].adj = 3;

		board[i][0].adj = 3;

		board[i][6].adj = 3;
	}

	board[0][0].adj = 2;
	board[0][6].adj = 2;
	board[6][0].adj = 2;
	board[6][6].adj = 2;

}
