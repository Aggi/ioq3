/*
===========================================================================
Copyright (C) 2020 Aggi

This file is part of cppioq3 source code.

cppioq3 source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

cppioq3 source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with cppioq3 source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

#include <fstream>
#include <iostream>
#include <string_view>
#include <string>



std::string replace(std::string str, std::string src, std::string dst)
{
    size_t index = 0;
    while (true) {
        /* Locate the substring to replace. */
        index = str.find(src, index);
        if (index == std::string::npos) break;

        /* Make the replacement. */
        str.replace(index, src.size(), dst);

        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += dst.size();
    }
    return str;
}


int main(int argc, char **argv)
{
    if(argc != 4) return -1;
    
    std::string_view basename(argv[1]);
    std::string_view in_file(argv[2]);
    std::string_view out_file(argv[3]);

    std::ifstream in(in_file.data());
    if(!in) return -2;
    std::ofstream out(out_file.data());
    if(!out) return -3;


    out << "const char *fallbackShader_" <<  basename << " =";

    std::string line;
    while(std::getline(in, line))
    {
        line = replace(line, "\\", "\\\\");
        line = replace(line, "\"", "\\\"");
        line = replace(line, "\t", "\\t");
        out << "\"" << line << "\\n\"\n";
    }
    out << ";";

    return 0;
}