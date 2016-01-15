// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Avm.class.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/14 11:29:59 by llapillo          #+#    #+#             //
//   Updated: 2016/01/15 11:18:16 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Avm.class.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                Constructors                                */
/*                                                                            */
/* ************************************************************************** */

Avm::Avm() {}

Avm::Avm(Avm const & src) {

	*this = src;

}

/* ************************************************************************** */
/*                                                                            */
/*                              Member Functions                              */
/*                                                                            */
/* ************************************************************************** */

void											Avm::push(IOperand const * operand) {

	this->_stack.push(operand);

}

void											Avm::pop(void) throw(Avm::EmptyStackException) {

	IOperand	const	*	top;

	if (this->_stack.empty()) {

		throw (Avm::EmptyStackException());

	}

	top = this->_stack.top();

	this->_stack.pop();
	delete top;

}

void											Avm::dump(void) const {

	std::stack< IOperand const * >	tmp(this->_stack);

	while (!tmp.empty()) {

		std::cout << tmp.top()->toString() << std::endl;
		tmp.pop();

	}

}

void											Avm::assert(IOperand const * operand) const throw(Avm::EmptyStackException,
																								  Avm::AssertException) {

	IOperand	const	*	op;

	if (this->_stack.empty()) {

		throw (Avm::EmptyStackException());

	}

	op = this->_stack.top();
	if (op->getType() != operand->getType() || op->toString() != operand->toString()) {

		throw (Avm::AssertException());

	}

}

void											Avm::operation(IOperand const * (IOperand::*op)(IOperand const &) const) {

	IOperand	const	*	operand1;
	IOperand	const	*	operand2;

	if (this->_stack.empty()) {

		throw (Avm::EmptyStackException());

	} else if (this->_stack.size() < 2) {

		throw (Avm::NotSufficientValuesException());

	}

	operand1 = this->_stack.top();
	this->_stack.pop();
	operand2 = this->_stack.top();
	this->_stack.pop();

	this->push((operand2->*(op))(*operand1));

	delete operand1;
	delete operand2;

}

void											Avm::add(void) throw(Avm::EmptyStackException,
																	 Avm::NotSufficientValuesException) {

	this->operation(&IOperand::operator+);

}

void											Avm::sub(void) throw(Avm::EmptyStackException,
																	 Avm::NotSufficientValuesException) {

	this->operation(&IOperand::operator-);

}

void											Avm::mul(void) throw(Avm::EmptyStackException,
																	 Avm::NotSufficientValuesException) {

	this->operation(&IOperand::operator*);

}

void											Avm::div(void) throw(Avm::EmptyStackException,
																	 Avm::NotSufficientValuesException) {

	this->operation(&IOperand::operator/);

}

void											Avm::mod(void) throw(Avm::EmptyStackException,
																	 Avm::NotSufficientValuesException) {

	this->operation(&IOperand::operator%);

}

void											Avm::print(void) const throw(Avm::EmptyStackException,
																			 Avm::PrintException) {

	IOperand	const	*	op;

	if (this->_stack.empty()) {

		throw (Avm::EmptyStackException());

	}

	op = this->_stack.top();
	if (op->getType() != IOperand::eOperandType::Int8) {

		throw (Avm::PrintException());

	}

	std::cout << op << std::endl;

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

Avm										&	Avm::operator=(Avm const &) {

	return *this;

}

/* ************************************************************************** */
/*                                                                            */
/*                                Destructors                                 */
/*                                                                            */
/* ************************************************************************** */

Avm::~Avm() {}

/* ************************************************************************** */
/*                                                                            */
/*                                 Exceptions                                 */
/*                                                                            */
/* ************************************************************************** */

char		const	*	Avm::AssertException::what(void) const throw() {

	return "the value at the top of the stack is not equal to the one passed as parameter";

}

char		const	*	Avm::PrintException::what(void) const throw() {

	return "the value at the top of the stack is not a 8-bit integer";

}

char		const	*	Avm::NotSufficientValuesException::what(void) const throw() {

	return "the stack haven't sufficient values";

}

char		const	*	Avm::EmptyStackException::what(void) const throw() {

	return "the stack is empty";

}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
