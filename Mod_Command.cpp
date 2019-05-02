/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Mod_Command.h"

#define MOD_PRIORITY 2

Mod_Command::Mod_Command(void)
{
}

Mod_Command::~Mod_Command(void)
{
}

int Mod_Command::getPriority()
{
	return MOD_PRIORITY;
}

int Mod_Command::evaluate(int n1, int n2) const
{
	if (n2 == 0)
		throw divided_by_zero("Mod cannot divide by Zero!");
	return n1 % n2;
}