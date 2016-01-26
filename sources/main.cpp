// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:27:42 by llapillo          #+#    #+#             //
//   Updated: 2016/01/26 19:23:27 by llapillo         ###   ########.fr       //
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
		//commands = lex.getCommands();
		//for (std::list< std::string >::const_iterator it = commands.begin(); it != commands.end(); it++) {
		//	cmd = "";
		//	type = "";
		//	value = "";
		//	lex.tokenInput(*it, cmd, type, value);
			//if (cmd == "push" || cmd == "assert")
			//	avm.((Avm::funMapArgs.at(cmd))(OperandFactory::sharedInstance().createOperand(Avm::typesMap.at(type), value)));
			//else
			//	avm.((Avm::funMap.at(cmd))());
			//std::cout << *it << " = " << cmd << " " << type << " " << value << std::endl;
			//}
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	input.close();
	return (0);

}
