#ifndef		INT16_CLASS_HPP
# define	INT16_CLASS_HPP

# include "AOperand.template.hpp"

class	Int16 : public AOperand< int16_t > {

public:

	Int16();
	Int16(Int16 const & src);

	Int16					&	operator=(Int16 const & rhs);

	IOperand::eOperandType		getType(void) const;

	virtual						~Int16();

};

#endif	//	INT16_CLASS_HPP
