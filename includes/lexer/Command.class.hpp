// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Command.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/12 13:55:22 by niccheva          #+#    #+#             //
//   Updated: 2016/01/12 14:25:18 by niccheva         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		COMMAND_CLASS_HPP
# define	COMMAND_CLASS_HPP

# include <string>

class	Command {

private:

	std::string						_name;
	bool							_arguments;

public:

	Command();
	Command(Command const & src);
	Command(std::string const & name, bool const & arguments);

	Command						&	operator=(Command const & rhs);

	virtual							~Command();

	Command						&	arguments(bool const & arguments);
	Command						&	name(std::string const & name);

	bool				const	&	arguments() const;
	std::string			const	&	name() const;

};

#endif	//	COMMAND_CLASS_HPP
