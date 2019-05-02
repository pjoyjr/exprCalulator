/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Num_Command.h"

#define NUM_PRIORITY 0

Num_Command::Num_Command(int num)
:value (num)
{
}

Num_Command::~Num_Command()
{
}

int Num_Command::getPriority()
{
	return NUM_PRIORITY;
}

bool Num_Command::execute(Stack<int> & s)
{
	s.push(value);
	return true;
}