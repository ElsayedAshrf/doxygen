#include <stdlib.h>
#include <windows.h>


/** @brief move the cursor to specific position
 *
 * @param column is column position
 * @param line is the line number
 * @return void
 *
 */

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}