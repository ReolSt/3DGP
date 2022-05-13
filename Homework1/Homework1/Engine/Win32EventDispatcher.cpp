#include "Win32EventDispatcher.h"
#include "SystemEvent.h"
#include "Engine.h"
#include "Alias.h"

#include <windows.h>
#include <vector>

namespace Engine
{
    Map<KeyCode, bool> Win32EventDispatcher::m_keyPressed;

    LRESULT Win32EventDispatcher::dispatchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        auto engine = Engine::getInstance();

        // ----------------------------------------------------------------------
        // Window Event
        // ----------------------------------------------------------------------

        if (message == WM_MOVE)
        {
            int x = (short)LOWORD(lParam);
            int y = (short)HIWORD(lParam);

            WindowEvent evt(SystemEventType::WindowMove, x, y, 0, 0);

            engine->dispatchEvent(&evt);
        }
        else if (message == WM_SIZE)
        {
            int width = (short)LOWORD(lParam);
            int height = (short)HIWORD(lParam);

            WindowEvent evt(SystemEventType::WindowResize, 0, 0, width, height);

            engine->dispatchEvent(&evt);
        }


        // ----------------------------------------------------------------------
        // Mouse Event 
        // ----------------------------------------------------------------------

        else if (message == WM_LBUTTONDOWN ||
            message == WM_RBUTTONDOWN ||
            message == WM_MBUTTONDOWN ||
            message == WM_XBUTTONDOWN ||
            message == WM_LBUTTONUP ||
            message == WM_RBUTTONUP ||
            message == WM_MBUTTONUP ||
            message == WM_XBUTTONUP ||
            message == WM_MOUSEWHEEL ||
            message == WM_MOUSEMOVE ||
            message == WM_MOUSEHOVER ||
            message == WM_MOUSELEAVE)
        {
            int x = (short)LOWORD(lParam);
            int y = (short)HIWORD(lParam);

            Array<KeyCode> buttons;
            if (wParam & MK_LBUTTON) buttons.push_back(KeyCode::LeftMouseButton);
            if (wParam & MK_RBUTTON) buttons.push_back(KeyCode::RightMouseButton);
            if (wParam & MK_MBUTTON) buttons.push_back(KeyCode::MiddleMouseButton);
            if (wParam & MK_XBUTTON1) buttons.push_back(KeyCode::ThumbMouseButton1);
            if (wParam & MK_XBUTTON2) buttons.push_back(KeyCode::ThumbMouseButton2);
            if (wParam == 0x0) buttons.push_back(KeyCode::None);

            SystemEventType eventType = SystemEventType::None;
            switch (message)
            {
			case WM_LBUTTONDOWN:
            case WM_RBUTTONDOWN:
            case WM_MBUTTONDOWN:
            case WM_XBUTTONDOWN:
                eventType = SystemEventType::MouseDown;
                break;
            case WM_LBUTTONUP:
            case WM_RBUTTONUP:
            case WM_MBUTTONUP:
            case WM_XBUTTONUP:
                eventType = SystemEventType::MouseUp;
                break;
            case WM_MOUSEMOVE:
                eventType = SystemEventType::MouseMove;
                break;
            case WM_MOUSEWHEEL:
                eventType = SystemEventType::MouseWheel;
                break;
            case WM_MOUSEHOVER:
                eventType = SystemEventType::MouseHover;
                break;
            case WM_MOUSELEAVE:
                eventType = SystemEventType::MouseLeave;
                break;
            }
            
            int wheelDelta = (short)HIWORD(wParam);

            MouseEvent evt(eventType, buttons, x, y, wheelDelta);
            
            engine->dispatchEvent(&evt);
        }

        // ----------------------------------------------------------------------
        // Keyboard Event
        // ----------------------------------------------------------------------

        else if (message == WM_KEYDOWN)
        {
            KeyCode keyCode = (KeyCode)wParam;
            KeyEvent evt(SystemEventType::KeyDown, keyCode);

            if (m_keyPressed.find(keyCode) == m_keyPressed.end())
            {
                m_keyPressed[keyCode] = true;
            }
            else if(m_keyPressed[keyCode] == true)
            {
                return 0;
            }

            m_keyPressed[keyCode] = true;

            engine->dispatchEvent(&evt);
        }    
        else if(message == WM_KEYUP)
        {
            KeyCode keyCode = (KeyCode)wParam;
            KeyEvent evt(SystemEventType::KeyUp, keyCode);

            Win32EventDispatcher::m_keyPressed[keyCode] = false;

            engine->dispatchEvent(&evt);
        }

        return 0;
    }
}
