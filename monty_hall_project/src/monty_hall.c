/*
 * monty_hall.c
 *
 *  Created on: Jun 30, 2020
 *      Author: Kasagumo
 */
#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_DOORS 3

enum door_tag
{
	GOAT, PRIZE
};
typedef enum door_tag door_t;

int num2ind(int door_number)
{
	return door_number - 1;
}

int ind2num(int door_index)
{
	return door_index + 1;
}

void print_prize(door_t *pointer_to_door)
{
	switch (*pointer_to_door)
	{
	case GOAT:
		printf("a goat!\n");
		break;
	case PRIZE:
		printf("a prize!\n");
		break;
	default:
		printf("Invalid prize\n");
		// This doesn't quite work since value outside of array may be mistaken for GOAT/PRIZE
	}
}

int generate_doors(door_t *first_door)
{
	int x = 0; // returns 0 if doors are not yet prepared
	int r = rand() % NUM_OF_DOORS;
	for (int i = 0; i < NUM_OF_DOORS; i++)
	{
		if (i == r)
		{
			first_door[i] = PRIZE;
		}
		else
		{
			first_door[i] = GOAT;
		}
	}
	x = 1; // returns 1 if doors are successfully prepared
	return x;
}

int show_a_door(door_t *first_door, int chosen_door_number)
{
	int chosen_door_index = num2ind(chosen_door_number);
	int shown_door_number;
	int possible_to_show[NUM_OF_DOORS] =
	{ 0 }; // fill with the number labels of showable doors.
	int number_of_showable_doors = 0;
	for (int i = 0; i < NUM_OF_DOORS; i++)
	{
		if ((i != chosen_door_index) && (first_door[i]==0))
		{
			possible_to_show[number_of_showable_doors] = ind2num(i);
			number_of_showable_doors++;
		}
	}
	if ((number_of_showable_doors < 1)
			|| (number_of_showable_doors > NUM_OF_DOORS))
	{
		exit(EXIT_FAILURE);
	}
	else if (number_of_showable_doors==1)
	{
		shown_door_number = possible_to_show[0];
	}
	else
	{
		shown_door_number = possible_to_show[rand() % number_of_showable_doors];
	}
	printf("Monty shows you door %d. Behind it is: ", shown_door_number);
	print_prize(&first_door[num2ind(shown_door_number)]);
	return shown_door_number;
}

int switch_doors(int initial_door, int shown_door) {
	// written only for the case of NUM_OF_DOORS = 3, numbered 1,2,3.
	int sum_of_door_nums = initial_door + shown_door;
	int final_door;
	switch (sum_of_door_nums)
	{
	case 3:
		final_door = 3;
		break;
	case 4:
		final_door = 2;
		break;
	case 5:
		final_door = 1;
		break;
	default: exit(EXIT_FAILURE);
	}
return final_door;
}

int process_switch(door_t * first_door, int initial_door, int shown_door) {
	int final_door;
	char answer_to_switch;
	puts("Would you like to switch? (y for yes, n for no)");
	scanf("%c", &answer_to_switch);
	switch (answer_to_switch)
	{
	case 'y':
		final_door = switch_doors(initial_door, shown_door);
		printf("Your choice has switched to door %d", final_door);
		break;
	case 'n':
		final_door = initial_door;
		printf("Your choice remains door %d", final_door);
		break;
	default:
		puts("Not an eligible choice. Type y or n."); exit(EXIT_FAILURE);
	}
	return final_door;
}

int main(int argc, char *argv[])
{
	printf("This is a simulation of the Monty Hall problem.\n");
	door_t set_of_doors[NUM_OF_DOORS] = { 0 };

	int x = generate_doors(set_of_doors);
	if (x != 1)
	{
		exit(EXIT_FAILURE);
	}
	int initial_choice;
	printf("Choose a door. 1, 2, or 3?\n");
	scanf("%d", &initial_choice);
	printf("You have chosen door %d\n", initial_choice);

	int door_to_show = show_a_door(set_of_doors, initial_choice);
	int final_choice = process_switch(set_of_doors, initial_choice, door_to_show);
	puts("Behind this door is: ");
	print_prize(&set_of_doors[num2ind(final_choice)]);
	return 0;
}

