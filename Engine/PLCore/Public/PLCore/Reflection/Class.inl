/*********************************************************\
 *  File: Rtti.h                                         *
 *
 *  Copyright (C) 2002-2013 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and associated documentation files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or
 *  substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
\*********************************************************/


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "ClassManager.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLRefl {

/**
*  @brief
*    Declare a new reflected class
*/
template <typename T>
ClassBuilder<T> Class::Declare(const PLCore::String &sName)
{
	// Destruction helper
	//struct Destructor
	//{
	//	template <typename T>
	//	static void Destruct(const UserObject &obj)
	//	{
	//		delete obj.GetAs<T*>();
	//	}
	//};

	// Register the class
	Class &clss = ClassManager::GetInstance()->RegisterClass(sName, StaticTypeId<T>::Get());
	//clss.Destructor = &Destructor::Destruct<T>;
	
	return ClassBuilder<T>(clss);
}

/**
*  @brief
*    Get the class name
*/
const PLCore::String &Class::GetName() const
{
	return m_sName;
}

/**
*  @brief
*    Get base classes
*/
const PLCore::Array<const Class*> &Class::GetBaseClasses() const
{
	return m_lstBases;
}

//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLRefl
