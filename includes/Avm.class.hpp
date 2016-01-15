// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Avm.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/14 11:30:06 by llapillo          #+#    #+#             //
//   Updated: 2016/01/15 11:17:38 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		AVM_CLASS_HPP
# define	AVM_CLASS_HPP

# include <stack>
# include "IOperand.interface.hpp"

class	Avm {

private:

	std::stack< IOperand const * >					_stack;

	Avm(Avm const & src);

	void											operation(IOperand const * (IOperand::*op)(IOperand const &) const);

	Avm											&	operator=(Avm const &);

public:

	Avm();

	void											push(IOperand const * operand);
	void											pop(void) throw(Avm::EmptyStackException);
	void											dump(void) const;
	void											assert(IOperand const * operand) const throw(Avm::EmptyStackException,
																								 Avm::AssertException);

	void											add(void) throw(Avm::EmptyStackException,
																	Avm::NotSufficientValuesException);
	void											sub(void) throw(Avm::EmptyStackException,
																	Avm::NotSufficientValuesException);
	void											mul(void) throw(Avm::EmptyStackException,
																	Avm::NotSufficientValuesException);
	void											div(void) throw(Avm::EmptyStackException,
																	Avm::NotSufficientValuesException);
	void											mod(void) throw(Avm::EmptyStackException,
																	Avm::NotSufficientValuesException);
	void											print(void) const throw(Avm::EmptyStackException,
																			Avm::PrintException);

	virtual											~Avm();


	// ************************************************************************** //
	//                                 Exceptions                                 //
	// ************************************************************************** //

	class AssertException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw();

	};

	class PrintException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw();

	};

	class NotSufficientValuesException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw();

	};

	class EmptyStackException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw();

	};

};

#endif	//	AVM_CLASS_HPP
