# ifndef MAIN_H
# define MAIN_H

/**
 * Handles the interrupt for the button.
 */
void buttonISR();

/**
 * Returns the amount of characters in a given int.
 *
 * @param i The int to return the length for.
 * @return The length of the int.
 */
int intLength(int i);

/**
 * Print the counter..
 */
void printCounter();

#endif
