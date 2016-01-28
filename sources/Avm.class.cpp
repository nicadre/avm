// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Avm.class.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/14 11:29:59 by llapillo          #+#    #+#             //
//   Updated: 2016/01/28 15:05:58 by llapillo         ###   ########.fr       //
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

void											Avm::pop(void) {

	IOperand	const	*	top;

	if (this->_stack.empty()) {

		throw (Avm::EmptyStackException());

	}

	top = this->_stack.top();

	this->_stack.pop();
	delete top;

}

void											Avm::dump(void) {

	std::stack< IOperand const * >	tmp(this->_stack);

	while (!tmp.empty()) {

		std::cout << tmp.top()->toString() << std::endl;
		tmp.pop();

	}

}

void											Avm::assertAvm(IOperand const * operand) {

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

void											Avm::add(void) {

	this->operation(&IOperand::operator+);

}

void											Avm::sub(void) {

	this->operation(&IOperand::operator-);

}

void											Avm::mul(void) {

	this->operation(&IOperand::operator*);

}

void											Avm::div(void) {

	this->operation(&IOperand::operator/);

}

void											Avm::mod(void) {

	this->operation(&IOperand::operator%);

}

void											Avm::print(void) {

	IOperand	const	*	op;

	if (this->_stack.empty()) {

		throw (Avm::EmptyStackException());

	}

	op = this->_stack.top();
	if (op->getType() != IOperand::eOperandType::Int8) {

		throw (Avm::PrintException());

	}

	std::cout << static_cast< char >(std::stoi(op->toString())) << std::endl;

}

void											Avm::execCommands(Lexer const & lex) {
	std::string					line = "";
	std::string					cmd = "";
	std::string					type = "";
	std::string					value = "";
	std::string					command = "";
	std::list< std::string >	commands;

	commands = lex.getCommands();
	for (std::list< std::string >::const_iterator it = commands.begin(); it != commands.end(); it++) {
		line = (*it).substr(0, (*it).find_first_of(" "));
		cmd = "";
		type = "";
		value = "";
		command = ((*it).substr(line.size()));
		command = command.substr(command.find_first_not_of(" "));
		lex.tokenInput(command, cmd, type, value);
		if (cmd == "exit")
			return ;

		try {
			if (cmd == "push" || cmd == "assert")
				(this->*(Avm::funMapArgs.at(cmd)))(OperandFactory::sharedInstance().createOperand(Avm::typesMap.at(type), value));
			else
				(this->*(Avm::funMap.at(cmd)))();
		}
		catch (std::exception const & e) {

			std::cerr << "Error: line " << line << ": ";
			throw;

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

	return "the stack hasn't sufficient values";

}

char		const	*	Avm::EmptyStackException::what(void) const throw() {

	return "the stack is empty";

}

/* ************************************************************************** */
/*                                                                            */
/*                           Non Member Attributes                            */
/*                                                                            */
/* ************************************************************************** */

Avm::funArrayArgs	const		Avm::funMapArgs {

	{ "push",	&Avm::push },
	{ "assert",	&Avm::assertAvm }

};

Avm::funArray		const		Avm::funMap {

	{ "pop",	&Avm::pop },
	{ "dump",	&Avm::dump },
	{ "add",	&Avm::add },
	{ "sub",	&Avm::sub },
	{ "mul",	&Avm::mul },
	{ "div",	&Avm::div },
	{ "mod",	&Avm::mod },
	{ "print",	&Avm::print }

};

Avm::typesArray		const		Avm::typesMap {

	{ "int8",	IOperand::eOperandType::Int8 },
	{ "int16",	IOperand::eOperandType::Int16 },
	{ "int32",	IOperand::eOperandType::Int32 },
	{ "float",	IOperand::eOperandType::Float },
	{ "double",	IOperand::eOperandType::Double }

};

/* ************************************************************************** */
