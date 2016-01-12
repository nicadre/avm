// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AOperand.template.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:21:24 by llapillo          #+#    #+#             //
//   Updated: 2016/01/12 10:25:23 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

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
AOperand< T >::AOperand(std::string const & value, eOperandType const & type) {


	(void)value;
	(void)type;
/* check under/overflow

  double d = std::stod(value); // return double, throw exception if under/overflow
  if type == Int* {
    if d - static_cast< long long >(d) != 0.0 {
	  throw();
	}
  }
  switch type {
  case Int8:
    if !(static_cast< double>(INT8_MIN) <= d <= static_cast< double>(INT8_MAX)) {
	throw()
	}
	this->_value = stoT(value);
	...
  }
 */

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

	return &rhs;

}

template< typename T >
IOperand			const	*	AOperand< T >::operator-(IOperand const & rhs) const {

	return &rhs;

}

template< typename T >
IOperand			const	*	AOperand< T >::operator*(IOperand const & rhs) const {

	return &rhs;

}

template< typename T >
IOperand			const	*	AOperand< T >::operator/(IOperand const & rhs) const {

	return &rhs;

}

template< typename T >
IOperand			const	*	AOperand< T >::operator%(IOperand const & rhs) const {

	return &rhs;

}

template< typename T >
AOperand< T >				&	AOperand< T >::operator=(AOperand< T > const &) {

	return *this;

}

template< typename T >
std::ostream				&	operator<<(std::ostream & o, AOperand< T > const & rhs) {

	(void)rhs;

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
