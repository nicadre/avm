// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/12 14:11:55 by niccheva          #+#    #+#             //
//   Updated: 2016/01/25 12:27:02 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		LEXER_CLASS_HPP
# define	LEXER_CLASS_HPP

# include "Command.class.hpp"
# include <list>
# include <iostream>

# include <boost/spirit/include/qi.hpp>
# include <boost/spirit/include/qi_string.hpp>
# include <boost/algorithm/string.hpp>
# include <fstream>

class	Lexer {

private:

	Lexer();
	Lexer(Lexer const & src);

	static  std::list< Command >			const		_commandList;
	std::istream									&	_input;

public:

	Lexer(std::istream & input);

	void												lex(void) const;
	void												tokenInput(std::string const & input, std::string & cmd, std::string & type, std::string & value) const;
	bool												parse_numbers(std::string::iterator first, std::string::iterator last) const;

	Lexer											&	operator=(Lexer const &);

	virtual												~Lexer();

	// ************************************************************************** //
	//                                 Exceptions                                 //
	// ************************************************************************** //

	class CommandUnknowException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class BadParameterException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class MissingExitProgramException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};



};

#endif	//	LEXER_CLASS_HPP
