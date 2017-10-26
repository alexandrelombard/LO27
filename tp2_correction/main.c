#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <product_list.h>

#define N 5

int main(int argc, char* argv[])
{
	ProductList l = NULL;	/* Don't forget to initialize at NULL */
	Product products[N];
	int idx = 0;

	srand(time(NULL));

	for(idx = 0; idx < N; idx++) {
		products[idx].code = rand()%10;
		products[idx].quantity = rand()%100;
		products[idx].price = rand()%100;

		l = insert_head(l, products[idx]);
	}

	printf("Print list: \n");
	print_list(l);

	printf("\n\nRemove head: \n");
	l = remove_head(l);
	print_list(l);

	printf("\n\nRemove tail: \n");
	l = remove_tail(l);
	print_list(l);

	printf("\n\nInsert tail: \n");
	l = insert_tail(l, products[0]);
	print_list(l);

	printf("\n\nInsert at: \n");
	l = insert_at(l, products[0], 1);
	print_list(l);

	printf("\n\nSize: %d\n", size(l));

	printf("\n\nRemove at (%d): \n", size(l));
	l = remove_at(l, 1);
	print_list(l);

	printf("\n\nPopulate (%d): \n", size(l));
	for(idx = 0; idx < N; idx++) {
		products[idx].code = rand()%10;
		products[idx].quantity = rand()%100;
		products[idx].price = rand()%100;

		l = insert_head(l, products[idx]);
	}
	print_list(l);

	printf("\n\nCompact: \n");
	l = compact(l);
	print_list(l);

	printf("\n\nSorted list: \n");
	l = sort(l);
	print_list(l);

	return EXIT_SUCCESS;
}