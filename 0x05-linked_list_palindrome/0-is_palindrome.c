#include "lists.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: list head
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head) {
	int *values_array, length = 0, length_aux = 0, i;
	listint_t *aux;
	
	aux = *head;
	while (aux) {
		aux = aux->next;
		length++;
	}
	if (!length)
		return (1);
	length_aux = length;
	values_array = malloc(length * sizeof(int));
	if (!values_array)
		return (0);
	aux = *head;
	while (aux) {
		values_array[length - 1] = aux->n;
		length--;
		aux = aux->next;
	}
	if (length_aux % 2)
		length_aux -= 1;
	for (i = 0; i < length_aux / 2; i++)
		if (values_array[i] != values_array[length_aux - (i + 1)])
			return (0);
	free(values_array);
	return (1);
}
