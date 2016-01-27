// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/12 14:11:48 by niccheva          #+#    #+#             //
//   Updated: 2016/01/27 11:23:36 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "lexer/Lexer.class.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                Constructors                                */
/*                                                                            */
/* ************************************************************************** */

Lexer::Lexer() : _input(std::cin), _nbrErrors(0) {}

Lexer::Lexer(Lexer const & src) : _input(std::cin), _nbrErrors(0) {

	*this = src;

}

Lexer::Lexer(std::istream & input) : _input(input), _nbrErrors(0) {}

/* ************************************************************************** */
/*                                                                            */
/*                              Member Functions                              */
/*                                                                            */
/* ************************************************************************** */

void											Lexer::lex(void) throw(Lexer::ErrorGeneratedException) {
	std::string					str;
	int							line = 0;
	int							str_begin = 0;
	int							str_end = 0;
	std::string					str_clean = "";
	std::string					cmd = "";
	std::string					type = "";
	std::string					value = "";
	std::list< std::string >	commands;

	while (std::getline(this->_input, str)) {
		line++;
		cmd = "";
		type = "";
		value = "";

		if (str == ";;")
			break ;
		if (str == "")
			continue ;

		str_begin = str.find_first_not_of(" ");
		str_end = (str.find_first_of(";") == std::string::npos) ? str.size() - str_begin : str.find_first_of(";");
		str_clean = str.substr(str_begin, str_end);
		if (!(this->parse_numbers(str.begin(), str.end()))) {
			try {
				this->tokenInput(str_clean, cmd, type, value);
				this->detectError(cmd, type, value);
			}
			catch (std::exception & e) {
				std::cerr << "Error line " << std::to_string(line) << " : " << str << " : " << e.what() << std::endl;
			}
			_nbrErrors++;
		}
		else {
			if (str_clean != "")
				commands.push_back(str.substr(str_begin, str_end));
		}
	}

	try {
		this->searchExitProgram(commands);
	}
	catch ( std::exception & e) {
		std::cerr << "Error file: " << e.what() << std::endl;
		(this->_nbrErrors)++;
	}

	if (_nbrErrors > 0) {
		throw (Lexer::ErrorGeneratedException(std::to_string(_nbrErrors) + " error(s) generated"));
	}

	this->_commands = commands;
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

void	Lexer::detectError(std::string cmd, std::string type, std::string value) const throw(Lexer::CommandUnknowException, Lexer::NotEnoughParameterException, Lexer::TooManyParameterException, Lexer::BadTypeParameterException, Lexer::BadValueParameterException) {
	using boost::spirit::qi::parse;
	using boost::spirit::ascii::string;
	using boost::spirit::qi::char_;

	std::list< Command >::const_iterator	it = this->_commandList.begin();
	bool									result = true;
	std::string::iterator					bt = type.begin();
	std::string::iterator					et = type.end();
	std::string::iterator					bv = value.begin();
	std::string::iterator					ev = value.end();
	auto types = (string("int8") | string("int16") | string("int32") | string("double") | string("float"));

	while (it != this->_commandList.end()) {
		if (cmd == it->name()) {

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

void	Lexer::searchExitProgram(std::list< std::string > & commands) const throw(Lexer::MissingExitProgramException) {
	bool	exitProgram = false;

	for (std::list< std::string >::const_iterator it = commands.begin(); it != commands.end(); it++) {
		if (*it == "exit")
			exitProgram = true;
	}
	if (!exitProgram)
		throw (Lexer::MissingExitProgramException());
}

std::list< std::string >							Lexer::getCommands(void) const {
	return this->_commands;
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

	return "the value of the parameter isn't correct";

}

char	const	*	Lexer::MissingExitProgramException::what() const throw() {

	return "exit program not found";

}

Lexer::ErrorGeneratedException::ErrorGeneratedException(std::string const & message) : _message(message) { return ; }

char	const	*	Lexer::ErrorGeneratedException::what() const throw() {

	return (_message.c_str());

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
