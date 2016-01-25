// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/12 14:11:48 by niccheva          #+#    #+#             //
//   Updated: 2016/01/25 12:32:44 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "lexer/Lexer.class.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                Constructors                                */
/*                                                                            */
/* ************************************************************************** */

Lexer::Lexer() : _input(std::cin) {}

Lexer::Lexer(Lexer const & src) : _input(std::cin) {

	*this = src;

}

Lexer::Lexer(std::istream & input) : _input(input) {}

/* ************************************************************************** */
/*                                                                            */
/*                              Member Functions                              */
/*                                                                            */
/* ************************************************************************** */

void											Lexer::lex(void) const {
	std::string		str;
	std::string	errors;
	int line = 1;

	while (std::getline(this->_input, str)) {
		std::string	m;
		std::string	cmd;
		std::string	type;
		std::string	value;
		if (str == "q" || str == "Q" || str == ";;")
			break ;
		if (str == "")
			continue ;
		m = this->parse_numbers(str.begin(), str.end()) ? "succeed" : "fail";
		//std::cout << m << std::endl;
		if (m == "succeed") {
			this->tokenInput(str.substr(str.find_first_not_of(" ")), cmd, type, value);
			//std::cout << cmd;
			//if (type != "")
			//	std::cout << " " << type << " ( " << value << " ) ";
			//std::cout << std::endl;
		}
		else {
			tokenInput(str.substr(str.find_first_not_of(" ")), cmd, type, value);
			errors += "Error line " + std::to_string(line) + " : "+ str + "\n";
		}
		line++;
	}
	//this->_input.close();
	std::cout << errors;

	// std::string		s;

	// while (s != ";;") {

	// 	std::getline(this->_input, s);

	// 	if (this->_input.eof()) {

	// 		break;

	// 	}

	// }
	//(void)this->_input;

}

void	Lexer::tokenInput(std::string const & input, std::string & cmd, std::string & type, std::string & value) const {

	std::vector< std::string >	tokens;
	boost::split(tokens, input, boost::is_any_of(" "), boost::token_compress_on);

	cmd = tokens[0];

	if (tokens.size() > 1) {
		type = tokens[1].substr(0, tokens[1].find("("));
		value = tokens[1].substr(tokens[1].find("(") + 1, tokens[1].size() - tokens[1].find("(") - 2);
	}

}

bool	Lexer::parse_numbers(std::string::iterator first, std::string::iterator last) const {
	using boost::spirit::qi::double_;
	using boost::spirit::qi::phrase_parse;
	using boost::spirit::ascii::space;
	using boost::spirit::ascii::string;
	using boost::spirit::qi::char_;

	auto commands_with_arguments = ((string("push") | string("assert")) >> ((string("int") >> (string("8") | string("16") | string("32"))) | string("float") | string("double")) >> char_('(') >> double_ >> char_(')'));
	auto commands_without_args = (string("pop") | string("dump") | string("add") | string("sub") | string("mul") | string("div") | string("mod") | string("print") | string("exit"));
	auto comments = ';' >> *(char_);

	bool r = phrase_parse(
		first,
		last,
		-(commands_with_arguments | commands_without_args)
		>> -(comments),
		space
		);
	if (first != last)
		return false;
	return r;
}

/* ************************************************************************** */
/*                                                                            */
/*                            Non Member Functions                            */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                             Operator Overloads                             */
/*                                                                            */
/* ************************************************************************** */

Lexer										&	Lexer::operator=(Lexer const &) {

	return *this;

}

/* ************************************************************************** */
/*                                                                            */
/*                                Destructors                                 */
/*                                                                            */
/* ************************************************************************** */

Lexer::~Lexer() {}

/* ************************************************************************** */
/*                                                                            */
/*                                 Exceptions                                 */
/*                                                                            */
/* ************************************************************************** */

char	const	*	Lexer::CommandUnknowException::what() const throw() {

	return "command unknow";

}

char	const	*	Lexer::BadParameterException::what() const throw() {

	return "the command's parameter isn't correct";

}

char	const	*	Lexer::MissingExitProgramException::what() const throw() {

	return "exit program not found";

}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */

std::list< Command >	const					Lexer::_commandList {

	Command("push", true),
	Command("pop", false),
	Command("assert", true),
	Command("exit", false),
	Command("dump", false),
	Command("add", false),
	Command("sub", false),
	Command("mult", false),
	Command("div", false),
	Command("mod", false),
	Command("print", false)

};

/* ************************************************************************** */
