#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *array;
    int size;  
    int capacity; 
} List;

void initialize_list(List *list) {
    list->array = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
}

void free_list(List *list) {
    free(list->array);
    list->size = 0;
    list->capacity = 0;
}

void add_element_end(List *list, int element) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = element;
}

void add_element_beginning(List *list, int element) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    }
        for (int i = list->size; i > 0; --i) {
        list->array[i] = list->array[i - 1];
    }
    list->array[0] = element;
    list->size++;
}


void display_list(List *list) {
    printf("Liste: ");
    for (int i = 0; i < list->size; ++i) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

void remove_element_end(List *list) {
    if (list->size > 0) {
        list->size--;
    }
}

void remove_element_beginning(List *list) {
    if (list->size > 0) {
        for (int i = 0; i < list->size - 1; ++i) {
            list->array[i] = list->array[i + 1];

void add_element_end(List *list, int element) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = element;
}
        }
        list->size--;
    }
}

void remove_element_at_position(List *list, int position) {
    if (position >= 0 && position < list->size) {
        for (int i = position; i < list->size - 1; ++i) {
            list->array[i] = list->array[i + 1];
        }
        list->size--;
    }
}


void insert_element_at_position(List *list, int element, int position) {
    if (position >= 0 && position <= list->size) {
        if (list->size >= list->capacity) {
            list->capacity *= 2;
            list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
        }
        for (int i = list->size; i > position; --i) {
            list->array[i] = list->array[i - 1];
        }
        list->array[position] = element;
        list->size++;
    }
}

int is_element_present(List *list, int element) {
    for (int i = 0; i < list->size; ++i) {
        if (list->array[i] == element) {
            return 1;
        }
    }
    return 0;
}

int main() {
    List list;
    initialize_list(&list);

    add_element_end(&list, 5);
    add_element_end(&list, 10);
    add_element_end(&list, 15);

    display_list(&list);

    remove_element_end(&list);
    display_list(&list);

    remove_element_beginning(&list);
    display_list(&list);

    insert_element_at_position(&list, 20, 1);
    display_list(&list);

    printf("Element 10 est %s dans la liste.\n", is_element_present(&list, 10) ? "présent" : "absent");
    printf("Element 25 est %s dans la liste.\n", is_element_present(&list, 25) ? "présent" : "absent");

    free_list(&list); 

    return 0;
}
