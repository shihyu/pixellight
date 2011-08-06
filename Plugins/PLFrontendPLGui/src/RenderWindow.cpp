/*********************************************************\
 *  File: RenderWindow.cpp                               *
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


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLGui/Gui/Base/Keys.h>
#include <PLRenderer/Renderer/Surface.h>
#include "PLFrontendPLGui/RenderWindow.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;
using namespace PLMath;
using namespace PLGraphics;
using namespace PLGui;
using namespace PLRenderer;
namespace PLFrontendPLGui {


//[-------------------------------------------------------]
//[ RTTI interface                                        ]
//[-------------------------------------------------------]
pl_implement_class(RenderWindow)


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
RenderWindow::RenderWindow(Renderer &cRenderer, Widget *pParent, const DisplayMode *pDisplayMode, bool bFullscreen) : PLGui::Window(pParent), WindowConnection(cRenderer, *this, this),
	SlotOnTimer(this),
	m_cTimer(*GetGui()),
	m_bBackupAvailable(false)
{
	// There's no need to have a widget background because we're render into it
	GetContentWidget()->SetBackgroundColor(Color4::Transparent);

	// By default, it's allowed to switch windows into fullscreen mode
	SetToggleFullscreenMode(true);

	// By default, it's allowed to use Alt-Tab
	SetFullscreenAltTab(true);

	// Initialize the window connection
	Initialize(pDisplayMode, bFullscreen);

	// Set widget into fullscreen state?
	if (bFullscreen)
		SetWindowState(StateFullscreen);

	// Connect to timer
	m_cTimer.EventFire.Connect(SlotOnTimer);

	// Start timer - An interval of 10 milliseconds should be enough
	// [TODO] PLGui-timers: Currently, this timer will pollute the PLGui message system - the message processing will never stop because while processing the messages, the threaded PLGui timer fires again...
	// m_cTimer.Start(10);
}

/**
*  @brief
*    Destructor
*/
RenderWindow::~RenderWindow()
{
}


//[-------------------------------------------------------]
//[ Protected virtual PLGui::WidgetFunctions functions    ]
//[-------------------------------------------------------]
void RenderWindow::OnDraw(Graphics &cGraphics)
{
	// Call base implementation
	Window::OnDraw(cGraphics);

	// Get the renderer surface
	Surface *pSurface = GetSurface();
	if (pSurface) {
		// Update the renderer surface
		pSurface->Update();
	}
}


//[-------------------------------------------------------]
//[ Protected virtual WindowConnection functions          ]
//[-------------------------------------------------------]
void RenderWindow::OnDisplayMode()
{
	// Set the size of the window depending on the current set display mode
	SetSize(GetDisplayMode().vSize);

	// Call base implementation
	WindowConnection::OnDisplayMode();
}


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Copy constructor
*/
RenderWindow::RenderWindow(const RenderWindow &cSource) : PLGui::Window(cSource.GetParent()), WindowConnection(*cSource.GetRenderer(), *GetContentWidget()),
	SlotOnTimer(this),
	m_cTimer(*GetGui()),
	m_bBackupAvailable(false)
{
	// No implementation because the copy constructor is never used
}

/**
*  @brief
*    Copy operator
*/
RenderWindow &RenderWindow::operator =(const RenderWindow &cSource)
{
	// No implementation because the copy operator is never used
	return *this;
}

/**
*  @brief
*    Timer callback
*/
void RenderWindow::OnTimer()
{
	// Ask PLGui politly to update (and repaint) the widget
	Redraw();
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLFrontendPLGui