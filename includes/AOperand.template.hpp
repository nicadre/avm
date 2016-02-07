// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AOperand.template.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:16:59 by niccheva          #+#    #+#             //
//   Updated: 2016/02/07 16:25:13 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		AOPERAND_TEMPLATE_HPP
# define	AOPERAND_TEMPLATE_HPP

# include "IOperand.interface.hpp"
# include "OperandFactory.class.hpp"
# include <math.h>

class OperandFactory;

template< typename T >
class	AOperand : public IOperand {

private:

	T									_value;
	mutable	std::string					_str;

	void								checkOutOfRange(long double d,
														long double max,
														long double min);

protected:

	AOperand< T >();
	AOperand< T >(AOperand< T > const & src);

	AOperand< T >					&	operator=(AOperand< T > const &);

public:

	AOperand< T >(std::string const & value, eOperandType const & type);

	int									getPrecision(void) const;
	virtual	eOperandType				getType(void) const = 0;

	std::string				const	&	toString(void) const;

	IOperand				const	*	operator+(IOperand const & rhs) const;
	IOperand				const	*	operator-(IOperand const & rhs) const;
	IOperand				const	*	operator*(IOperand const & rhs) const;
	IOperand				const	*	operator/(IOperand const & rhs) const;
	IOperand				const	*	operator%(IOperand const & rhs) const;

	virtual								~AOperand< T >();

	// ************************************************************************** //
	//                                 Exceptions                                 //
	// ************************************************************************** //

	class BadTypeException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class OverflowException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class UnderflowException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class DivisionByZeroException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class ModuloByZeroException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

	class ModuloWithFloatException : public std::exception {

	public:

		virtual	char		const	*	what(void) const throw ();

	};

};

#endif	//	AOPERAND_TEMPLATE_HPP
