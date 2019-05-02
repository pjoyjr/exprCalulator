/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Divide_Command.h"

#define DIVIDE_PRIORITY 2

Divide_Command::Divide_Command(void)
{
}

Divide_Command::~Divide_Command (void)
{
}

int Divide_Command::getPriority()
{
	return DIVIDE_PRIORITY;
}

int Divide_Command::evaluate (int n1, int n2) const
{
	if (n2 == 0)
		throw divided_by_zero("Dividing by Zero");
	return n1 / n2;
}