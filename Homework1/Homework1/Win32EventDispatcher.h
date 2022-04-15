#pragma once

#include "Singleton.h"

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
	};
}