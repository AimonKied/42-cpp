/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:37:46 by swied             #+#    #+#             */
/*   Updated: 2025/12/08 09:02:52 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

# include <string>
# include <fstream>
# include <iostream>

class Replace {
    public:
        static bool processFile(const std::string &filename, const std::string &s1, const std::string &s2);
};

#endif