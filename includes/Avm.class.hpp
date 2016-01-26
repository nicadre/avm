// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Avm.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/14 11:30:06 by llapillo          #+#    #+#             //
//   Updated: 2016/01/26 19:22:49 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		AVM_CLASS_HPP
# define	AVM_CLASS_HPP

# include <map>
# include <list>
# include <stack>
# include "IOperand.interface.hpp"
# include "lexer/Lexer.class.hpp"
#include "OperandFactory.class.hpp"

class	Avm {

private:
	typedef void					(Avm::*funPtrArgs)(IOperand const *) ;
	typedef void					(Avm::*funPtr)(void) ;

	typedef std::map< std::string, Avm::funPtrArgs >					funArrayArgs;
	typedef std::map< std::string, Avm::funPtr >						funArray;
	typedef std::map< std::string, IOperand::eOperandType >				typesArray;

	static	funArrayArgs	const						funMapArgs;
	static	funArray		const						funMap;
	static	typesArray		const						typesMap;

	std::stack< IOperand const * >					_stack;

	Avm(Avm const & src);

	void											operation(IOperand const * (IOperand::*op)(IOperand const &) const)
		throw (Avm::EmptyStackException,
			   Avm::NotSufficientValuesException);

	Avm											&	operator=(Avm const &);

public:

	Avm();

	void											push(IOperand const * operand);
	void											pop(void) throw (Avm::EmptyStackException);
	void											dump(void);
	void											assert2(IOperand const * operand)
		throw (Avm::EmptyStackException,
			   Avm::AssertException);

	void											add(void) throw (Avm::EmptyStackException,
																	Avm::NotSufficientValuesException);
	void											sub(void) throw (Avm::EmptyStackException,
																	Avm::NotSufficientValuesException);
	void											mul(void) throw (Avm::EmptyStackException,
																	Avm::NotSufficientValuesException);
	void											div(void) throw (Avm::EmptyStackException,
																	Avm::NotSufficientValuesException);
	void											mod(void) throw (Avm::EmptyStackException,
																	Avm::NotSufficientValuesException);
	void											print(void) throw (Avm::EmptyStackException,
																			Avm::PrintException);

	void											execCommands(Lexer const & lex);

	virtual											~Avm();


	// ************************************************************************** //
	//                                 Exceptions                                 //
	// ************************************************************************** //

	class AssertException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class PrintException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class NotSufficientValuesException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class EmptyStackException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

};

#endif	//	AVM_CLASS_HPP
