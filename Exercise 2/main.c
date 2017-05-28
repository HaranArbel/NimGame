#include "SPBufferset.h"
#include "main_aux.h"
#include "sp_nim.h"
#include <stdio.h>

int main() {
	int N, heaps[N], turn=0;
	SP_BUFF_SET();
	printf("Enter the number of heaps:\n");
	scanf("%d",&N);
	if (N < 1 || N > 32){
		printf("Error: the number of heaps must be between 1 and 32.\n");
		return 0;}
	int cnt=1, c, num_digit=0, heap_size, digit;
	printf("Enter the heap sizes:\n");
		c=getchar();
		while ((c=getchar())!=EOF && c!='\n') {
			if (c!=' ') {
				if ((num_digit==0 && c>'0' && c<='9') || (num_digit>0 && c>='0' && c<='9')) {
					digit = c-'0';
					heap_size = num_digit*10+digit;
				} else { //input is not valid
					printf("Error: the size of heap %d should be positive.\n", cnt);
					return 0;}
			} else { // finished reading size of current heap
				heaps[cnt - 1] = heap_size;
				cnt++;
				num_digit = 0;}}
		heaps[cnt - 1] = heap_size; //last size

	while (!check_winner(heaps, N)){//while there is no winner
		turn++;
		print_heaps_status(heaps,turn, N);
		if (turn%2 == 1){//if it's the computer's turn
			strategy(heaps, N);
		}
		else{//if it's the users turn
			print_game_board(heaps, N);
			int heap_index, num_removed;
			printf("Your turn: please enter the heap index and the number of removed objects.\n");
			scanf("%d",&heap_index); scanf("%d",&num_removed);
			int isValid = check_valid_turn_input(heaps, heap_index-1, num_removed, N);
			while(isValid==0){
				printf("Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
				scanf("%d",&heap_index);
				scanf("%d",&num_removed);
				isValid = check_valid_turn_input(heaps, heap_index-1, num_removed, N);}
			printf("You take %d objects from heap %d.\n",num_removed,heap_index);
			heaps[heap_index-1] -= num_removed;}//already checked if valid
	}	//announce the winner winner:
	if (turn%2==1) printf("Computer wins!\n");
	else printf("You win!\n");}

