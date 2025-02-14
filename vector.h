#include <stdlib.h>
#include <stdarg.h>

#define v(...) v_create((int[]){__VA_ARGS__}, sizeof((int[]){__VA_ARGS__}) / sizeof(int))

typedef struct {
	int capacity;
	int size;
	int data[];
} vector_t;

vector_t* v_create(int* values, int count);
void v_push_back(vector_t** self, int item);
void v_print(vector_t* self);
int v_pop_back(vector_t** self);
int v_find(vector_t* self, int value);
int v_find_index(vector_t* self, int value);
