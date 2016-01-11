// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AOperand.template.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:16:59 by llapillo          #+#    #+#             //
//   Updated: 2016/01/11 15:52:52 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		AOPERAND_TEMPLATE_HPP
# define	AOPERAND_TEMPLATE_HPP

# include "IOperand.interface.hpp"

template< typename T >
class	AOperand : public IOperand {

private:

	T									_value;

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

};

template< typename T >
std::ostream						&	operator<<(std::ostream & o, AOperand< T > const & rhs);

#endif	//	AOPERAND_TEMPLATE_HPP
