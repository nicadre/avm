// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Float.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 18:12:15 by niccheva          #+#    #+#             //
//   Updated: 2016/02/07 16:01:09 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		FLOAT_CLASS_HPP
# define	FLOAT_CLASS_HPP

# include "AOperand.template.hpp"

class	Float : public AOperand< float > {

private:

	Float();
	Float(Float const & src);

	Float					&	operator=(Float const & rhs);

public:

	Float(std::string const & value);

	IOperand::eOperandType		getType(void) const;

	virtual						~Float();

};

#endif	//	FLOAT_CLASS_HPP
