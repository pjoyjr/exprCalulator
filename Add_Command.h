/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
 
#ifndef ADD_COMMAND_H
#define ADD_COMMAND_H

#include "Binary_Op_Command.h"

class Add_Command : public Binary_Op_Command
{
public:
	Add_Command(void);
	~Add_Command(void);
	int getPriority();
	int evaluate(int n1, int n2) const;
};



#endif