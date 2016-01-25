// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/12 14:11:48 by niccheva          #+#    #+#             //
//   Updated: 2016/01/25 15:40:59 by llapillo         ###   ########.fr       //
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
	int				line = 1;
	bool			error = false;
	int				str_begin = 0;
	int				str_end = 0;
	std::string		cmd = "";
	std::string		type = "";
	std::string		value = "";

	while (std::getline(this->_input, str)) {
		cmd = "";
		type = "";
		value = "";

		if (str == "q" || str == "Q" || str == ";;")
			break ;
		if (str == "")
			continue ;

		if (!(this->parse_numbers(str.begin(), str.end()))) {
			error = true;
			try {
				str_begin = str.find_first_not_of(" ");
				str_end = (str.find_first_of(";") == std::string::npos) ? str.size() - str_begin : str.find_first_of(";");
//				std::cout << "\n" << str_begin << " " << str_end << " " << str.substr(str_begin, str_end) << " " << str.find_first_of(";") << std ::endl;
				this->tokenInput(str.substr(str_begin, str_end), cmd, type, value);
				this->detectError(cmd, type, value);
			}
			catch (std::exception & e) {
				std::cerr << "Error line " << std::to_string(line) << " : " << str << " : " << e.what() << std::endl;
			}
		}
		line++;
	}
	/* try catch search for exit program */

	//std::cout << errors;

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
	using boost::spirit::qi::double_;
	using boost::spirit::qi::phrase_parse;
	using boost::spirit::ascii::space;
	using boost::spirit::ascii::string;
	using boost::spirit::qi::char_;
	using boost::spirit::qi::matches;
	using boost::spirit::qi::attr;
	using boost::spirit::qi::parse;

bool	Lexer::parse_numbers(std::string::iterator first, std::string::iterator last) const {

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

void	Lexer::detectError(std::string cmd, std::string type, std::string value) const throw(Lexer::CommandUnknowException, Lexer::NotEnoughParameterException, Lexer::TooManyParameterException, Lexer::BadTypeParameterException, Lexer::BadValueParameterException) {
	std::list< Command >::iterator  it = this->_commandList.begin();
	bool							result = true;
	std::string::iterator			bt = type.begin();
	std::string::iterator			et = type.end();
	std::string::iterator			bv = value.begin();
	std::string::iterator			ev = value.end();
	auto types = (string("int8") | string("int16") | string("int32") | string("double") | string("float"));

	while(it != this->_commandList.end()) {
		if (cmd == it->name()) {

//			std::cout << "(" << cmd << ")" << "(" << type << ")" << "(" << value << ")" << std::endl;

			if ((it->arguments() && (type == "" || value == "")))
				throw (Lexer::NotEnoughParameterException());
			else if	(!(it->arguments()) && (type != "" || value != ""))
				throw (Lexer::TooManyParameterException());

			result = parse(bt, et, types);
			if (bt != et)
				throw (Lexer::BadTypeParameterException());

			result = parse(bv, ev, (*char_('0', '9') >> -(char_('.') >> *char_('0', '9'))));
			if (bv != ev)
				throw (Lexer::BadValueParameterException());

			break ;
		}
		it++;
	}
	if (it == this->_commandList.end())
		throw (Lexer::CommandUnknowException());
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

char	const	*	Lexer::TooManyParameterException::what() const throw() {

	return "there is too many arguments for this command";

}

char	const	*	Lexer::NotEnoughParameterException::what() const throw() {

	return "not enough parameter for this command";

}

char	const	*	Lexer::BadTypeParameterException::what() const throw() {

	return "the command's parameter haven't correct type";

}

char	const	*	Lexer::BadValueParameterException::what() const throw() {

	return "the type of the parameter isn't correct";

}

char	const	*	Lexer::MissingExitProgramException::what() const throw() {

	return "exit program not found";

}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */

//std::list< Command >	const					Lexer::_commandList {
std::list< Command >							Lexer::_commandList {

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
