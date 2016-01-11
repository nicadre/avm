// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AOperand.template.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:16:59 by llapillo          #+#    #+#             //
//   Updated: 2016/01/11 14:39:47 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		AOPERAND_TEMPLATE_HPP
# define	AOPERAND_TEMPLATE_HPP

template< typename T >
class	AOperand {

private:

	T									_value;

	AOperand< T >();
	AOperand< T >(AOperand< T > const & src);

	AOperand< T >					&	operator=(AOperand< T > const &);

public:

	virtual								~AOperand< T >();

};

#endif	//	AOPERAND_TEMPLATE_HPP
