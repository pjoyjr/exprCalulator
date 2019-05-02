/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Multiply_Command.h"

#define MULTIPLY_PRIORITY 2

Multiply_Command::Multiply_Command(void)
{
}

Multiply_Command::~Multiply_Command(void)
{
}

int Multiply_Command::getPriority()
{
	return MULTIPLY_PRIORITY;
}

int Multiply_Command::evaluate(int n1, int n2) const
{
	return n1 * n2;
}