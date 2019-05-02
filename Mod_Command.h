/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifndef MOD_COMMAND_H
#define MOD_COMMAND_H

#include "Binary_Op_Command.h"

class Mod_Command : public Binary_Op_Command
{
public:
	class divided_by_zero : public std::logic_error
	{
	public:
		explicit divided_by_zero(const std::string & arg)
		:std::logic_error (arg)
		{
		}
	};

	Mod_Command(void);
	~Mod_Command(void);
	int getPriority();
	int evaluate(int n1, int n2) const;
};

#endif