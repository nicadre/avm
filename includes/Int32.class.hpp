#ifndef		INT32_CLASS_HPP
# define	INT32_CLASS_HPP

# include "AOperand.template.hpp"

class	Int32 : public AOperand< int32_t > {

public:

	Int32();
	Int32(Int32 const & src);

	Int32					&	operator=(Int32 const & rhs);

	virtual						~Int32();

};

#endif	//	INT32_CLASS_HPP
