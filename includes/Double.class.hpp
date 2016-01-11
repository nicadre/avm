// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Double.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 18:13:05 by llapillo          #+#    #+#             //
//   Updated: 2016/01/11 18:14:38 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		DOUBLE_CLASS_HPP
# define	DOUBLE_CLASS_HPP

# include "AOperand.template.hpp"

class	Double : public AOperand< double > {

private:

	Double();
	Double(Double const & src);

	Double					&	operator=(Double const & rhs);

public:

	Double(std::string const & value);

	IOperand::eOperandType		getType(void) const;

	virtual						~Double();

};

#endif	//	DOUBLE_CLASS_HPP
