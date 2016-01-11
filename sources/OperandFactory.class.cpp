// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OperandFactory.class.cpp                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 16:13:54 by llapillo          #+#    #+#             //
//   Updated: 2016/01/11 18:00:28 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OperandFactory.class.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                Constructors                                */
/*                                                                            */
/* ************************************************************************** */

OperandFactory::OperandFactory() {}

OperandFactory::OperandFactory(OperandFactory const & src) {

	*this = src;

}

/* ************************************************************************** */
/*                                                                            */
/*                              Member Functions                              */
/*                                                                            */
/* ************************************************************************** */

OperandFactory	const	&	OperandFactory::sharedInstance(void) {

	static	OperandFactory	fact;

	return (fact);

}

IOperand	const			*	OperandFactory::createOperand(IOperand::eOperandType type, std::string const & value) const {

	return (this->*(OperandFactory::funMap.at(type)))(value);

}

IOperand	const			*	OperandFactory::createInt8(std::string const & value) const {

	return (new Int8(value));

}

IOperand	const			*	OperandFactory::createInt16(std::string const & value) const {

	return (new Int16(value));

}

IOperand	const			*	OperandFactory::createInt32(std::string const & value) const {

	return (new Int32(value));

}

IOperand	const			*	OperandFactory::createFloat(std::string const & value) const {

	return (new Float(value));

}

IOperand	const			*	OperandFactory::createDouble(std::string const & value) const {

	return (new Double(value));

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

OperandFactory				&	OperandFactory::operator=(OperandFactory const & rhs) {


	return *this;

}

/* ************************************************************************** */
/*                                                                            */
/*                                Destructors                                 */
/*                                                                            */
/* ************************************************************************** */

OperandFactory::~OperandFactory() {}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */

const std::map< IOperand::eOperandType, OperandFactory::funPtr > OperandFactory::funMap {

	{IOperand::eOperandType::Int8, &OperandFactory::createInt8},
	{IOperand::eOperandType::Int16, &OperandFactory::createInt16},
	{IOperand::eOperandType::Int32, &OperandFactory::createInt32},
	{IOperand::eOperandType::Float, &OperandFactory::createFloat},
	{IOperand::eOperandType::Double, &OperandFactory::createDouble}

};

/* ************************************************************************** */
