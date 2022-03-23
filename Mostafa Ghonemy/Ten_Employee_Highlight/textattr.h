#include <stdlib.h>
#include <windows.h>

/** @brief changes the textattr
 *
 * @param i is the no. of the mode required
 * 
 * @return void
 *
 */

void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}