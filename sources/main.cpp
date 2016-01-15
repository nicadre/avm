// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/11 14:27:42 by llapillo          #+#    #+#             //
//   Updated: 2016/01/15 11:38:50 by llapillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Avm.class.hpp"
#include "OperandFactory.class.hpp"

int		main(void) {

	Avm		avm;

	avm.push(OperandFactory::sharedInstance().createOperand(IOperand::eOperandType::Int8, "42"));
	avm.push(OperandFactory::sharedInstance().createOperand(IOperand::eOperandType::Int16, "42"));

	try {

		avm.print();
		avm.pop();
		avm.print();
		avm.pop();
		avm.print();
		avm.pop();

	} catch (std::exception const & e) {

		std::cout << e.what() << std::endl;

	}

	return (0);

}
