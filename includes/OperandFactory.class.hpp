// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OperandFactory.class.hpp                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 16:10:27 by llapillo          #+#    #+#             //
//   Updated: 2016/01/27 14:30:32 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		OPERANDFACTORY_CLASS_HPP
# define	OPERANDFACTORY_CLASS_HPP

# include <map>
# include "IOperand.interface.hpp"

class	OperandFactory {

private:

	typedef IOperand	const		*	(OperandFactory::*funPtr)(std::string const &) const;
	typedef std::map< IOperand::eOperandType, OperandFactory::funPtr >	funArray;

	static	funArray	const			funMap;

	OperandFactory();
	OperandFactory(OperandFactory const & src);

	IOperand	const				*	createInt8(std::string const & value) const;
	IOperand	const				*	createInt16(std::string const & value) const;
	IOperand	const				*	createInt32(std::string const & value) const;
	IOperand	const				*	createFloat(std::string const & value) const;
	IOperand	const				*	createDouble(std::string const & value) const;

	OperandFactory					&	operator=(OperandFactory const &);

public:

	static	OperandFactory	const	&	sharedInstance(void);

	IOperand	const				*	createOperand(IOperand::eOperandType type, std::string const & value) const;

	virtual								~OperandFactory();

};

#endif	//	OPERANDFACTORY_CLASS_HPP
