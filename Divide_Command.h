/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifndef DIVIDE_COMMAND_H
#define DIVIDE_COMMAND_H

#include "Binary_Op_Command.h"
#include <stdexcept>

class Divide_Command : public Binary_Op_Command
{
public:
	class divided_by_zero : public std::logic_error
	{
	public:
		explicit divided_by_zero (const std::string & arg)
		:std::logic_error (arg)
		{
		}
	};

	Divide_Command(void);
	~Divide_Command(void);
	int getPriority();
	int evaluate(int n1, int n2) const;
};

#endif