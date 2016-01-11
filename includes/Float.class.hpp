// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Float.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 18:12:15 by llapillo          #+#    #+#             //
//   Updated: 2016/01/11 18:14:32 by llapillo         ###   ########.fr       //
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
