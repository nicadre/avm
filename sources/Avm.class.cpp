// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Avm.class.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/14 11:29:59 by llapillo          #+#    #+#             //
//   Updated: 2016/01/14 16:33:31 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Avm.class.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                Constructors                                */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
Avm< T >::Avm() {}

template< typename T >
Avm< T >::Avm(Avm const & src) {

	*this = src;

}

/* ************************************************************************** */
/*                                                                            */
/*                              Member Functions                              */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
void											Avm< T >::push(AOperand< T > const operand) {
	this->_stack.push(operand);
}

template< typename T >
void											Avm< T >::pop(void) throw() {
	if (this->_stack.empty())
		throw (Avm::EmptyStackException());
	this->_stack.pop();
}

template< typename T >
void											Avm< T >::dump(void) {
	std::stack< AOperand< T > >	tmp(this->_stack);

	while (!tmp.empty()) {
		std::cout << tmp.top()._value << std::endl;
		tmp.pop();
	}
}

template< typename T >
void											Avm< T >::assert(AOperand< T > const operand) throw() {
	AOperand< T >	op(this->_stack.top());

	if (op.getType() != operand.getType() || op.toString() != operand.toString())
		throw (Avm::AssertException());
}

template< typename T >
void											Avm< T >::popOperation(AOperand< T > *op1, AOperand< T > *op2) {
	if (this->_stack.empty())
		throw (Avm::EmptyStackException());
	else if (this->_stack.size() < 2)
		throw (Avm::NotSufficientValuesException());

	op1 = this->_stack.top();
	this->_stack.pop();
	op2 = this->_stack.top();
	this->_stack.pop();
}

template< typename T >
void											Avm< T >::add(void) throw() {

	AOperand< T >		op1;
	AOperand< T >		op2;
	AOperand< T >		result;

	this->popOperation(&op1, &op2);
	result = op1 + op2;
	this->push(result);
}

template< typename T >
void											Avm< T >::sub(void) throw() {
	AOperand< T >		op1;
	AOperand< T >		op2;
	AOperand< T >		result;

	this->popOperation(&op1, &op2);
	result = op1 - op2;
	this->push(result);

}

template< typename T >
void											Avm< T >::mul(void) throw() {
	AOperand< T >		op1;
	AOperand< T >		op2;
	AOperand< T >		result;

	this->popOperation(&op1, &op2);
	result = op1 * op2;
	this->push(result);

}

template< typename T >
void											Avm< T >::div(void) throw() {
	AOperand< T >		op1;
	AOperand< T >		op2;
	AOperand< T >		result;

	this->popOperation(&op1, &op2);
	result = op1 / op2;
	this->push(result);

}

template< typename T >
void											Avm< T >::mod(void) throw() {
	AOperand< T >		op1;
	AOperand< T >		op2;
	AOperand< T >		result;

	this->popOperation(&op1, &op2);
	result = op1 % op2;
	this->push(result);

}

template< typename T >
void											Avm< T >::print(void) {
	AOperand< T >	op(this->_stack.top());

	if (op.getType() != IOperand::eOperandType::Int8)
		throw (Avm::PrintException());

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

template< typename T >
Avm< T >										&	Avm< T >::operator=(Avm const & rhs) {

	this->_stack = rhs.stack();

	return *this;

}

/* ************************************************************************** */
/*                                                                            */
/*                                Destructors                                 */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
Avm< T >::~Avm() {}

/* ************************************************************************** */
/*                                                                            */
/*                                 Exceptions                                 */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
char		const	*	Avm< T >::AssertException::what(void) const throw() {
	return "the value at the top of the stack is not equal to the one passed as parameter";
}

template< typename T >
char		const	*	Avm< T >::PrintException::what(void) const throw() {
	return "the value at the top of the stack is not a 8-bit integer";
}

template< typename T >
char		const	*	Avm< T >::NotSufficientValuesException::what(void) const throw() {
	return "the stack haven't sufficient values";
}

template< typename T >
char		const	*	Avm< T >::EmptyStackException::what(void) const throw() {
	return "the stack is empty";
}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
