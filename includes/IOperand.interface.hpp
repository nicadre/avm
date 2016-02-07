// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IOperand.interface.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:12:54 by niccheva          #+#    #+#             //
//   Updated: 2016/02/07 16:01:23 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		IOPERAND_INTERFACE_HPP
# define	IOPERAND_INTERFACE_HPP

# include <iostream>

class IOperand {

public:

	enum class							eOperandType {
		Int8,
		Int16,
		Int32,
		Float,
		Double
	};

	virtual	int							getPrecision(void) const = 0;
	virtual	eOperandType				getType(void) const = 0;

	virtual	std::string		const	&	toString(void) const = 0;

	virtual	IOperand		const	*	operator+(IOperand const & rhs) const = 0;
	virtual	IOperand		const	*	operator-(IOperand const & rhs) const = 0;
	virtual	IOperand		const	*	operator*(IOperand const & rhs) const = 0;
	virtual	IOperand		const	*	operator/(IOperand const & rhs) const = 0;
	virtual	IOperand		const	*	operator%(IOperand const & rhs) const = 0;

	virtual	~IOperand(void) {}

};

#endif	//	IOPERAND_INTERFACE_HPP
