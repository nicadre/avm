// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/12 14:11:55 by niccheva          #+#    #+#             //
//   Updated: 2016/01/12 14:24:19 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		LEXER_CLASS_HPP
# define	LEXER_CLASS_HPP

# include "lexer/Command.class.hpp"
# include <list>
# include <iostream>

class	Lexer {

private:

	Lexer();
	Lexer(Lexer const & src);

	static  std::list< Command >			const		_commandList;
	std::istream										_input;

public:

	Lexer(std::istream const & input);

	Lexer											&	operator=(Lexer const & rhs);

	virtual												~Lexer();

};

#endif	//	LEXER_CLASS_HPP
