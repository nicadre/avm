#ifndef		FLOAT_CLASS_HPP
# define	FLOAT_CLASS_HPP

# include "AOperand.template.hpp"

class	Float : public AOperand< float > {

public:

	Float();
	Float(Float const & src);

	Float					&	operator=(Float const & rhs);

	virtual						~Float();

};

#endif	//	FLOAT_CLASS_HPP
