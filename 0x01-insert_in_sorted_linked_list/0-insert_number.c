#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - insert a new node in a sorted linked lists
 * @head - linked lists head
 * @number - number to add
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number) {

    listint_t *new, *next;

    next = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
      // failed to alocate needed memory
      return NULL;

    new->n = number;
    new->next = NULL;

    if (next == NULL)
      *head = new;

    while (next->next->n < number)
      next = next->next;

    new->next = next->next;
    next->next = new;

    return new;
}
