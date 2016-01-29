// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:27:42 by llapillo          #+#    #+#             //
//   Updated: 2016/01/29 15:05:19 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Avm.class.hpp"
#include "OperandFactory.class.hpp"
#include "lexer/Lexer.class.hpp"

int		loadFile(std::list< std::string > & commands, char const * file) {
	std::ifstream	input;
	std::string		str;

	input.open(file, std::ifstream::in);
	if (input.fail()) {
		std::cerr << strerror(errno) << std::endl;
		return (1);
	}
	while (std::getline(input, str))
		commands.push_back(str);

	input.close();

	return (0);
}

void	readInput(std::list< std::string > & commands) {
	std::string		str;

	while (std::getline(std::cin, str)) {
		if (str == ";;")
			break ;
		commands.push_back(str);
	}
}

int		main(int argc, char** argv) {

 	Avm							avm;
	std::list< std::string >	commands;

	if (argc < 3 && access(argv[1], X_OK)) {
		if (argc > 1) {
			if (loadFile(commands, argv[1]))
				return (1);
		}
		else
			readInput(commands);

		Lexer	lex(commands);

		try {
			lex.lex();
			avm.execCommands(lex);
		}
		catch (std::exception const & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Usage: ./avm [file]" << std::endl;
	return (0);

}
