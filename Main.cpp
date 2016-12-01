// CS 237, Fall 2016
// Programming assignment 2
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "board.h"
using namespace std;

int bomb_count, board_width, board_height, pos_x, pos_y, RFG;

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	// TODO: Ask for the board size (between 5 and 20 in each direction) DONE
	while (board_width <! 5 && board_width >! 20 && board_height <! 5 && board_height >! 20)
	{
		cout << "Enter the boards height between 5 and 20: ";
		cin >> board_height;
		cout << "Enter the boards width between 5 and 20: ";
		cin >> board_width;
	}
	// and the number of mines. DONE
	while (bomb_count > (board_height * board_width))
	{
		cout << "Enter the number of mines (Anynumber less than the size of the board): ";
		cin >> bomb_count;
	}
	

	// Create a board of that size. DONE
	// TODO: change these numbers. DONE
	MineSweeperBoard board(board_width, board_height, bomb_count);

	while (!board.lost() && !board.won())
	{
		board.display(cout);
		// TODO: Ask the user to [R]eveal, [F]lag, or [G]ive up. DONE
		cout << "Enter [R]eveal, [F]lag, or [G]ive up: ";
		cin >> RFG;

		// The first two commands also require a Position, so
		// you may need to ask for x and y coordinates as well. DONE
		if (RFG == 'r' || RFG == 'f' || RFG == 'R' || RFG == 'F')
		{
			cout << "Enter x and y coordinates for the positon you want: ";
			cin >> pos_x, pos_y;
		}
		

		// TODO: Then perform that command by calling the appropriate
		// method.

		if (RFG == 'r' || RFG == 'R')
		{
			board.reveal(Position(pos_x,pos_y));
		}
		if (RFG == 'f' || RFG == 'F')
		{
			board.flag(Position(pos_x, pos_y));
		}
		if (RFG == 'g' || RFG == 'G')
		{
			board.give_up();
		}

	}

	// TODO: Tell the user whether they won or lost.
	if (board.won() == true)
	{
		cout << "You Won";
	}
	if (board.lost() == true)
	{
		cout << "You Lost";
	}
	// TODO: Compute and display how much time the game took.

	system("pause");
	return 0;
}
