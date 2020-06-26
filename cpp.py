# ===========================================================================
# Copyright (C) 2020 Aggi

# This file is part of cppioq3 source code.

# cppioq3 source code is free software; you can redistribute it
# and/or modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of the License,
# or (at your option) any later version.

# cppioq3 source code is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with cppioq3 source code; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
# ===========================================================================


import os
import shutil

cppioq3 = os.path.dirname(os.path.realpath(__file__))
c_path = os.path.join(cppioq3, 'code')
cpp_path = os.path.join(cppioq3, 'code-cpp')

# code/files must contain absolute paths of all used files
files = []
with open(os.path.join(c_path, 'files')) as f:
    for line in f.readlines():
        line = line.strip()
        if not os.path.exists(line):
            continue
        
        name, ext = os.path.splitext(line)
        if ext == '.c':
            header = name + '.h'
            if not os.path.exists(header):
                files.append(header)

        files.append(line)



for in_path in files:
    out_path = in_path.replace(c_path, cpp_path)

    out_path, ext = os.path.splitext(out_path)

    if ext == '.c':
        out_path += '.cpp'
    elif ext == '.h':
        out_path += '.hpp'
    else:
        out_path += ext

    if os.path.exists(in_path) and not os.path.exists(out_path):
        os.makedirs(os.path.dirname(out_path), exist_ok=True)
        shutil.copyfile(in_path, out_path)
