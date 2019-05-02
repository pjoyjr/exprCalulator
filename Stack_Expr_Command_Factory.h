/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifndef STACK_EXPR_COMMAND_FACTORY_H
#define STACK_EXPR_COMMAND_FACTORY_H

#include "Expr_Command_Factory.h"

class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
	public:
		//constructor
		Stack_Expr_Command_Factory();

		//virtual destructor
		virtual ~Stack_Expr_Command_Factory (void);

		//create methods
		virtual Add_Command * create_add_command (void);
		virtual Divide_Command * create_divide_command (void);
		virtual Mod_Command * create_mod_command (void);
		virtual Multiply_Command * create_multiply_command (void);
		virtual Num_Command * create_num_command (int num);
		virtual Subtract_Command * create_subtract_command (void);
};

#endif