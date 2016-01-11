// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int8.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 15:17:34 by llapillo          #+#    #+#             //
//   Updated: 2016/01/11 15:55:32 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Int8.class.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                Constructors                                */
/*                                                                            */
/* ************************************************************************** */

Int8::Int8() {}

Int8::Int8(Int8 const & src) {

	*this = src;

}

Int8::Int8(std::string const & value) :
	AOperand< int8_t >(value, IOperand::eOperandType::Int8) {}

/* ************************************************************************** */
/*                                                                            */
/*                              Member Functions                              */
/*                                                                            */
/* ************************************************************************** */

IOperand::eOperandType		Int8::getType(void) const {

	return (IOperand::eOperandType::Int8);

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

Int8				&	Int8::operator=(Int8 const & rhs) {


	return *this;

}

/* ************************************************************************** */
/*                                                                            */
/*                                Destructors                                 */
/*                                                                            */
/* ************************************************************************** */

Int8::~Int8() {}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
