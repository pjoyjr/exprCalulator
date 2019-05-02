/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <bits/stdc++.h> 
#include "Calc.h"


// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.

//moved methods to Calc.h and Calc.cpp

int main()
{
	std::cout << "Starting program..." << std::endl;
	Calc calculator;
	std::string infix;

	std::cout << "Please enter an infixed expression (QUIT to quit): " << std::endl;
	std::getline (std::cin, infix);
	while(infix != "QUIT")
	{
		int result;
		bool check = calculator.calculate(infix, result);
		if(check)
			std::cout << result << std::endl;
		else
		//should throw error here for invalid infix but printing invalid instead to lets test cases keep testing
		//throw invalid_infix("invalid infix!");
			std::cout << "invalid" << std::endl;
		std::cout << "Please enter an infixed expression (QUIT to quit): " << std::endl;
		std::getline (std::cin, infix);
	}
	std::cout << "Ending program" << std::endl; 
	return 0;
}