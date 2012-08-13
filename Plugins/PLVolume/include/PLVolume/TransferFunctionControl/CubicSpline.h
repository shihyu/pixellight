/*********************************************************\
 *  File: CubicSpline.h                                  *
 *
 *  Copyright (C) 2002-2012 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  PixelLight is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PixelLight is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with PixelLight. If not, see <http://www.gnu.org/licenses/>.
\*********************************************************/


#ifndef __PLVOLUME_CUBICSPLINE_H__
#define __PLVOLUME_CUBICSPLINE_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLCore/Container/Array.h>
#include "PLVolume/PLVolume.h"
#include "PLVolume/TransferFunctionControl/TransferControlPoint.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLVolume {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Cubic spline
*
// [TODO] Comment/Cleanup
/// Cubic class that calculates the cubic spline from a set of control points/knots
/// and performs cubic interpolation.
*
*  @note
*    - Based on the natural cubic spline code from http://www.cse.unsw.edu.au/~lambert/splines/natcubic.html
*/
class CubicSpline {


	//[-------------------------------------------------------]
	//[ Public static functions                               ]
	//[-------------------------------------------------------]
	public:
		// [TODO] Comment/Cleanup
		static PLVOLUME_API void CalculateCubicSpline(PLCore::uint32 n, PLCore::Array<TransferControlPoint> &v, PLCore::Array<CubicSpline> &cubic);


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Default constructor
		*/
		inline CubicSpline();

		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] a
		*    First coefficient
		*  @param[in] b
		*    Second coefficient
		*  @param[in] c
		*    Third coefficient
		*  @param[in] d
		*    Fourth coefficient
		*/
		inline CubicSpline(float a, float b, float c, float d);

		/**
		*  @brief
		*    Copy constructor
		*
		*  @param[in] cSource
		*    Source to copy from
		*/
		inline CubicSpline(const CubicSpline &cSource);

		/**
		*  @brief
		*    Destructor
		*/
		inline ~CubicSpline();

		/**
		*  @brief
		*    Copy operator
		*
		*  @param[in] cSource
		*    Source to copy from
		*
		*  @return
		*    Reference to this instance
		*/
		inline CubicSpline &operator =(const CubicSpline &cSource);

		/**
		*  @brief
		*    Comparison operator
		*
		*  @param[in] cOther
		*    Other instance to compare with
		*
		*  @return
		*    'true' if equal, else 'false'
		*/
		inline bool operator ==(const CubicSpline &cOther) const;

		/**
		*  @brief
		*    Evaluate value using a cubic equation
		*
		*  @param[in] fValue
		*    Value to evaluate (e.g. along x-axis)
		*
		*  @return
		*    Resulting value (e.g. along y-axis)
		*/
		inline float GetValueOnSpline(float fValue) const;


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		float a, b, c, d;	/**< Coefficients: a + b*s + c*s^2 +d*s^3 */


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLVolume


//[-------------------------------------------------------]
//[ Implementation                                        ]
//[-------------------------------------------------------]
#include "PLVolume/TransferFunctionControl/CubicSpline.inl"


#endif // __PLVOLUME_CUBICSPLINE_H__