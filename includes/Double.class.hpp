#ifndef		DOUBLE_CLASS_HPP
# define	DOUBLE_CLASS_HPP

# include "AOperand.template.hpp"

class	Double : public AOperand< double > {

public:

	Double();
	Double(Double const & src);

	Double					&	operator=(Double const & rhs);

	virtual						~Double();

};

#endif	//	DOUBLE_CLASS_HPP
