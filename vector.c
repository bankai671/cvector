#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

vector_t* v_create(int* values, int count) {
	vector_t* vec = (vector_t*)malloc(sizeof(vector_t) + sizeof(int) * count * 2);
	
	if (vec == NULL) {
		fprintf(stderr, "[v_create] memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	vec->capacity = count * 2;
	vec->size = count;

	for (int i = 0; i < count; ++i) {
		vec->data[i] = values[i];
	}

	printf("[v_create] vector size = %d\n", vec->size);
	printf("[v_create] vector capacity = %d\n", vec->capacity);

	return vec;
}

void v_push_back(vector_t** self, int item) {
	if ((*self)->size == (*self)->capacity) {
		(*self)->capacity *= 2;
		*self = (vector_t*)realloc(*self, sizeof(vector_t) + sizeof(int) * (*self)->capacity);
		if (*self == NULL) {
			fprintf(stderr, "[v_push_back] memory allocation failed!\n");
            exit(EXIT_FAILURE);
		}
	}

	(*self)->data[(*self)->size++] = item;
}

void v_print(vector_t* self) {
	if (self->size == 0) {
		puts("[v_print] vector is empty\n");
	}

	for (int i = 0; i < self->size; ++i) {
		printf("[v_print] vector[%d]: %d \n", i, self->data[i]);
	}
}

int v_pop_back(vector_t** self) {
	if ((*self)->size == 0) {
		fprintf(stderr, "[v_pop_back] pop_back failed, nothing to pop!\n");
        exit(EXIT_FAILURE);
	}

	int last_value = (*self)->data[(*self)->size - 1];
	(*self)->size--;
	
	printf("[v_pop_back] vector[%d]: %d deleted\n", (*self)->size+1, last_value);

	return last_value;
}

int v_find(vector_t* self, int value) {
	if (self->size == 0) {
		puts("[v_find] vector is empty");
	}

	for (int i = 0; i < self->size; ++i) {
		if (self->data[i] == value) {
			return value;
		}
	}

	printf("[v_find] vector has no %d element", value);
	return -1;
}

int v_find_index(vector_t* self, int value) {
	if (self->size == 0) {
		puts("[v_find] vector is empty");
	}

	for (int i = 0; i < self->size; ++i) {
		if (self->data[i] == value) {
			return i;
		}
	}

	printf("[v_find] vector has no %d element", value);
	return -1;
}
