/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifndef NUM_COMMAND_H
#define NUM_COMMAND_H

#include "Expr_Command.h"
#include "Stack.h"

class Num_Command : public Expr_Command
{
public:
	Num_Command (int num);
	~Num_Command ();
	int getPriority();
	bool execute(Stack<int> & s);
private:
	int value;
};

#endif