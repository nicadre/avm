// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int32.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 18:36:17 by niccheva          #+#    #+#             //
//   Updated: 2016/02/07 16:08:20 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Int32.class.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                Constructors                                */
/*                                                                            */
/* ************************************************************************** */

Int32::Int32() {}

Int32::Int32(Int32 const & src) {

	*this = src;

}

Int32::Int32(std::string const & value) :
	AOperand< int32_t >(value, IOperand::eOperandType::Int32) {}

/* ************************************************************************** */
/*                                                                            */
/*                              Member Functions                              */
/*                                                                            */
/* ************************************************************************** */

IOperand::eOperandType		Int32::getType(void) const {

	return (IOperand::eOperandType::Int32);

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

Int32				&	Int32::operator=(Int32 const & rhs) {

	AOperand< int32_t >::operator=(rhs);

	return *this;

}

/* ************************************************************************** */
/*                                                                            */
/*                                Destructors                                 */
/*                                                                            */
/* ************************************************************************** */

Int32::~Int32() {}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
