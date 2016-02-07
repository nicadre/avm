// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/12 14:11:55 by niccheva          #+#    #+#             //
//   Updated: 2016/02/07 17:01:43 by niccheva         ###   ########.fr       //
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
	std::list< std::string >							_input;
	std::list< std::string >							_commands;
	int													_nbrErrors;

public:

	Lexer(std::list< std::string > & input);

	void												lex(void) throw(Lexer::ErrorGeneratedException);
	void												tokenInput(std::string const & input, std::string & cmd, std::string & type, std::string & value) const;
	bool												parse_numbers(std::string::iterator first, std::string::iterator last) const;
	void												detectError(std::string cmd, std::string type, std::string value) const throw(Lexer::CommandUnknowException, Lexer::NotEnoughParameterException, Lexer::TooManyParameterException, Lexer::BadTypeParameterException, Lexer::BadValueParameterException);

	std::list< std::string >							getCommands(void) const;

	Lexer											&	operator=(Lexer const &);

	virtual												~Lexer();

	// ************************************************************************** //
	//                                 Exceptions                                 //
	// ************************************************************************** //

	class CommandUnknowException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class TooManyParameterException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class NotEnoughParameterException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class BadTypeParameterException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class BadValueParameterException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class MissingExitProgramException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class ErrorGeneratedException : public std::exception {

	private:

		std::string					const	_message;

	public:

		ErrorGeneratedException(std::string const & _message);
		virtual	char		const	*	what(void) const throw ();

	};



};

#endif	//	LEXER_CLASS_HPP
