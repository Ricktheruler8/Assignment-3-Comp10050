/*
 * crossops.h
 *
 *  Created on: 10 Apr 2017
 *      Author: richie
 */

#ifndef CROSSOPS_H_
#define CROSSOPS_H_

#define BOARD_SIZE 7
#define REQ_DISTANCE 3

/*
 * Definition of boolean types
 * This avoids using <stdbool.h>
 */
typedef int bool;
enum { false, true };

/*
 * The slot template
 */

struct Player{

		char Player_Name[50];
		char Player_Type[50];
		char Current_Pos[50]; // is assigned slot type for player
		int Current_PosNo; // is assigned number corresponding to index value of slot type e.g. if slot[2].Slot_Type is City, player.Current_Pos will = City and player.Current_Pos will = 2
		float Life_Points; // is assigned 100 for player life points
		int Smartness; // is assigned a value depending on player.Player_Type.
		int Strength; // see ^
		int Magic_Skills; // see ^
		int Luck; // see ^
		int Dexterity; // see ^
		int pRow;
		int pCol;
};

struct slot{
	//row number
	int row;
	//column number
	int column;

	// adjacent left slot
	struct slot *left;
	// adjacent right slot
	struct slot *right;
	// adjacent up slot
	struct slot *up;
	// adjacent down slot
	struct slot *down;

	char Slot_Type[7]; // is assigned a slot type randomly e.g. slot.Slot_Type = "City"

	int Slot_Tag; // used to keep track of who is in what slot

	int counter; // counter used to keep track of if a slot is occupied

	int adj; // slots with adjacency of 4

}slot;


int getBoardSize();

void getDesiredElement(int maxsize, int * row, int * col);

void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight, struct slot **board);


struct slot *  reachDesiredElement(int row, int column, struct slot * initialSlot);


void findSlots(int reqDist, int currDist,  struct slot * currSlot, struct slot * foundSlots, int * count,  bool explored[7][7]);
void ELF(struct Player *player);
void WIZARD(struct Player *player);
void HUMAN(struct Player *player);
void OGRE(struct Player *player);
void AssignType(struct Player *player);
void ModStr(struct Player *player);
void ModMag(struct Player *player);
void ReverseModStr(struct Player *player);
void ReverseModMag(struct Player *player);
void Attack(struct Player *attacker,struct Player *attacked);
void farAttack(struct Player *attacker, struct Player *attacked);
void magicAttack(struct Player *attacker, struct Player *attacked);
void slotAdj(struct slot ** board, int boardsize);

#endif /* CROSSOPS_H_ */