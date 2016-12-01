// CS 237, Fall 2016
// Programming assignment 2
#include <iostream>
#include "board.h"
using namespace std;

MineSweeperBoard::MineSweeperBoard(int board_width, int board_height, int mine_count) //TODO
{
	
}

MineSweeperBoard::~MineSweeperBoard() //TODO
{
	delete MineSweeperBoard::MineSweeperBoard;
}

int MineSweeperBoard::get_width() const //TODO
{
	return board_width;
}

int MineSweeperBoard::get_height() const //TODO
{
	return board_height;
}

void MineSweeperBoard::reveal(Position p) //TODO
{

}

bool MineSweeperBoard::flag(Position p) //TODO
{

}

char MineSweeperBoard::appearance(Position p) const
{
	int x = p.x();
	int y = p.y();

	if (flagged[y][x]) {
		return '/';
	}
	else if (revealed[y][x]) {
		if (mined[y][x]) {
			// Boom!
			return '*';
		}
		else {
			// At most 8 adjacent mines, so one digit.
			int adjmines = adjacent_mines(p);
			// Convert a number to a digit character.
			return '0' + adjmines;
		}
	}
	else {
		// Unrevealed, unflagged.
		return '.';
	}
}

void MineSweeperBoard::display(ostream &out) const //TODO
{
	out << endl;
	// print the column numbers
	out << " |";
	for (int x = 0; x < width; x++) {
		out << setw(3) << x;
	}
	out << endl;
	// and a row of dashes
	out << "----+";
	out << setfill('-') << setw(3 * width) << "-" << endl;
	out << setfill(' ');
	for (int y = 0; y < height; y++) {
		// Print the row number
		out << setw(3) << y << " |";

		for (int x = 0; x < width; x++) {
			out << setw(3) << appearance(Position(x, y));
		}
		out << endl;
	}
	out << endl;
}

bool MineSweeperBoard::won() const
{
	// Check every square.  If we see a square that is mined but
	// not flagged, or unmined but not revealed, return false
	// immediately.  If we get to the end, every square is correct,
	// so the user won and we return true.
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (mined[y][x] && !flagged[y][x]) {
				return false;
			}
			else if (!mined[y][x] && !revealed[y][x]) {
				return false;
			}
		}
	}
	return true;
}

bool MineSweeperBoard::lost() const //TODO
{

}

void MineSweeperBoard::give_up()
{
	cout << "You Lose";
	system("pause");
	EXIT_SUCCESS;
}

PositionList MineSweeperBoard::adjacent(Position p) const
{
	PositionList result;

	// Loop over the 3x3 block centered around p.
	for (int adj_y = p.y() - 1; adj_y <= p.y() + 1; adj_y++) {
		for (int adj_x = p.x() - 1; adj_x <= p.x() + 1; adj_x++) {
			// Make a position out of the new coordinates.
			Position adj(adj_x, adj_y);
			// Skip out-of-bounds squares
			if (!adj.in_bounds(width, height))
				continue;
			// Also skip the center.
			if (adj.x() == p.x() && adj.y() == p.y())
				continue;

			// If we get here, it's really adjacent, so add it to the list.
			result.push_front(adj);
		}
	}
	return result;
}

int MineSweeperBoard::adjacent_mines(Position p) const
{
	PositionList neighbors = adjacent(p);

	// Loop over the neighbors.
	int adjacent_count = 0;
	for (int i = 0; i < neighbors.size(); i++) {
		Position adj = neighbors.get(i);
		// If it's mined, increase the count.
		if (mined[adj.y()][adj.x()])
			adjacent_count++;
	}
	return adjacent_count;
}

int MineSweeperBoard::adjacent_flags(Position p) const //TODO
{

}
