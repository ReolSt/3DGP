#pragma once

#include <windows.h>

#include "debug.h"
#include <string>
#include <vector>
#include <functional>

#include "Core/Event.h"
#include "Core/ObjectBase.h"
#include "Core/Types.h"

#define BindEventFunction(Method) std::bind(&Method, this, std::placeholders::_1)

namespace Engine
{
	enum class SystemEventType
	{
		None,
		WindowMove,
		WindowResize,
		MouseDown,
		MouseUp,
		MouseMove,
		MouseWheel,
		MouseHover,
		MouseLeave,
		KeyDown,
		KeyUp,
	};

	bool __isWindowEvent(SystemEventType eventType);
	bool __isKeyEvent(SystemEventType eventType);
	bool __isMouseEvent(SystemEventType eventType);

	std::string GetStringFromEventType(SystemEventType eventType);
	SystemEventType GetEventTypeFromString(const std::string& str);

	enum class KeyCode
	{
		None = 0x0,
		LeftMouseButton = VK_LBUTTON,
		RightMouseButton = VK_RBUTTON,
		MiddleMouseButton = VK_MBUTTON,
		ThumbMouseButton1 = VK_XBUTTON1,
		ThumbMouseButton2 = VK_XBUTTON2,
		BackSpace = VK_BACK,
		Tab = VK_TAB,
		Enter = VK_RETURN,
		Shift = VK_SHIFT,
		Control = VK_CONTROL,
		Alt = VK_MENU,
		PauseBreak = VK_PAUSE,
		CapsLock = VK_CAPITAL,
		Hangul = VK_HANGUL,
		Hanja = VK_HANJA,
		Escape = VK_ESCAPE,
		Space = VK_SPACE,
		PageUp = VK_PRIOR,
		PageDown = VK_NEXT,
		End = VK_END,
		Home = VK_HOME,
		Left = VK_LEFT,
		Right = VK_RIGHT,
		Up = VK_UP,
		Down = VK_DOWN,
		Print = VK_PRINT,
		PrintScreen = VK_SNAPSHOT,
		Insert = VK_INSERT,
		Delete = VK_DELETE,
		Zero = 0x30,
		One = 0x31,
		Two = 0x32,
		Three = 0x33,
		Four = 0x34,
		Five = 0x35,
		Six = 0x36,
		Seven = 0x37,
		Eight = 0x38,
		Nine = 0x39,
		A = 0x41,
		B = 0x42,
		C = 0x43,
		D = 0x44,
		E = 0x45,
		F = 0x46,
		G = 0x47,
		H = 0x48,
		I = 0x49,
		J = 0x4A,
		K = 0x4B,
		L = 0x4C,
		M = 0x4D,
		N = 0x4E,
		O = 0x4F,
		P = 0x50,
		Q = 0x51,
		R = 0x52,
		S = 0x53,
		T = 0x54,
		U = 0x55,
		V = 0x56,
		W = 0x57,
		X = 0x58,
		Y = 0x59,
		Z = 0x5A,
		LeftWin = VK_LWIN,
		RightWin = VK_RWIN,
		Sleep = VK_SLEEP,
		NumPad0 = VK_NUMPAD0,
		NumPad1 = VK_NUMPAD1,
		NumPad2 = VK_NUMPAD2,
		NumPad3 = VK_NUMPAD3,
		NumPad4 = VK_NUMPAD4,
		NumPad5 = VK_NUMPAD5,
		NumPad6 = VK_NUMPAD6,
		NumPad7 = VK_NUMPAD7,
		NumPad8 = VK_NUMPAD8,
		NumPad9 = VK_NUMPAD9,
		NumPadMultiply = VK_MULTIPLY,
		NumPadPlus = VK_ADD,
		NumPadMinus = VK_SUBTRACT,
		NumPadDecimal = VK_DECIMAL,
		NumPadDivide = VK_DIVIDE,
		F1 = VK_F1,
		F2 = VK_F2,
		F3 = VK_F3,
		F4 = VK_F4,
		F5 = VK_F5,
		F6 = VK_F6,
		F7 = VK_F7,
		F8 = VK_F8,
		F9 = VK_F9,
		F10 = VK_F10,
		F11 = VK_F11,
		F12 = VK_F12,
		F13 = VK_F13,
		F14 = VK_F14,
		F15 = VK_F15,
		F16 = VK_F16,
		F17 = VK_F17,
		F18 = VK_F18,
		F19 = VK_F19,
		F20 = VK_F20,
		F21 = VK_F21,
		F22 = VK_F22,
		F23 = VK_F23,
		F24 = VK_F24,
		NumLock = VK_NUMLOCK,
		ScrollLock = VK_SCROLL,
		LeftShift = VK_LSHIFT,
		RightShift = VK_RSHIFT,
		LeftControl = VK_LCONTROL,
		RightControl = VK_RCONTROL,
		LeftMenu = VK_LMENU,
		RightMenu = VK_RMENU,
		VolumeMute = VK_VOLUME_MUTE,
		VolumeDown = VK_VOLUME_DOWN,
		VolumeUp = VK_VOLUME_UP,
		SemiColon = VK_OEM_1,
		Plus = VK_OEM_PLUS,
		Comma = VK_OEM_COMMA,
		Minus = VK_OEM_MINUS,
		Period = VK_OEM_PERIOD,
		Slash = VK_OEM_2,
		BackQuote = VK_OEM_3,
		LeftBracket = VK_OEM_4,
		BackSlash = VK_OEM_5,
		RightBracket = VK_OEM_6,
		Quote = VK_OEM_7
	};

