/*
 * main_aux.h
 */

#ifndef MAIN_AUX_H_
#define MAIN_AUX_H_

void print_heaps_status(int *heaps, int turn, int N);
void print_game_board(int *heaps_array, int N);
int check_valid_turn_input(int *heaps, int heap_index, int num_removed, int N);

#endif /* MAIN_AUX_H_ */
