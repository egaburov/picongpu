#!/bin/bash
# Copyright 2013 Axel Huebl, Rene Widera
# 
# This file is part of PIConGPU. 
# 
# PIConGPU is free software: you can redistribute it and/or modify 
# it under the terms of the GNU General Public License as published by 
# the Free Software Foundation, either version 3 of the License, or 
# (at your option) any later version. 
# 
# PIConGPU is distributed in the hope that it will be useful, 
# but WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
# GNU General Public License for more details. 
# 
# You should have received a copy of the GNU General Public License 
# along with PIConGPU.  
# If not, see <http://www.gnu.org/licenses/>. 
# 

## copy memcheck programs
cd $TBG_dstPath
mkdir picongpu
cp -r $TBG_projectPath/bin picongpu
cp -r $TBG_projectPath/include picongpu
cp -r $TBG_projectPath/submit picongpu
cp -a $TBG_cfgPath/openib.conf tbg
cp $TBG_cfgPath/cuda.filter tbg
cp $0 tbg

