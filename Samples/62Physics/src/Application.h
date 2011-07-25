/*********************************************************\
 *  File: Application.h                                  *
 *
 *  Copyright (C) 2002-2011 The PixelLight Team (http://www.pixellight.org/)
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


#ifndef __PLSAMPLE_62_APPLICATION_H__
#define __PLSAMPLE_62_APPLICATION_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLEngine/Application/BasicSceneApplication.h>


//[-------------------------------------------------------]
//[ Forward declarations                                  ]
//[-------------------------------------------------------]
namespace PLPhysics {
	class Body;
	class ContactInformation;
}


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Application class
*/
class Application : public PLEngine::BasicSceneApplication {


	//[-------------------------------------------------------]
	//[ RTTI interface                                        ]
	//[-------------------------------------------------------]
	pl_class(pl_rtti_export, Application, "", PLEngine::BasicSceneApplication, "Application class")
		// Constructors
		pl_constructor_0(DefaultConstructor,	"Default constructor",	"")
		// Slots
		pl_slot_2(OnKeyDown,	PLCore::uint32,					PLCore::uint32,	"Called when a key is pressed down. pressed key as first parameter and modifier keys pressed as second parameter",	"")
		pl_slot_2(OnKeyUp,		PLCore::uint32,					PLCore::uint32,	"Called when a key is released. pressed key as first parameter and modifier keys pressed as second parameter",		"")
		pl_slot_1(OnContact,	PLPhysics::ContactInformation&,					"Called when a contact between two bodies was detected by the physics, contact information as first parameter",		"")
	pl_class_end


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*/
		Application();

		/**
		*  @brief
		*    Destructor
		*/
		virtual ~Application();

		/**
		*  @brief
		*    Returns the name of the used physics API
		*
		*  @return
		*    Name of the used physics API
		*/
		PLCore::String GetPhysicsAPI() const;


	//[-------------------------------------------------------]
	//[ Private functions                                     ]
	//[-------------------------------------------------------]
	private:
		/**
		*  @brief
		*    Updates the text of the mass text node
		*/
		void UpdateMassTextNode();

		/**
		*  @brief
		*    Function where the user has to choose the desired physics API
		*
		*  @return
		*    'true' if all went fine and the user has chosen a physics API, else 'false'
		*
		*  @note
		*    - If only one physics API is available no dialog will appear
		*/
		bool ChoosePhysicsAPI();

		/**
		*  @brief
		*    Returns the PL physics body of the given scene node
		*
		*  @param[in] cSceneNode
		*    Scene node the PL physics body should returned from
		*
		*  @return
		*    The PL physics body of the given scene node, a null pointer if there's no such body
		*/
		PLPhysics::Body *GetPhysicsBody(PLScene::SceneNode &cSceneNode) const;

		/**
		*  @brief
		*    Called when a key is pressed down
		*
		*  @param[in] nKey
		*    Pressed key
		*  @param[in] nModifiers
		*    Modifier keys pressed
		*/
		void OnKeyDown(PLCore::uint32 nKey, PLCore::uint32 nModifiers);

		/**
		*  @brief
		*    Called when a key is released
		*
		*  @param[in] nKey
		*    Pressed key
		*  @param[in] nModifiers
		*    Modifier keys pressed
		*/
		void OnKeyUp(PLCore::uint32 nKey, PLCore::uint32 nModifiers);

		/**
		*  @brief
		*    Called when a contact between two bodies was detected by the physics
		*
		*  @param[in] cContactInformation
		*    Contact information
		*/
		void OnContact(PLPhysics::ContactInformation &cContactInformation);


	//[-------------------------------------------------------]
	//[ Private virtual PLGui::GuiApplication functions       ]
	//[-------------------------------------------------------]
	private:
		virtual void OnInit();
		virtual void OnCreateMainWindow();


	//[-------------------------------------------------------]
	//[ Private virtual PLRenderer::RenderApplication functions ]
	//[-------------------------------------------------------]
	private:
		virtual bool OnUpdate();


	//[-------------------------------------------------------]
	//[ Private virtual PLEngine::BasicSceneApplication functions ]
	//[-------------------------------------------------------]
	private:
		virtual void OnCreateScene(PLScene::SceneContainer &cContainer);


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		PLCore::String	 	 m_sPhysicsAPI;		/**< Name of the used physics API */
		PLScene::SceneNode	*m_pLine;			/**< Pointer to the line scene node, can be a null pointer */
		PLScene::SceneNode	*m_pFallingBox;		/**< Pointer to the falling box scene node, can be a null pointer */
		bool				 m_bApplyForce;		/**< Apply force to the falling box scene node? */
		bool				 m_bTorqueForce;	/**< Apply torque to the falling box scene node? */


};


#endif // __PLSAMPLE_62_APPLICATION_H__