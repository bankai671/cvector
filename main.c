#include "vector.h"
#include <stdio.h>

int main() {
	vector_t* int_vec = v(0, 1, 2, 3, 4, 5, 6);
	
	puts("BEFORE PUSH BACK");
	v_print(int_vec);
	
	v_push_back(&int_vec, 777);
	v_push_back(&int_vec, 888);
	v_push_back(&int_vec, 999);
	v_push_back(&int_vec, 101010);
	v_push_back(&int_vec, 111111);
	
	puts("AFTER PUSH BACK");
	v_print(int_vec);
	
	puts("BEFORE POP BACK");
	v_pop_back(&int_vec);
	v_pop_back(&int_vec);
	v_pop_back(&int_vec);
	v_pop_back(&int_vec);
	v_pop_back(&int_vec);

	puts("AFTER POP BACK");
	v_print(int_vec);
	
	int found = v_find(int_vec, 101010);
	
	printf("[v_find (call)] founded %d\n", found);
	
	int found_idx = v_find_index(int_vec, 1231);
	
	printf("[v_find_index (call)] founded %d index\n", found_idx);

	free(int_vec);
	return 0;
}
