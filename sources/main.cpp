// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:27:42 by llapillo          #+#    #+#             //
//   Updated: 2016/01/25 12:37:12 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Avm.class.hpp"
#include "OperandFactory.class.hpp"

#include <stdio.h>
#include <string.h>
#include <vector>

#include "lexer/Lexer.class.hpp"

int		main(int argc, char** argv) {

// 	Avm		avm;

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

	lex.lex();

	input.close();
	return (0);

}
