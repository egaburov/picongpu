/**
 * Copyright 2013 Axel Huebl
 *
 * This file is part of PIConGPU. 
 * 
 * PIConGPU is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version. 
 * 
 * PIConGPU is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * along with PIConGPU.  
 * If not, see <http://www.gnu.org/licenses/>. 
 */ 

#pragma once

#include "mappings/simulation/GridController.hpp"
#include "mappings/simulation/SubGrid.hpp"
#include "cuSTL/container/HostBuffer.hpp"
#include "math/vector/Int.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <utility>

#include <splash.h>

namespace picongpu
{
    template<typename Type, uint32_t bufDim>
    void DumpHBuffer::operator()( const PMacc::container::HostBuffer<Type, bufDim>& hBuffer,
                                  const std::pair<uint32_t, uint32_t> axis_element,
                                  const double unit,
                                  const uint32_t currentStep ) const
    {
        std::cout << "NOT implemented: "
                  << "Dump SPLASH Parallel" << std::endl;
    }

} // namespace picongpu
