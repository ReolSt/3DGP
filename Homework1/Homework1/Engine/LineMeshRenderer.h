#pragma once

#include "Renderer.h"
#include "Math.h"
#include "LineMesh.h"

#include <windows.h>

namespace Engine
{
	class LineMeshRenderer : public Renderer
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		LineMeshRenderer();
		~LineMeshRenderer();

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void initialize(HINSTANCE instance, HWND window);
		void render(Engine* engine) override;

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		HINSTANCE m_instance;
		HWND m_window;

		HDC m_dc;
		HBITMAP m_frameBuffer;

		RECT m_rcClient;
	};
}


