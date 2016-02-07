// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int8.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 15:16:37 by niccheva          #+#    #+#             //
//   Updated: 2016/02/07 16:01:31 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		INT8_CLASS_HPP
# define	INT8_CLASS_HPP

# include "AOperand.template.hpp"

class	Int8 : public AOperand< int8_t > {

private:

	Int8();
	Int8(Int8 const & src);

	Int8					&	operator=(Int8 const & rhs);

public:

	Int8(std::string const & value);

	IOperand::eOperandType		getType(void) const;

	virtual						~Int8();

};

#endif	//	INT8_CLASS_HPP
