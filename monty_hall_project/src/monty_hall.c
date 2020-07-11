/*
 * monty_hall.c
 *
 *  Created on: Jun 30, 2020
 *      Author: Kasagumo
 */
#include <stdio.h>
//#include <stdlib.h>
#define NUM_OF_DOORS 3

enum door_tag {
	GOAT,
	PRIZE
};
typedef enum door_tag door_t;

void print_prize(door_t * pointer_to_door) {
	switch (*pointer_to_door)
	{
	case GOAT:
		printf("You get a goat!");
		break;
	case PRIZE:
		printf("You get a prize!");
		break;
	default:
		printf("Invalid prize");
		// This doesn't quite work since value outside of array may be mistaken for GOAT/PRIZE
	}
}

int generate_doors(door_t* first_door) {
	int x = 0; // returns 0 if doors are not yet prepared
	for (int i = 0; i < NUM_OF_DOORS; i++)
	{
		first_door[i] = GOAT;
	}
	int r = random() % NUM_OF_DOORS;
	first_door[r] = PRIZE;
	x = 1; // returns 1 if doors are successfully prepared
	return x;
}

int main(int argc, char *argv[]) {
	printf("This is a simulation of the Monty Hall problem.\n");
	door_t * set_of_doors;
	int x = generate_doors(set_of_doors);
	int chosen_door;
	printf("Choose a door. 1, 2, or 3?\n");
	scanf("%d",&chosen_door);
	printf("Chosen door is: %d\n", chosen_door);
	print_prize(&set_of_doors[chosen_door-1]);

	return 0;
}

