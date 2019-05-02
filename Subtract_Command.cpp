/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Subtract_Command.h"

#define SUBTRACT_PRIORITY 1

Subtract_Command::Subtract_Command(void)
{
}

Subtract_Command::~Subtract_Command(void)
{
}

int Subtract_Command::getPriority()
{
	return SUBTRACT_PRIORITY;
}

int Subtract_Command::evaluate(int n1, int n2) const
{
	return n1 - n2;
}