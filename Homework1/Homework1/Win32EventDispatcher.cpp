#include "Win32EventDispatcher.h"
#include <windows.h>

namespace Engine
{
    LRESULT Win32EventDispatcher::dispatchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
            // ----------------------------------------------------------------------
            // Window Event
            // ----------------------------------------------------------------------

        case WM_MOVE:
            break;
        case WM_SIZE:
            break;

            // ----------------------------------------------------------------------
            // Mouse Event
            // ----------------------------------------------------------------------

        case WM_LBUTTONDOWN:
            break;
        case WM_LBUTTONUP:
            break;
        case WM_RBUTTONDOWN:
            break;
        case WM_RBUTTONUP:
            break;
        case WM_MBUTTONDOWN:
            break;
        case WM_MBUTTONUP:
            break;
        case WM_MOUSEMOVE:
            break;
        case WM_MOUSEWHEEL:
            break;
        case WM_MOUSEHOVER:
            break;
        case WM_MOUSELEAVE:
            break;

            // ----------------------------------------------------------------------
            // Keyboard Event
            // ----------------------------------------------------------------------

        case WM_KEYDOWN:
            break;
        case WM_KEYUP:
            break;
            break;
        }

        return 0;
    }
}
