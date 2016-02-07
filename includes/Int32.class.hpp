// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int32.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 18:11:38 by niccheva          #+#    #+#             //
//   Updated: 2016/02/07 16:01:50 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		INT32_CLASS_HPP
# define	INT32_CLASS_HPP

# include "AOperand.template.hpp"

class	Int32 : public AOperand< int32_t > {

private:


	Int32();
	Int32(Int32 const & src);

	Int32					&	operator=(Int32 const & rhs);

public:

	Int32(std::string const & value);

	IOperand::eOperandType		getType(void) const;

	virtual						~Int32();

};

#endif	//	INT32_CLASS_HPP
