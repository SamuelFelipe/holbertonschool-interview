#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_node - insert a new node in a sorted linked lists
 * @head: linked lists head
 * @number: number to add
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
  listint_t *new, *tmp;

  new = malloc(sizeof(listint_t));
  if (!new)
    return (NULL);

  tmp = *head;
  new->n = number;
  if (tmp->n > number)
  {
    new->next = tmp;
    *head = new;
    return (new);
  }
  else
    new->next = NULL;

  while (tmp->next != NULL) {
    if (tmp->next->n > number)
      break;
    tmp = tmp->next;
  }

  new->next = tmp->next;
  tmp->next = new;

  return (new);
}
