// CS 237, Fall 2016
// Programming assignment 2
#include <cstdlib>
#include "positionlist.h"
using namespace std;

// Default constructor: Initialize an empty list
PositionList::PositionList()
{
	first = nullptr;
}

// Initialize a node with no next node and the given position.
Node::Node(Position p)
: next(NULL), pos(p)
{}


// Initialize a copy of a list using the copy_nodes helper function.
PositionList::PositionList(const PositionList &original)
{
	first = copy_nodes(original.first);
}

PositionList::~PositionList() //TODO
{

}

PositionList &PositionList::operator=(const PositionList &other)
{
	if (this == &other)
		return *this;

	free_nodes(first);
	first = copy_nodes(other.first);
}

bool PositionList::empty() const //TODO done I think
{
	if (first == nullptr)
		return true;
}

int PositionList::size() const
{
	int i = 0;
	for (Node *curr = first; curr != NULL; curr = curr->next) {
		i++;
	}
	return i;
}

Position PositionList::get(int index) const //TODO
{

}

void PositionList::push_front(Position pos) //TODO
{

}

void PositionList::pop_front() //TODO
{
	
}

Node PositionList::*copy_nodes(const Node *in) //TODO
{

}
