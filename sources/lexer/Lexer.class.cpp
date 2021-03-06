// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/12 14:11:48 by niccheva          #+#    #+#             //
//   Updated: 2016/01/18 14:11:45 by llapillo         ###   ########.fr       //
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

	std::string		s;

	while (s != ";;") {

		std::getline(this->_input, s);

		if (this->_input.eof()) {

			break;

		}

	}

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
