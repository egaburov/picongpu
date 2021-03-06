/**
 * Copyright 2013 Heiko Burau, Rene Widera, Richard Pausch
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

#include "types.h"
#include "simulation_defines.hpp"

namespace picongpu
{
/** not focusing polynomial laser pulse
 * 
 *  no phase shifts, just spacial envelope
 */
namespace laserPolynom
{

HDINLINE float_64 Tpolynomial(const float_64 tau);

/** Compute the longitudinal enevelope of the laser
 * 
 */
HINLINE float3_X laserLongitudinal(uint32_t currentStep, float_X& phase)
{
    const float_64 runTime = DELTA_T*currentStep;
    const float_64 f = SPEED_OF_LIGHT / WAVE_LENGTH;

    float3_X elong(0.0f, 0.0f, 0.0f);

    // a symmetric pulse will be initialized at position z=0 
    // the laser amplitude rises  for T_rise
    // and falls for T_rise
    // making the laser pulse 2*T_rise long

    const float_64 T_rise = 0.5 * PULSE_LENGTH;
    const float_64 tau = runTime / T_rise;

    const float_64 omegaLaser = 2.0 * PI * f;

    elong.x() = float_X(
                       float_64(AMPLITUDE) *
                       Tpolynomial(tau)
                       * math::sin(omegaLaser * (runTime - T_rise))
                       );

    phase = 0.0f;

    return elong;
}

/**
 * 
 * @param elong E-field without transversal envelope 
 * @param phase phase of the laser field
 * @param posX location in x (transversal)
 * @param posZ location in y (transversal)
 * @return E-field value
 */
HDINLINE float3_X laserTransversal(float3_X elong, const float_X, const float_X posX, const float_X posZ)
{
    const float_64 exponent = (posX / W0x)*(posX / W0x) + (posZ / W0z)*(posZ / W0z);

    return elong * precisionCast<float_X > (math::exp(-exponent));

}

HDINLINE float_64 Tpolynomial(const float_64 tau)
{
    if (tau >= 0.0 && tau <= 1.0)
        return tau * tau * tau * (10.0 - 15.0 * tau + 6.0 * tau * tau);
    else if (tau > 1.0 && tau <= 2.0)
        return (2.0 - tau) * (2.0 - tau) * (2.0 - tau) * (4.0 - 9.0 * tau + 6.0 * tau * tau);
    else
        return 0.0;
}


} /* end: namespace laserPolynom */
} /* end: namespace picongpu */





