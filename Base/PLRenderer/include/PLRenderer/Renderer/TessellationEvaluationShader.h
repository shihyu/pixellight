/*********************************************************\
 *  File: TessellationEvaluationShader.h                 *
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


#ifndef __PLRENDERER_TESSELATIONEVALUATIONSHADER_H__
#define __PLRENDERER_TESSELATIONEVALUATIONSHADER_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLRenderer/Renderer/Shader.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLRenderer {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Abstract renderer tessellation evaluation shader (named "domain shader" in DirectX) shader resource
*/
class TessellationEvaluationShader : public Shader {


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Destructor
		*/
		PLRENDERER_API virtual ~TessellationEvaluationShader();


	//[-------------------------------------------------------]
	//[ Protected functions                                   ]
	//[-------------------------------------------------------]
	protected:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] cRenderer
		*    Owner renderer
		*/
		PLRENDERER_API TessellationEvaluationShader(Renderer &cRenderer);


	//[-------------------------------------------------------]
	//[ Private functions                                     ]
	//[-------------------------------------------------------]
	private:
		/**
		*  @brief
		*    Copy constructor
		*
		*  @param[in] cSource
		*    Source to copy from
		*/
		TessellationEvaluationShader(const TessellationEvaluationShader &cSource);

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
		TessellationEvaluationShader &operator =(const TessellationEvaluationShader &cSource);


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLRenderer


#endif // __PLRENDERER_TESSELATIONEVALUATIONSHADER_H__