#ifndef _PRODUCT_LIST_H_
#define _PRODUCT_LIST_H_

/**
 * Product list definition and related functions
 * @author Alexandre Lombard
 */

#include "product.h"

#define TRUE 1
#define FALSE 0
typedef int BOOL;

/**
 * List node element
 */
/* TODO Define the type 'Element' which represents a node of the list */

/**
 * List of product
 */
/* TODO Define the type 'ProductList' which represents a list of products */

/**
 * Tests if a list is empty
 * @param l the list to test
 * @return <code>true</code> if the list is empty, <code>false</code> otherwise
 */
BOOL is_empty(ProductList l);

/**
 * Gets the head of the list
 * @param l the list
 * @return a pointer to the head of the list or <code>NULL</code> if the list is empty
 */
Element* head(ProductList l);

/**
 * Gets the tail of the list
 * @param l the list
 * @return a pointer to the tail of the list or <code>NULL</code> if the list is empty
 */
Element* tail(ProductList l);

/**
 * Inserts the given product at the head of the list
 * @param l the list
 * @param p the product to insert
 * @return the modified product list
 */
ProductList insert_head(ProductList l, Product p);

/**
 * Inserts the given product at the tail of the list
 * @param l the list
 * @param p the product to insert
 * @return the modified product list
 */
ProductList insert_tail(ProductList l, Product p);

/**
 * Returns the number of elements of the given list
 * @param l the list
 * @return the size of the list
 */
int size(ProductList l);

/**
 * Displays all the elements of the list on the standard output
 * @param l the product list
 */
void print_list(ProductList l);

/**
 * Gets the element at the given position in the list
 * @param l the product list
 * @param position the position of the element to get, or <code>NULL</code> if the position is not valid (negative or greater or equal to the size)
 */
Element* get_at(ProductList l, int position);

/**
 * Inserts the given element at the given position in the list. If position is negative it is equivalent to insert_head,
 * if it is greater than or equal to the size it is equivalent to insert_tail.
 * @param l the product list
 * @param p the product to insert
 * @param position the position
 * @return the modified list
 */
ProductList insert_at(ProductList l, Product p, int position);

/**
 * Compacts a list, i.e. creates a new list without duplicate products (according to the code). 
 * When 'compacting' duplicate products, the new quantity is the sum of the quantity of the products, the price is the
 * weighted mean of the price according to the quantity.
 * @param l the product list
 * @return the compacted list
 */
ProductList compact(ProductList l);

/**
 * Sorts the given list by increasing codes.
 * @param l the product list
 * @return the sorted list
 */
ProductList sort(ProductList l);

#endif