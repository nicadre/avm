// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Avm.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/14 11:30:06 by llapillo          #+#    #+#             //
//   Updated: 2016/01/14 16:07:33 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		AVM_CLASS_HPP
# define	AVM_CLASS_HPP

# include <stack>
# include "AOperand.template.hpp"

template< typename T >
class	Avm {

private:

	std::stack< AOperand< T > >						_stack;

public:

	Avm();
	Avm(Avm const & src);


	void											push(AOperand< T > const operand);
	void											pop(void) throw();
	void											dump(void);
	void											assert(AOperand< T > const operand) throw();

	void											popOperation(AOperand< T > *op1, AOperand< T > *op2);
	void											add(void) throw();
	void											sub(void) throw();
	void											mul(void) throw();
	void											div(void) throw();
	void											mod(void) throw();
	void											print(void);

	Avm											&	operator=(Avm const & rhs);

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
