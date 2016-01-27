// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AOperand.template.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:21:24 by llapillo          #+#    #+#             //
//   Updated: 2016/01/27 17:53:09 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cfloat>
#include <cstdint>
#include "AOperand.template.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                Constructors                                */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
AOperand< T >::AOperand() {}

template< typename T >
AOperand< T >::AOperand(AOperand< T > const & src) {

	*this = src;

}

template< typename T >
AOperand< T >::AOperand(std::string const & value, IOperand::eOperandType const & type) {

	try {

		long double	d = std::stold(value);

		if (type == IOperand::eOperandType::Int8
			|| type == IOperand::eOperandType::Int16
			|| type == IOperand::eOperandType::Int32) {

			if (d - static_cast< long long >(d) != 0.0) {

				throw (AOperand< T >::BadTypeException());

			}

		}

		switch (type) {

		case IOperand::eOperandType::Int8:

			checkOutOfRange(d, INT8_MIN, INT8_MAX);
			break;

		case IOperand::eOperandType::Int16:

			checkOutOfRange(d, INT16_MIN, INT16_MAX);
			break;

		case IOperand::eOperandType::Int32:

			checkOutOfRange(d, INT32_MIN, INT32_MAX);
			break;

		case IOperand::eOperandType::Float:

			checkOutOfRange(d, FLT_MIN, FLT_MAX);
			break;

		case IOperand::eOperandType::Double:

			checkOutOfRange(d, DBL_MIN, DBL_MAX);
			break;

		}

		this->_value = static_cast< T >(d);

	} catch (std::exception const & e) {

		throw;

	}

}

template< typename T>
void							AOperand< T >::checkOutOfRange(long double d,
															   long double min,
															   long double max) {

	if (d < min) {

		throw (AOperand< T >::UnderflowException());

	}

	if (d > max) {

		throw (AOperand< T >::OverflowException());

	}

}

/* ************************************************************************** */
/*                                                                            */
/*                              Member Functions                              */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
int								AOperand< T >::getPrecision(void) const {

	return (static_cast< int >(this->getType()));

}

template< typename T >
std::string			const	&	AOperand< T >::toString(void) const {

	this->_str = std::to_string(this->_value);

	return (this->_str);

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

template< typename T >
IOperand			const	*	AOperand< T >::operator+(IOperand const & rhs) const {

	long double				result;
	IOperand::eOperandType	type;

	type = (this->getPrecision() >= rhs.getPrecision()) ? this->getType() : rhs.getType();
	result	= this->_value + std::stold(rhs.toString());

	return (OperandFactory::sharedInstance().createOperand(type, std::to_string(result)));

}

template< typename T >
IOperand			const	*	AOperand< T >::operator-(IOperand const & rhs) const {

	long double				result;
	IOperand::eOperandType	type;

	type = (this->getPrecision() >= rhs.getPrecision()) ? this->getType() : rhs.getType();
	result	= this->_value - std::stold(rhs.toString());
	return (OperandFactory::sharedInstance().createOperand(type, std::to_string(result)));

}

template< typename T >
IOperand			const	*	AOperand< T >::operator*(IOperand const & rhs) const {

	long double				result;
	IOperand::eOperandType	type;

	type = (this->getPrecision() >= rhs.getPrecision()) ? this->getType() : rhs.getType();
	result	= this->_value * std::stold(rhs.toString());
	return (OperandFactory::sharedInstance().createOperand(type, std::to_string(result)));

}

template< typename T >
IOperand			const	*	AOperand< T >::operator/(IOperand const & rhs) const {

	long double				result;
	IOperand::eOperandType	type;

	if (std::stoi(rhs.toString()) == 0)
		throw (AOperand< T >::DivisionByZeroException());

	type = (this->getPrecision() >= rhs.getPrecision()) ? this->getType() : rhs.getType();
	result	= this->_value / std::stold(rhs.toString());
	return (OperandFactory::sharedInstance().createOperand(type, std::to_string(result)));

}

template< typename T >
IOperand			const	*	AOperand< T >::operator%(IOperand const & rhs) const {

	long double				result;
	IOperand::eOperandType	type;

	if (std::stoi(rhs.toString()) == 0)
		throw (AOperand< T >::DivisionByZeroException());
	/* add modulo with float exception */

	type = (this->getPrecision() >= rhs.getPrecision()) ? this->getType() : rhs.getType();
	result	= this->_value / std::stold(rhs.toString());
	return (OperandFactory::sharedInstance().createOperand(type, std::to_string(result)));

}

template< typename T >
AOperand< T >				&	AOperand< T >::operator=(AOperand< T > const &) {

	return *this;

}

template< typename T >
std::ostream				&	operator<<(std::ostream & o, AOperand< T > const & rhs) {

	(void) rhs;

	return	o;

}

/* ************************************************************************** */
/*                                                                            */
/*                                Destructors                                 */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
AOperand< T >::~AOperand() {}

/* ************************************************************************** */
/*                                                                            */
/*                                 Exceptions                                 */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
char	const	*	AOperand< T >::BadTypeException::what() const throw() {

	return "float value for integer value expected";

}

template< typename T >
char	const	*	AOperand< T >::OverflowException::what() const throw() {

	return "this value will overflow with the type specified";

}

template< typename T >
char	const	*	AOperand< T >::UnderflowException::what() const throw() {

	return "this value will underflow with the type specified";

}

template< typename T >
char	const	*	AOperand< T >::DivisionByZeroException::what() const throw() {

	return "division by zero isn't allowed";

}

template< typename T >
char	const	*	AOperand< T >::ModuloByZeroException::what() const throw() {

	return "modulo by zero isn't allowed";

}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                           Template Declarations                            */
/*                                                                            */
/* ************************************************************************** */

template class AOperand< int8_t >;
template class AOperand< int16_t >;
template class AOperand< int32_t >;
template class AOperand< float >;
template class AOperand< double >;

/* ************************************************************************** */
