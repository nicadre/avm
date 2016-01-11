// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IOperand.interface.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:12:54 by llapillo          #+#    #+#             //
//   Updated: 2016/01/11 14:39:15 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IOPERAND_INTERFACE_HPP
# define IOPERAND_INTERFACE_HPP

class IOperand {

public:

	virtual	int							getPrecision( void ) const = 0;
	virtual	eOperandType				getType( void ) const = 0;
	virtual	IOperand		const	*	operator+( IOperand const & rhs ) const = 0;
	virtual	IOperand		const	*	operator-( IOperand const & rhs ) const = 0;
	virtual	IOperand		const	*	operator*( IOperand const & rhs ) const = 0;
	virtual	IOperand		const	*	operator/( IOperand const & rhs ) const = 0;
	virtual	IOperand		const	*	operator%( IOperand const & rhs ) const = 0;
	virtual	std::string		const	&	toString( void ) const = 0;
	virtual	~IOperand( void ) {}

};

#endif
