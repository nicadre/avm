// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Float.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 18:36:29 by llapillo          #+#    #+#             //
//   Updated: 2016/01/12 10:21:56 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Float.class.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                Constructors                                */
/*                                                                            */
/* ************************************************************************** */

Float::Float() {}

Float::Float(Float const & src) {

	*this = src;

}

Float::Float(std::string const & value) :
	AOperand< float >(value, IOperand::eOperandType::Float) {}

/* ************************************************************************** */
/*                                                                            */
/*                              Member Functions                              */
/*                                                                            */
/* ************************************************************************** */

IOperand::eOperandType		Float::getType(void) const {

	return (IOperand::eOperandType::Float);

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

Float				&	Float::operator=(Float const & rhs) {

	AOperand< float >::operator=(rhs);

	return *this;

}

/* ************************************************************************** */
/*                                                                            */
/*                                Destructors                                 */
/*                                                                            */
/* ************************************************************************** */

Float::~Float() {}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
