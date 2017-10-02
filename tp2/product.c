/**
 * Implementation file of product related functions
 * @author Alexandre Lombard
 */

#include "product.h"

#include <stdio.h>

void print_product(Product* product)
{
	printf("[Code: %d, Quantity: %d, Price: %f]", product->code, product->quantity, product->price);
}