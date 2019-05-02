/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Add_Command.h"

#define ADD_PRIORITY 1

Add_Command::Add_Command(void)
{
}

Add_Command::~Add_Command(void)
{
}

int Add_Command::getPriority()
{
	return ADD_PRIORITY;
}

int Add_Command::evaluate (int n1, int n2) const
{
	return n1 + n2;
}