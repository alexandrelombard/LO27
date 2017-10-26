/**
 * Implementation file of product list related functions
 * @author Alexandre Lombard
 */

#include <product_list.h>

#include <stdlib.h>
#include <stdio.h>

#ifndef NULL
#define NULL 0
#endif

BOOL is_empty(ProductList l)
{
	if(l == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

Element* head(ProductList l)
{
	Element* head = l;
	return head;
}

Element* tail(ProductList l)
{
	Element* tmp = l;

	if(tmp == NULL) {
		return NULL;
	} else {
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}

		return tmp;
	}
}

ProductList insert_head(ProductList l, Product p)
{
	Element* newElement = (Element*) malloc(sizeof(Element));

	newElement->value = p;
	newElement->next = l;

	return newElement;
}

ProductList insert_tail(ProductList l, Product p)
{
	Element* newElement = (Element*) malloc(sizeof(Element));
	Element* tmp = l;

	newElement->value = p;
	newElement->next = NULL;

	if(is_empty(l)) {
		/* In this case, it is equivalent to insert_head because the list is empty */
		return newElement;
	} else {
		/* In this case, we iterate over the list to connect the last element to the new one */
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}

		tmp->next = newElement;
	}

	return l;
}

ProductList remove_head(ProductList l)
{
	Element* tmp;

	if(!is_empty(l))
	{
		tmp = l->next;

		free(l);

		return tmp;
	} else {
		return l;
	}
}

ProductList remove_tail(ProductList l)
{
	Element* tmp = l;

	if(!is_empty(l)) {
		if(tmp->next == NULL) {
			return remove_head(l);
		} else {
			while(tmp->next->next != NULL) {
				tmp = tmp->next;
			}

			free(tmp->next);
			tmp->next = NULL;

			return l;
		}
	} else {
		return l;
	}
}

ProductList remove_at(ProductList l, int position)
{
	int index;
	Element* tmp;
	Element* elementToFree;

	if(position < 0 || is_empty(l)) {
		/* In this case it is equivalent to remove head */
		return remove_head(l);
	} else {
		index = 0;
		tmp = l;

		while(index < position - 1) {
			index++;
			tmp = tmp->next;
		}

		elementToFree = tmp->next;
		tmp->next = tmp->next->next;

		free(elementToFree);
	}

	return l;
}

int size(ProductList l)
{
	int size = 0;

	Element* tmp = l;

	while(tmp != NULL) {
		size++;
		tmp = tmp->next;
	}

	return size;
}

void print_list(ProductList l)
{
	Element* tmp = l;

	while(tmp != NULL) {
		print_product(&(tmp->value));
		printf("\n");
		tmp = tmp->next;
	}
}

Element* get_at(ProductList l, int position)
{
	int index = 0;
	Element* tmp = l;

	if(position < 0) {
		return NULL;
	}

	while(index < position && tmp != NULL) {
		index++;
		tmp = tmp->next;
	}

	return tmp;
}

ProductList insert_at(ProductList l, Product p, int position)
{
	int index = 0;
	Element* newElement;
	Element* tmp = l;

	if(position <= 0 || is_empty(l)) {
		/* In both of these cases, it is equivalent to insert_head */
		return insert_head(l, p);
	} else {
		 newElement = (Element*) malloc(sizeof(Element));
		 newElement->value = p;

		while(index < position - 1) {
			index++;
			tmp = tmp->next;
		}

		newElement->next = tmp->next;
		tmp->next = newElement;
	}

	return l;
}

ProductList compact(ProductList l)
{
	/* Several strategies are available, the proposed one is just a suggestion and it's not the most efficient one.
	   Indeed, there are a lot of loops. However, it is easy to understand and to implement. */

	int s = size(l);
	int i;
	int j;

	ProductList compacted_list = l;

	for(i = 0; i < s; i++) {
		Element* element_at_i = get_at(compacted_list, i);
		for(j = i + 1; j < s; j++) {
			Element* element_at_j = get_at(compacted_list, j);

			if(element_at_i->value.code == element_at_j->value.code) {
				/* Computes the total quantity and the total price */
				int total_quantity = element_at_i->value.quantity + element_at_j->value.quantity;
				float average_price = (element_at_i->value.quantity * element_at_i->value.price + element_at_j->value.quantity * element_at_j->value.price)
										/ total_quantity;

				/* Sets the new value for the element at position i */
				element_at_i->value.quantity = total_quantity;
				element_at_i->value.price = average_price;

				/* Removes the element at position j */
				compacted_list = remove_at(compacted_list, j);
				s = s - 1;	/* An element is removed, we reduce the size */
				j = j - 1;	/* The indices of the next elements are moved, we don't want to increase j */
			}
		}
	}

	return l;
}

ProductList sort(ProductList l)
{
	/* Like the previous function, there are a lot of possibilties. A heap sort for instance could be interresting but it would require
	   us to define a binary tree structure. For the sake of simplicity, here, we just use a simple bubble sort */

	Element* tmp = l;
	Element* last = NULL;

	int change;

	if(!is_empty(tmp) && !is_empty(tmp->next)) {
		do {
			change = 0;

			while(tmp->next != last) {
				if(tmp->value.code > tmp->next->value.code) {
					/* Here we swap the elements */
					Product tmpProduct = tmp->next->value;
					tmp->next->value = tmp->value;
					tmp->value = tmpProduct;

					change = 1;
				}

				tmp = tmp->next;
			}

			last = tmp;
			tmp = l;

		} while(change == 1);
	}

	return l;
}