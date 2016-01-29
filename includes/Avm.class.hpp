// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Avm.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/14 11:30:06 by llapillo          #+#    #+#             //
//   Updated: 2016/01/29 15:03:41 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		AVM_CLASS_HPP
# define	AVM_CLASS_HPP

# include "IOperand.interface.hpp"
# include "lexer/Lexer.class.hpp"
# include "OperandFactory.class.hpp"

# include <map>
# include <list>
# include <stack>
# include <unistd.h>

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

	void											operation(IOperand const * (IOperand::*op)(IOperand const &) const);

	Avm											&	operator=(Avm const &);

public:

	Avm();

	void											push(IOperand const * operand);
	void											pop(void);
	void											dump(void);
	void											assertAvm(IOperand const * operand);

	void											add(void) ;
	void											sub(void);
	void											mul(void);
	void											div(void);
	void											mod(void);
	void											print(void);

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
