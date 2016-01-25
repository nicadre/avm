// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:27:42 by llapillo          #+#    #+#             //
//   Updated: 2016/01/25 12:20:08 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Avm.class.hpp"
#include "OperandFactory.class.hpp"

#include <stdio.h>
#include <string.h>
#include <vector>


#include "lexer/Lexer.class.hpp"

// bool	parse_numbers(std::string::iterator first, std::string::iterator last) {
// 	using boost::spirit::qi::double_;
// 	using boost::spirit::qi::phrase_parse;
// 	using boost::spirit::ascii::space;
// 	using boost::spirit::ascii::string;
// 	using boost::spirit::qi::char_;

// 	auto commands_with_arguments = ((string("push") | string("assert")) >> ((string("int") >> (string("8") | string("16") | string("32"))) | string("float") | string("double")) >> char_('(') >> double_ >> char_(')'));
// 	auto commands_without_args = (string("pop") | string("dump") | string("add") | string("sub") | string("mul") | string("div") | string("mod") | string("print") | string("exit"));
// 	auto comments = ';' >> *(char_);

// 	bool r = phrase_parse(
// 		first,
// 		last,
// 		-(commands_with_arguments | commands_without_args)
// 		>> -(comments),
// 		space
// 		);
// 	if (first != last)
// 		return false;
// 	return r;
// }

// void	tokenInput(std::string const & input, std::string & cmd, std::string & type, std::string & value) {

// 	std::vector< std::string >	tokens;
// 	boost::split(tokens, input, boost::is_any_of(" "), boost::token_compress_on);

// 	cmd = tokens[0];

// 	if (tokens.size() > 1) {
// 		type = tokens[1].substr(0, tokens[1].find("("));
// 		value = tokens[1].substr(tokens[1].find("(") + 1, tokens[1].size() - tokens[1].find("(") - 2);
// 	}

// }

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
	// std::string		str;
	std::ifstream	input(argv[1]);
	(void)argc;
	// std::string	errors;
	// int line = 1;
	Lexer	lex(input);

	lex.lex();
	// while (std::getline(input, str)) {
	// 	std::string	m;
	// 	std::string	cmd;
	// 	std::string	type;
	// 	std::string	value;
	// 	if (str == "q" || str == "Q" || str == ";;")
	// 		break ;
	// 	if (str == "")
	// 		continue ;
	// 	m = parse_numbers(str.begin(), str.end()) ? "succeed" : "fail";
	// 	//std::cout << m << std::endl;
	// 	if (m == "succeed") {
	// 		tokenInput(str.substr(str.find_first_not_of(" ")), cmd, type, value);
	// 		//std::cout << cmd;
	// 		//if (type != "")
	// 		//	std::cout << " " << type << " ( " << value << " ) ";
	// 		//std::cout << std::endl;
	// 	}
	// 	else {
	// 		tokenInput(str.substr(str.find_first_not_of(" ")), cmd, type, value);
	// 		errors += "Error line " + std::to_string(line) + " : "+ str + "\n";
	// 	}
	// 	line++;
	// }
	// input.close();
	// std::cout << errors;
	return (0);

}
