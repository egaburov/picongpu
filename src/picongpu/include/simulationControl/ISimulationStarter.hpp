/**
 * Copyright 2013 Rene Widera
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
 


#ifndef ISIMULATIONSTARTER_HPP
#define	ISIMULATIONSTARTER_HPP

#include "types.h"
#include "simulation_defines.hpp"


#include "moduleSystem/Module.hpp"

namespace picongpu
{
    using namespace PMacc;

    
    class ISimulationStarter : public Module
    {
    public:

        virtual ~ISimulationStarter()
        {
        }
        /**Pars progarm parameters
         *             * 
         * @param argc number of arguments in argv
         * @param argv arguments for programm
         * 
         * @return true if no error else false
         */
        virtual bool parseConfigs(int argc, char **argv) = 0;

        /*start simulation
         * is called after parsConfig and moduleLoad
         */
        virtual void start() = 0;
    };
}

#endif	/* ISIMULATIONSTARTER_HPP */