	std::string GetStringFromKeyCode(KeyCode keyCode);
	KeyCode GetKeyCodeFromString(const std::string& str);

	bool __isKeyCode(KeyCode button);
	bool __isMouseButtonCode(KeyCode button);

	class SystemEvent : public Event
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		SystemEvent() { setType(SystemEventType::None); }
		SystemEvent(SystemEventType type) { setType(type); }

		virtual ~SystemEvent() { }

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		SystemEventType getType() const { return m_type; }

		void setType(SystemEventType type) { m_type = type; }
	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		SystemEventType m_type;
	};

	class WindowEvent : public SystemEvent
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor Destructor
		// ----------------------------------------------------------------------

		WindowEvent(SystemEventType type, int x, int y, int width, int height);

		// ----------------------------------------------------------------------
		// Getter Setter
		// ----------------------------------------------------------------------

		int getX() const { return m_x; }
		int getY() const { return m_y; }
		int getWidth() const { return m_width; }
		int getHeight() const { return m_height; }

		void setX(int x) { m_x = x; }
		void setY(int y) { m_y = y; }
		void setWidth(int width) { m_width = width; }
		void setHeight(int height) { m_height = height; }

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		int m_x;
		int m_y;
		int m_width;
		int m_height;
	};

	class KeyEvent : public SystemEvent
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor Destructor
		// ----------------------------------------------------------------------

		KeyEvent(SystemEventType type, KeyCode keyCode);

		// ----------------------------------------------------------------------
		// Getter Setter
		// ----------------------------------------------------------------------

		KeyCode getKeyCode() const { return m_keyCode; }
		String getKeyCodeString() const { return GetStringFromKeyCode(m_keyCode); }

		void setKeyCode(KeyCode keyCode)
		{
			VERIFY(__isKeyCode(keyCode));

			m_keyCode = keyCode;
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		KeyCode m_keyCode;
	};

	class MouseEvent : public SystemEvent
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor Destructor
		// ----------------------------------------------------------------------

		MouseEvent(SystemEventType type, const Array<KeyCode>& buttons, int x, int y, int wheelDelta);

		// ----------------------------------------------------------------------
		// Getter Setter
		// ----------------------------------------------------------------------

		Array<KeyCode> getButtons() const { return m_buttons; }
		int getX() const { return m_x; }
		int getY() const { return m_y; }
		int getWheelDelta()  const { return m_wheelDelta; }

		void setButtons(const Array<KeyCode>& buttons)
		{
			for (KeyCode button : buttons)
			{
				VERIFY(__isMouseButtonCode(button));
			}
			
			m_buttons = buttons;
		}
		void setX(int x) { m_x = x; }
		void setY(int y) { m_y = y; }
		void setWheelDelta(int wheelDelta) { m_wheelDelta = wheelDelta; }

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Array<KeyCode> m_buttons;

		int m_x;
		int m_y;

		int m_wheelDelta;
	};

	using SystemEventFunction = std::function<void(SystemEvent*)>;

	class SystemEventCallback : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		SystemEventCallback() { }
		SystemEventCallback(const SystemEventFunction& func) { setFunction(func); }

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const SystemEventFunction& getFunction() const
		{
			return m_func;
		}

		void setFunction(const SystemEventFunction& func)
		{
			m_func = func;
		}

		// ----------------------------------------------------------------------
		// Operator
		// ----------------------------------------------------------------------

		void operator()(SystemEvent* evt)
		{
			m_func(evt);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		SystemEventFunction m_func;
	};

	using WindowEventFunction = std::function<void(WindowEvent*)>;

	class WindowEventCallback : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		WindowEventCallback() { }
		WindowEventCallback(const WindowEventFunction& func) { setFunction(func); }

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const WindowEventFunction& getFunction() const
		{
			return m_func;
		}

		void setFunction(const WindowEventFunction& func)
		{
			m_func = func;
		}

		// ----------------------------------------------------------------------
		// Operator
		// ----------------------------------------------------------------------

		void operator()(WindowEvent* evt)
		{
			m_func(evt);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		WindowEventFunction m_func;
	};

	using KeyEventFunction = std::function<void(KeyEvent*)>;

	class KeyEventCallback : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		KeyEventCallback() { }
		KeyEventCallback(const KeyEventFunction& func) { setFunction(func); }

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const KeyEventFunction& getFunction() const
		{
			return m_func;
		}

		void setFunction(const KeyEventFunction& func)
		{
			m_func = func;
		}

		// ----------------------------------------------------------------------
		// Operator
		// ----------------------------------------------------------------------

		void operator()(KeyEvent* evt)
		{
			m_func(evt);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		KeyEventFunction m_func;
	};

	using MouseEventFunction = std::function<void(MouseEvent*)>;

	class MouseEventCallback : public ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------
		MouseEventCallback() { }
		MouseEventCallback(const MouseEventFunction& func) { setFunction(func); }

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		const MouseEventFunction& getFunction() const
		{
			return m_func;
		}

		void setFunction(const MouseEventFunction& func)
		{
			m_func = func;
		}

		// ----------------------------------------------------------------------
		// Operator
		// ----------------------------------------------------------------------

		void operator()(MouseEvent* evt)
		{
			m_func(evt);
		}

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		MouseEventFunction m_func;
	};
}