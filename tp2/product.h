#ifndef _PRODUCT_H_
#define _PRODUCT_H_

/**
 * Product definition and related functions
 * @author Alexandre Lombard
 */

/**
 * Product definition
 */
typedef struct {
	/** The code of the product */
	int code;
	/** The quantity of the product */
	int quantity;
	/** The price of the product */
	float price;
} Product;

/**
 * Prints the details of the given product on the standard output
 * @param product a pointer to the product to display, must no be <code>null</code>
 */
void print_product(Product* product);

#endif