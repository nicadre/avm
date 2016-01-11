// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Double.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 18:36:49 by llapillo          #+#    #+#             //
//   Updated: 2016/01/11 18:36:59 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Double.class.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                Constructors                                */
/*                                                                            */
/* ************************************************************************** */

Double::Double() {}

Double::Double(Double const & src) {

	*this = src;

}

Double::Double(std::string const & value) : AOperand< double >(value, IOperand::eOperandType::Double) {

}

/* ************************************************************************** */
/*                                                                            */
/*                              Member Functions                              */
/*                                                                            */
/* ************************************************************************** */

IOperand::eOperandType		Double::getType(void) const {

	return (IOperand::eOperandType::Double);

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

Double				&	Double::operator=(Double const & rhs) {

	AOperand< double >::operator=(rhs);

	return *this;

}

/* ************************************************************************** */
/*                                                                            */
/*                                Destructors                                 */
/*                                                                            */
/* ************************************************************************** */

Double::~Double() {}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
