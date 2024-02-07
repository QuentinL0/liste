#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

// Structure de la liste
typedef struct {
    int *array; // Tableau dynamique pour stocker les éléments de la liste
    int size;   // Taille actuelle de la liste
    int capacity; // Capacité maximale du tableau
} List;

// Initialise une nouvelle liste
void initialize_list(List *list) {
    list->array = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
}

// Libère la mémoire utilisée par la liste
void free_list(List *list) {
    free(list->array);
    list->size = 0;
    list->capacity = 0;
}

// Ajoute un élément à la fin de la liste
void add_element_end(List *list, int element) {
    if (list->size >= list->capacity) {
        // Si la capacité maximale est atteinte, augmentez la capacité du tableau
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = element;
}

// Affiche la liste
void display_list(List *list) {
    printf("Liste: ");
    for (int i = 0; i < list->size; ++i) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

// Supprime un élément à la fin de la liste
void remove_element_end(List *list) {
    if (list->size > 0) {
        list->size--;
    }
}

// Supprime un élément au début de la liste
void remove_element_beginning(List *list) {
    if (list->size > 0) {
        for (int i = 0; i < list->size - 1; ++i) {
            list->array[i] = list->array[i + 1];
        }
        list->size--;
    }
}

// Insère un élément dans la liste à une position saisie
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

// Recherche si un élément est présent dans la liste
int is_element_present(List *list, int element) {
    for (int i = 0; i < list->size; ++i) {
        if (list->array[i] == element) {
            return 1; // Retourne 1 si l'élément est présent
        }
    }
    return 0; // Retourne 0 si l'élément n'est pas présent
}

// Programme principal
int main() {
    List list;
    initialize_list(&list);

    // Utilisation des fonctionnalités
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

    free_list(&list); // Libération de la mémoire allouée

    return 0;
}
