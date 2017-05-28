/*
 * main_aux.c
 */

#include <stdio.h>

//A function that prints the heaps' status
void print_heaps_status(int *heaps, int turn, int N){
	printf("In turn %d heap sizes are:",turn);
	for (int i = 0; i < N; i++) {
		printf(" h%d=%d",i+1,heaps[i]);
	}
	printf(".\n");
}

//A function that prints the game board
void print_game_board(int *heaps_array, int N){
	int max = 0;
	//first find the size of the largest heap
	for (int i = 0; i<N;i++){
		if (heaps_array[i] > max) {
			max = heaps_array[i];
		}
	}
	//now print the heaps
	for (int i=0; i<max; i++){
			for (int j=0; j<N-1; j++){
				if (i>=max-heaps_array[j])
					printf("*\t");
				else
					printf(" \t");
			}
			//the last object in line doesn't need space after
			if(i>=max-heaps_array[N-1])
				printf("*");
			else
				printf(" ");
			printf("\n");
		}
}

//A function that checks the validity of input during the user's turn
int check_valid_turn_input(int *heaps, int heap_index, int num_removed, int N){
	int isValid = 1;
	if(heap_index<0 || heap_index>N){
		isValid=0;
	}
	if(num_removed>heaps[heap_index] || num_removed<1){
		isValid=0;
	}
	return isValid;
}
