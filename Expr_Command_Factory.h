/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifndef EXPR_COMMAND_FACTORY_H
#define EXPR_COMMAND_FACTORY_H

#include "Add_Command.h"
#include "Divide_Command.h"
#include "Mod_Command.h"
#include "Multiply_Command.h"
#include "Num_Command.h"
#include "Subtract_Command.h"

class Expr_Command_Factory
{
	public:
		//constructor
		Expr_Command_Factory(){};

		//virtual destructor
		virtual ~Expr_Command_Factory() {};
		
		//pure virtual methods
		virtual Add_Command * create_add_command (void) = 0;
		virtual Divide_Command * create_divide_command (void) = 0;
		virtual Mod_Command * create_mod_command (void) = 0;
		virtual Multiply_Command * create_multiply_command (void) = 0;
		virtual Num_Command * create_num_command (int num) = 0;
		virtual Subtract_Command * create_subtract_command (void) = 0;

	private:// prevent the following operations
		Expr_Command_Factory (const Expr_Command_Factory &);
		const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};

#endif