/*
 * sp_nim.c
 */
#include <stdio.h>

//A function that helps you determines the computer�s next move
void strategy (int *heaps_array, int N){
	int s_nim_t=0;
	int heaps_array_len = N;
	for (int i=0; i<heaps_array_len; i++){
		s_nim_t^=heaps_array[i];
	}
	if (s_nim_t !=0){
		for (int i=0; i<heaps_array_len; i++){//find a winner heap
			int heap_nim_sum = heaps_array[i]^s_nim_t;
			if(heap_nim_sum<heaps_array[i]){
				int num_removed = heaps_array[i]-heap_nim_sum;
				heaps_array[i]-= num_removed;
				printf("Computer takes %d objects from heap %d.\n",num_removed,i+1);
				break;
			}
		}
	}
	else{
		for (int i=0; i<heaps_array_len; i++){
			if(heaps_array[i]>0){
				heaps_array[i]--;
				printf("Computer takes %d objects from heap %d.\n",1,i+1);
				break;
			}
		}
	}
}

//a function that checks if there's a winner
int check_winner(int *heaps_array, int N){
	int heaps_array_len = N; // sizeof(heaps_array); // /sizeof(int);
	for (int i=0; i<heaps_array_len; i++){
		if (heaps_array[i]!=0)//there are still objects left in some heap
			return 0;// no winner
	}
	return 1;//heaps are empty-there's a winner
}


