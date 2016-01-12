// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/12 14:11:55 by niccheva          #+#    #+#             //
//   Updated: 2016/01/12 15:14:46 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		LEXER_CLASS_HPP
# define	LEXER_CLASS_HPP

# include "Command.class.hpp"
# include <list>
# include <iostream>

class	Lexer {

private:

	Lexer();
	Lexer(Lexer const & src);

	static  std::list< Command >			const		_commandList;
	std::istream							const	&	_input;

public:

	Lexer(std::istream const & input);

	void												lex(void) const;

	Lexer											&	operator=(Lexer const &);

	virtual												~Lexer();

};

#endif	//	LEXER_CLASS_HPP
