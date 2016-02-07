// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int16.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 18:07:29 by niccheva          #+#    #+#             //
//   Updated: 2016/02/07 16:01:38 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		INT16_CLASS_HPP
# define	INT16_CLASS_HPP

# include "AOperand.template.hpp"

class	Int16 : public AOperand< int16_t > {

private:

	Int16();
	Int16(Int16 const & src);

	Int16					&	operator=(Int16 const & rhs);

public:

	Int16(std::string const & value);

	IOperand::eOperandType		getType(void) const;

	virtual						~Int16();

};

#endif	//	INT16_CLASS_HPP
