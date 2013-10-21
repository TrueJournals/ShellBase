/*
 * main.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: Bobby
 */

#include <Shell.h>

#include "Calculator.h"

int main(int argc, char * argv[])
{
	Calculator calc;
	Shell shell(calc, "calc");

	shell.run();
}


