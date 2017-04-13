/*
 * main.c
 *
 *  Created on: 2 Apr 2017
 *      Author: richie
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "crossops.h"

char Hill[5]="Hill",Ground[7]="Ground",City[5]="City"; // slot type strings to be used when assigning slot types

int main(void){

	srand(time(NULL));

	int row, column;

			struct slot* currSlot = NULL;
			struct slot *foundSlots;
			bool explored[BOARD_SIZE][BOARD_SIZE];
			int count =0;
			int boardSize = 7;

			//pointer to slot (0,0)
			struct slot *upLeft;

			//pointer to slot (0,boardSize -1)
			struct slot *upRight;

			//pointer to slot (boardSize - 1, 0)
			struct slot *downLeft;

			//pointer to slot (boardSize - 1, boardSize -1)
			struct slot *downRight;


			struct slot ** board = malloc(boardSize * sizeof(struct slot *));

			//Creates the board
			createBoard(BOARD_SIZE,&upLeft, &upRight, &downLeft, &downRight, board);

			getDesiredElement(BOARD_SIZE, &row,&column);


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
				printf("\ncurrSlot %s ",currSlot->Slot_Type);

				foundSlots = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(struct slot ));
				printf("\n\nFunction findSlotsinvoked:\n");

				if(currSlot!= NULL){

					findSlots(REQ_DISTANCE, 0, currSlot, foundSlots, &count, explored);
					for(int i=0; i<count; i++){
						printf("(%d, %d, %s)-> ",foundSlots[i].row, foundSlots[i].column,foundSlots[i].Slot_Type);
					}
				}

				printf("\n(%d, %d) type: %s\n", board[5][3].row,board[5][3].column,board[5][3].Slot_Type);
				fflush(stdout);

	int maxPlayers; // maxPlayers is the variable that the user inputs max 6 used as index size for struct array player

	printf("How many players will play (Maximum 6!)\n"); // prompt user
	fflush(stdout);

	do{ // do while maxPlayers is greater then allowed max players
		scanf("%d",&maxPlayers); // user input stored in max players. set number of players
	}while(maxPlayers>6);

	struct Player player[maxPlayers]; // declare a struct array player with size maxPlayers. See cross.h for struct Player declaration

	for(size_t i=0;i<maxPlayers;i++){ // loop to fill struct type Player_Name

		printf("Please enter name for player %zd\n",i); // prompt user
		fflush(stdout);

		scanf("%s",player[i].Player_Name); // iterates through player array and gives each player a user input name

	}// end loop
	for(size_t i=0;i<maxPlayers;i++){ // loop to fill struct type PLayer_Type

		printf("Please enter player %zd type\n",i);
		fflush(stdout);
		scanf("%s",player[i].Player_Type); // stores Player_Type. Player Type is referenced when distributing player capabilities. NOTE: Types must must entered in the format of Elf,Wizard,Human,Ogre. Capital letter first!!
	} // end of loop

	for(size_t i=0;i<maxPlayers;i++){ // loop iterates through each player and assigns capabilities based on player type

		AssignType(&player[i]); // call to function AssignType. See line 114 of crossFuncts.c.
	} // end loop

	for(size_t i=0;i<maxPlayers;i++){ // prints each players capabilties, name and type.

		printf("Player type is: %s\n",player[i].Player_Type);
		printf("Player Name is: %s\n",player[i].Player_Name);
		printf("Player Life-points: %.1f\n",player[i].Life_Points);
		printf("Dexterity: %d\n",player[i].Dexterity);
		printf("Luck: %d\n",player[i].Luck);
		printf("Magic Skills: %d\n",player[i].Magic_Skills);
		printf("Smartness: %d\n",player[i].Smartness);
		printf("Strength: %d\n",player[i].Strength);
		printf("\n");
	}

	//for Random player assignment to slot, save slot number and position
	for(size_t i=0;i<maxPlayers;i++){ // loop to assign a random slot to player[i]

		int rnd = rand()%6+0; // random number between 0 and 6
		int rnd1 = rand()%6+0; // random number between 0 and 6

		player[i].pRow = rnd;
		player[i].pCol = rnd1;

		int pRow, pCol;

		pRow = player[i].pRow;
		pCol = player[i].pCol;



		printf("Player %s has been assigned to slot(%d, %d) Type: %s\n",player[i].Player_Name, board[pRow][pCol].row, board[pRow][pCol].column, board[pRow][pCol].Slot_Type); // slot[rnd] will be a random index value which will give back a random slot type
		player[i].Current_PosNo = rnd; // stores the random value in player[i].Current_PosNo. This is how will will keep track of where each player is between rounds. will be updated after each turn.
		strcpy(player[i].Current_Pos,board[rnd][rnd1].Slot_Type); // copies slot type to current_position of player. This will be how we keep trck of and modify capabilities according to rules of the game. Will be updated after each turn.

		board[rnd][rnd1].counter = 1; // counter to track if slot is filled with player

		board[rnd][rnd1].Slot_Tag = i; // slot rnd slot tag is assigned i, will be int from 0 to 5 represnting player[0], player[1] etc. keeps track of player present in slot. used for attack function

		if(strcmp(player[i].Current_Pos,Hill)==0){ // modifies player capabilities based on assigned slot type
			 ModStr(&player[i]);
		}
		else if(strcmp(player[i].Current_Pos,City)==0){ // same as above
			ModMag(&player[i]);
		}
	}

	printf("\n");
	for(size_t i=0;i<maxPlayers;i++){ // loop prints values assigned in previous section. Just to make sure everything is working. can be removed in final version.

		printf("Player current position is: (%d, %d) position type: %s\n",player[i].pRow,player[i].pCol,player[i].Current_Pos); // prints current position number and slot type
		fflush(stdout);
	} // end loop

	// Code below Breaks program was trying to implement player movement.

	int control; // control variable for main do while loop if 1 loop continues if > then loop and program stops

	do{ // start of loop to keep program on between moves

		for(size_t i = 0;i<maxPlayers;i++){ // movement loop iterates through each player prompting for either movement or attack if available

			if(player[i].Life_Points<=0.0){ // if player i life points are 0 player is dead move to next player
				printf("\nplayer %zd is dead",i);
				fflush(stdout);
				break;
			}


			int a = player[i].Current_PosNo; // variable a is player i current position number, used throughout this section to move player and attack

					printf("\n"); // used to format printed information makes it easier for user to read
					printf("Current Player: player[%zd]. Where would you like to move?\n",i); // prints current player and prompt
					fflush(stdout);
					printf("\n");

					printf("Player current position is %d",a); // prints current position makes it easier to keep track of position and make a move

					printf("\n");

					printf("Press 1 to move down or 2 to move up or press 3 to attack nearest player\n"); // prompt user
					fflush(stdout);

					int input; // variable for below conditional statements is used for player decision
					scanf("%d",&input); // take user input and store in variable input

					if(input==1){ // moves player down, if slot below is occupied player automatically attacks


						if(player[i].Current_PosNo==19 || player[i].Current_PosNo == 0){ // conditional statement provides player information based on whether either condition is true

							printf("Player position is either 0 or 19, please check position and act accordingly\n i.e. there is no position < 0 or > than 19\n");
						}

						if(slot[a-1].counter==1){ // see line 150 for variable a, a-1 will be slot below player current pos. counter has value of 1 or 0. 1 for player present, 0 for no player present

							printf("Slot[%d] has a player already, you have attacked ",a-1); // if player tried to move to occupied slot attack will happen automatically
							fflush(stdout);

							int b = slot[a-1].Slot_Tag; // SEE line 118 for explanation on slot_Tag. slot[a-1].slot_tag represents player[0] to player[5]. value is stored in variable b which is then used as index value inside call to attack function
							Attack(&player[i],&player[b]);
						}
						else if(slot[a-1].counter==0){ // else counter is 0 meaning no one is present and slot is free to move to.

							strcpy(player[i].Current_Pos,slot[a-1].Slot_Type); // player current pos gets string value of new slot type moved too.
							player[i].Current_PosNo=a-1; // player position number is updated with new pos No.
							slot[a].counter -= 1; // pevious slot[a] counter is returned to 0 leaving slot free for another player.
							slot[a-1].counter += 1; // new slot counter is updated to 1 leaving slot occupied for player attack
							slot[a].Slot_Tag = -1; // previous slot tag is updated back to -1 meaning no player is present to attack
							slot[a-1].Slot_Tag = i; // new slot tag is updated with player number
						}

						ReverseModStr(&player[i]); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
						ReverseModMag(&player[i]); // same ^

						if(strcmp(player[i].Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules
							ModStr(&player[i]); // calls ModStr function NOTE: See CrossFunct.c line 16 for function definition.
						}
						else if(strcmp(player[i].Current_Pos,City)==0){ // same ^
							ModMag(&player[i]); // calls ModMag function NOTE: See CrossFunct.c line 27 for function definition.
						}
					}
						else if(input==2){ // if players wants to move up, everything exactly the same as above


						if(slot[a+1].counter==1){

							printf("Slot[%d] has a player already, you have attacked\n",a+1);
							fflush(stdout);

							int b = slot[a+1].Slot_Tag;
							Attack(&player[i],&player[b]);
						}
						else if(slot[a+1].counter==0){

							strcpy(player[i].Current_Pos,slot[a+1].Slot_Type);
							player[i].Current_PosNo=a+1;
							slot[a].counter -= 1;
							slot[a+1].counter += 1;
							slot[a].Slot_Tag = -1;
							slot[a+1].Slot_Tag = i;
						}

						ReverseModStr(&player[i]);
						ReverseModMag(&player[i]);

						if(strcmp(player[i].Current_Pos,Hill)==0){
							ModStr(&player[i]);
						}
						else if(strcmp(player[i].Current_Pos,City)==0){
							ModMag(&player[i]);
						}
					}

					else if(input==3){ // if player wants to attack

						if(slot[a+1].Slot_Tag==-1 && slot[a-1].Slot_Tag==-1){ // conditional checks if both slots surrounding player are empty

							printf("No player to attack\n");
							fflush(stdout);
						}
						else if(slot[a+1].Slot_Tag>-1 && slot[a-1].Slot_Tag>-1){ // if both slots surounding player are occupied enter compound statement

							printf("You are surrounded!! Which player would you like to attack\n 1 for player below 2 for player above\n"); //tells player they are surrounded
							fflush(stdout);
							int decision; // decision variable
							scanf("%d",&decision); // stores player input in decision variable

							if(decision==1){ // if player chose 1

								int c = slot[a-1].Slot_Tag; // player below will be in position a - 1 where a is player current pos
								Attack(&player[i],&player[c]); // attack player below
							}
							else if(decision==2){ // if 2 same as above except player in slot above will be attacked

								int c = slot[a+1].Slot_Tag; // slot a+1 is slot above current pos of a
								Attack(&player[i],&player[c]); // call attack function
							}
						}
						else if(slot[a+1].Slot_Tag!=-1){ // checks if there is a player in position above if so attack

							int b = slot[a+1].Slot_Tag;
							Attack(&player[i],&player[b]);
						}
						else if(slot[a-1].Slot_Tag!=-1){ // if no player above then attack player below

							int b = slot[a-1].Slot_Tag;
							Attack(&player[i],&player[b]);
						}
					}


					printf("\n");
					printf("New position is %d and slot type is %s\n", player[i].Current_PosNo,player[i].Current_Pos); // prints new position after turn
					fflush(stdout);
					printf("\n");

					printf("\n");

					for(size_t i = 0;i<maxPlayers;i++){ //

						printf("Player %zd current position is: [%d] %s\n",i,player[i].Current_PosNo,player[i].Current_Pos); // prints a list of current player positions after each player turn. makes movement and attack decisions easier
						fflush(stdout);
					}
					printf("\n");
			}

		for(size_t i = 0;i<maxPlayers;i++){ // iterates through each player and prints results for turn just made

			printf("%s (%s, %.1f)\n",player[i].Player_Name,player[i].Player_Type,player[i].Life_Points); // prints name, type and life points according to assignment requirements
			fflush(stdout);
		}
		printf("\n");

		printf("Do you want to continue the game? 1 for Yes 2 for No"); // asks user to continue with game or quit
		fflush(stdout);
		scanf("%d",&control);
		printf("\n");

	}while(control==1); // conitnues game while user chose 1
}