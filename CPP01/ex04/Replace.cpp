/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:37:44 by swied             #+#    #+#             */
/*   Updated: 2025/12/08 09:23:02 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

static std::string manualReplace(std::string content, const std::string &s1, const std::string &s2) {

    if (s1.empty())
        return (content);
    std::string::size_type pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    return (content);
}

bool Replace::processFile(const std::string &filename, const std::string &s1, const std::string &s2) {

    std::ifstream input(filename.c_str());
    if (!input)
    {
        std::cerr << "Error: Cannot open input file\n";
        return false;
    }
    std::ofstream output((filename + ".replace").c_str());
    if (!output)
    {
        std::cerr << "Error: Cannot create output file\n";
        return false;
    }
    std::string line;
    while (std::getline(input, line))
    {
        output << manualReplace(line, s1, s2);
        if (!input.eof())
            output << "\n";
    }
    input.close();
    output.close();
    return true;
}
