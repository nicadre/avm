// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:27:42 by llapillo          #+#    #+#             //
//   Updated: 2016/01/27 15:38:04 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Avm.class.hpp"
#include "OperandFactory.class.hpp"

#include <stdio.h>
#include <string.h>
#include <vector>

#include "lexer/Lexer.class.hpp"

int		main(int argc, char** argv) {

 	Avm		avm;

// 	avm.push(OperandFactory::sharedInstance().createOperand(IOperand::eOperandType::Int8, "42"));
// //	avm.push(OperandFactory::sharedInstance().createOperand(IOperand::eOperandType::Int16, "42"));

// 	try {

// 		avm.print();
// 		avm.pop();
// 		avm.print();
// 		avm.pop();
// 		avm.print();
// 		avm.pop();

// 	} catch (std::exception const & e) {

// 		std::cout << e.what() << std::endl;

// 	}
	std::ifstream	input(argv[1]);
	(void)argc;
	Lexer	lex(input);
	std::list< std::string >	commands;

	std::string					cmd = "";
	std::string					type = "";
	std::string					value = "";


	try {
		lex.lex();
		avm.execCommands(lex);
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

	input.close();
	return (0);

}
