/*
 * monty_hall.c
 *
 *  Created on: Jun 30, 2020
 *      Author: Kasagumo
 */
#include <stdio.h>
//#include <stdlib.h>

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

door_t* generate_doors(door_t* first_door) {
	door_t set_of_doors[3] = {GOAT, GOAT, GOAT};
		int r = random() % 3;
		set_of_doors[r] = PRIZE;

}

int main(int argc, char *argv[]) {
	printf("This is a simulation of the Monty Hall problem.\n");

	int chosen_door;
	printf("Choose a door. 1, 2, or 3?\n");
	scanf("%d",&chosen_door);
	printf("Chosen door is: %d\n", chosen_door);
	print_prize(&set_of_doors[chosen_door-1]);


	return 0;
}

