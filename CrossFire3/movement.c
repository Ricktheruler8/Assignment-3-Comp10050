/*
 * movement.c
 *
 *  Created on: 15 Apr 2017
 *      Author: richie
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"crossops.h"

char UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd';

void movement(int move,  int row, int column, int pnum, struct slot **board, struct Player *player){

	char walk;

	if(move == 1){

		printf("Press 'w' = up, 's' = down, 'a' = left, 'd' = right");
		scanf("%c%*c",&walk);

		if(walk == UP){;

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == DOWN){

			player->pRow += 1;
			strcpy(player->Current_Pos,board[row+1][column].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row+1][column].Slot_Tag = pnum;
			board[row+1][column].counter = 1;

		}
		else if(walk == LEFT){

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
		else if(walk == RIGHT){

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 2){

		printf("Press 'w' = up, 'a' = left, 'd' = right\n");
		scanf("%c%*c",&walk);

		if(walk == UP){;

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == LEFT){

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
		else if(walk == RIGHT){

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 3){

		printf("Press 's' = down, 'a' = left, 'd' = right\n");
		scanf("%c%*c",&walk);

		if(walk == DOWN){

			player->pRow += 1;
			strcpy(player->Current_Pos,board[row+1][column].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row+1][column].Slot_Tag = pnum;
			board[row+1][column].counter = 1;

		}
		else if(walk == LEFT){

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
		else if(walk == RIGHT){

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 4){

		printf("Press 'w' = up, 'a' = left, 's' = down\n");
		scanf("%c%*c",&walk);

		if(walk == UP){;

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == LEFT){

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
		else if(walk == DOWN){

			player->pRow += 1;
			strcpy(player->Current_Pos,board[row+1][column].Slot_Type);

			board[row][column].Slot_Tag = pnum;
			board[row][column].counter = 0;

			board[row+1][column].Slot_Tag = pnum;
			board[row+1][column].counter = 1;

		}
	}

	else if(move == 5){

		printf("Press 'w' = up, 'a' = left, 'd' = right\n");
		scanf("%c%*c",&walk);

		if(walk == UP){;

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == LEFT){

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
		else if(walk == RIGHT){

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 6){

		printf("Press 's' = down, 'd' = right\n");
		scanf("%c%*c",&walk);

		if(walk == DOWN){

			player->pRow += 1;
			strcpy(player->Current_Pos,board[row+1][column].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row+1][column].Slot_Tag = pnum;
			board[row+1][column].counter = 1;

		}
		else if(walk == RIGHT){

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 7){

		printf("Press 's' = down, 'a' = left\n");
		scanf("%c%*c",&walk);

		if(walk == DOWN){

			player->pRow += 1;
			strcpy(player->Current_Pos,board[row+1][column].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row+1][column].Slot_Tag = pnum;
			board[row+1][column].counter = 1;

		}
		else if(walk == LEFT){

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
	}

	else if(move == 8){

		printf("Press 'w' = up, 'd' = right, \n");
		scanf("%c%*c",&walk);

		if(walk == UP){;

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == RIGHT){

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 9){

		printf("Press 'w' = up, 'a' = left, \n");
		scanf("%c%*c",&walk);

		if(walk == UP){;

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == LEFT){

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
	}
}


