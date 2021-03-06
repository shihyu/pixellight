/*********************************************************\
 *  File: Application.h                                  *
\*********************************************************/


#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
[!if CORE_APPLICATION]
#include <PLCore/Application/Application.h>
[!endif]
[!if GUI_APPLICATION]
#include <PLGui/Application/GuiApplication.h>
[!endif]
[!if RENDERER_APPLICATION]
#include <PLRenderer/Application/RendererApplication.h>
[!endif]
[!if SCENE_APPLICATION]
#include <PLScene/Application/SceneApplication.h>
[!endif]
[!if BASIC_SCENE_APPLICATION]
#include <PLEngine/Application/EngineApplication.h>
[!endif]
[!if SAMPLE_SCENE_APPLICATION]
#include <PLEngine/Application/SampleSceneApplication.h>
[!endif]


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Application class
*/
[!if CORE_APPLICATION]
class Application : public PLCore::Application {
[!endif]
[!if GUI_APPLICATION]
class Application : public PLGui::GuiApplication {
[!endif]
[!if RENDERER_APPLICATION]
class Application : public PLRenderer::RendererApplication {
[!endif]
[!if SCENE_APPLICATION]
class Application : public PLScene::SceneApplication {
[!endif]
[!if BASIC_SCENE_APPLICATION]
class Application : public PLEngine::EngineApplication {
[!endif]
[!if SAMPLE_SCENE_APPLICATION]
class Application : public PLEngine::SampleSceneApplication {
[!endif]


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


};


#endif // __APPLICATION_H__
