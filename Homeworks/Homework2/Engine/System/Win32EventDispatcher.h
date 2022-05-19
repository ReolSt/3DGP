#pragma once

#include "Core/Singleton.h"
#include "Core/Types.h"
#include "System/SystemEvent.h"

#include <windows.h>

namespace Engine
{
	class Win32EventDispatcher : public Singleton<Win32EventDispatcher>
	{
	public:
		// ----------------------------------------------------------------------
		// Public Static Method
		// ----------------------------------------------------------------------

		static LRESULT dispatchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		
	private:
		// ----------------------------------------------------------------------
		// Private Static Variable
		// ----------------------------------------------------------------------

		static Map<KeyCode, bool> m_keyPressed;
	};
}