#include "deck.h"
int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - compares two strings.
 * @s1: string one to be compared.
 * @s2: string two to be compared.
 * Return: positive if s1 > s2, 0 if equal, negative if s1 < s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - get numerical value of a card.
 * @card: pointer to a deck_node_t card.
 * Return: numerical value of the card.
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - sorts a deck of cards.
 * @deck: pointer to the head of a deck_node_t doubly linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *len, *current, *temp;

	for (len = (*deck)->next; len != NULL; len = temp)
	{
		temp = len->next;
		current = len->prev;
		while (current != NULL && current->card->kind > len->card->kind)
		{
			current->next = len->next;
			if (len->next != NULL)
				len->next->prev = current;
			len->prev = current->prev;
			len->next = current;
			if (current->prev != NULL)
				current->prev->next = len;
			else
				*deck = len;
			current->prev = len;
			current = len->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - sorts a deck of cards.
 * @deck: pointer to the head of a deck_node_t doubly linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *len, *current, *temp;

	for (len = (*deck)->next; len != NULL; len = temp)
	{
		temp = len->next;
		current = len->prev;
		while (current != NULL &&
			current->card->kind == len->card->kind &&
			get_value(current) > get_value(len))
		{
			current->next = len->next;
			if (len->next != NULL)
				len->next->prev = current;
			len->prev = current->prev;
			len->next = current;
			if (current->prev != NULL)
				current->prev->next = len;
			else
				*deck = len;
			current->prev = len;
			current = len->prev;
		}
	}
}

/**
 * sort_deck - sorts a deck of cards.
 * @deck: pointer to the head of a deck_node_t doubly linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
