#include "SystemEvent.h"

#include <cassert>
#include <string>
#include <unordered_map>

#include "Alias.h"

namespace Engine
{
	bool __isWindowEvent(SystemEventType eventType)
	{
		return eventType == SystemEventType::WindowMove ||
			eventType == SystemEventType::WindowResize;
	}

	bool __isKeyEvent(SystemEventType eventType)
	{
		return eventType == SystemEventType::KeyDown ||
			eventType == SystemEventType::KeyUp;
	}

	bool __isMouseEvent(SystemEventType eventType)
	{
		return eventType == SystemEventType::MouseDown ||
			eventType == SystemEventType::MouseUp ||
			eventType == SystemEventType::MouseWheel ||
			eventType == SystemEventType::MouseMove ||
			eventType == SystemEventType::MouseHover ||
			eventType == SystemEventType::MouseLeave;
	}

	std::string GetStringFromEventType(SystemEventType eventType)
	{
		static std::unordered_map<SystemEventType, std::string> eventTypeToString;

		if (eventTypeToString.size() == 0)
		{
			eventTypeToString[SystemEventType::None] = "None";
			eventTypeToString[SystemEventType::WindowMove] = "WindowMove";
			eventTypeToString[SystemEventType::WindowResize] = "WindowResize";
			eventTypeToString[SystemEventType::MouseDown] = "MouseDown";
			eventTypeToString[SystemEventType::MouseUp] = "MouseUp";
			eventTypeToString[SystemEventType::MouseMove] = "MouseMove";
			eventTypeToString[SystemEventType::MouseWheel] = "MouseWheel";
			eventTypeToString[SystemEventType::MouseHover] = "MouseHover";
			eventTypeToString[SystemEventType::MouseLeave] = "MouseLeave";
			eventTypeToString[SystemEventType::KeyDown] = "KeyDown";
			eventTypeToString[SystemEventType::KeyUp] = "KeyUp";
		}

		return eventTypeToString[eventType];
	}

	SystemEventType GetEventTypeFromString(const std::string& str)
	{
		static std::unordered_map<std::string, SystemEventType> stringToEventType;

		if (stringToEventType.size() == 0)
		{
			stringToEventType["None"] = SystemEventType::None;
			stringToEventType["Move"] = SystemEventType::WindowMove;
			stringToEventType["Resize"] = SystemEventType::WindowResize;
			stringToEventType["MouseDown"] = SystemEventType::MouseDown;
			stringToEventType["MouseUp"] = SystemEventType::MouseUp;
			stringToEventType["MouseMove"] = SystemEventType::MouseMove;
			stringToEventType["MouseWheel"] = SystemEventType::MouseWheel;
			stringToEventType["MouseHover"] = SystemEventType::MouseHover;
			stringToEventType["MouseLeave"] = SystemEventType::MouseLeave;
			stringToEventType["KeyDown"] = SystemEventType::KeyDown;
			stringToEventType["KeyUp"] = SystemEventType::KeyUp;
		}

		return stringToEventType[str];
	}

	std::string GetStringFromKeyCode(KeyCode keyCode)
	{
		static std::unordered_map<KeyCode, std::string> keyCodeToString;

		if (keyCodeToString.size() == 0)
		{
			keyCodeToString[KeyCode::None] = "None";
			keyCodeToString[KeyCode::LeftMouseButton] = "LeftMouseButton";
			keyCodeToString[KeyCode::RightMouseButton] = "RightMouseButton";
			keyCodeToString[KeyCode::MiddleMouseButton] = "MiddleMouseButton";
			keyCodeToString[KeyCode::ThumbMouseButton1] = "ThumbMouseButton1";
			keyCodeToString[KeyCode::ThumbMouseButton2] = "ThumbMouseButton2";
			keyCodeToString[KeyCode::BackSpace] = "BackSpace";
			keyCodeToString[KeyCode::Tab] = "Tab";
			keyCodeToString[KeyCode::Enter] = "Enter";
			keyCodeToString[KeyCode::Shift] = "Shift";
			keyCodeToString[KeyCode::Control] = "Control";
			keyCodeToString[KeyCode::Alt] = "Alt";
			keyCodeToString[KeyCode::PauseBreak] = "PauseBreak";
			keyCodeToString[KeyCode::CapsLock] = "CapsLock";
			keyCodeToString[KeyCode::Hangul] = "Hangul";
			keyCodeToString[KeyCode::Escape] = "Escape";
			keyCodeToString[KeyCode::Space] = "Space";
			keyCodeToString[KeyCode::PageUp] = "PageUp";
			keyCodeToString[KeyCode::PageDown] = "PageDown";
			keyCodeToString[KeyCode::End] = "End";
			keyCodeToString[KeyCode::Home] = "Home";
			keyCodeToString[KeyCode::Left] = "Left";
			keyCodeToString[KeyCode::Right] = "Right";
			keyCodeToString[KeyCode::Up] = "Up";
			keyCodeToString[KeyCode::Down] = "Down";
			keyCodeToString[KeyCode::Print] = "Print";
			keyCodeToString[KeyCode::PrintScreen] = "PrintScreen";
			keyCodeToString[KeyCode::Insert] = "Insert";
			keyCodeToString[KeyCode::Delete] = "Delete";
			keyCodeToString[KeyCode::Zero] = "Zero";
			keyCodeToString[KeyCode::One] = "One";
			keyCodeToString[KeyCode::Two] = "Two";
			keyCodeToString[KeyCode::Three] = "Three";
			keyCodeToString[KeyCode::Four] = "Four";
			keyCodeToString[KeyCode::Five] = "Five";
			keyCodeToString[KeyCode::Six] = "Six";
			keyCodeToString[KeyCode::Seven] = "Seven";
			keyCodeToString[KeyCode::Eight] = "Eight";
			keyCodeToString[KeyCode::Nine] = "Nine";
			keyCodeToString[KeyCode::A] = "A";
			keyCodeToString[KeyCode::B] = "B";
			keyCodeToString[KeyCode::C] = "C";
			keyCodeToString[KeyCode::D] = "D";
			keyCodeToString[KeyCode::E] = "E";
			keyCodeToString[KeyCode::F] = "F";
			keyCodeToString[KeyCode::G] = "G";
			keyCodeToString[KeyCode::H] = "H";
			keyCodeToString[KeyCode::I] = "I";
			keyCodeToString[KeyCode::J] = "J";
			keyCodeToString[KeyCode::K] = "K";
			keyCodeToString[KeyCode::L] = "L";
			keyCodeToString[KeyCode::M] = "M";
			keyCodeToString[KeyCode::N] = "N";
			keyCodeToString[KeyCode::O] = "O";
			keyCodeToString[KeyCode::P] = "P";
			keyCodeToString[KeyCode::Q] = "Q";
			keyCodeToString[KeyCode::R] = "R";
			keyCodeToString[KeyCode::S] = "S";
			keyCodeToString[KeyCode::T] = "T";
			keyCodeToString[KeyCode::U] = "U";
			keyCodeToString[KeyCode::V] = "V";
			keyCodeToString[KeyCode::W] = "W";
			keyCodeToString[KeyCode::X] = "X";
			keyCodeToString[KeyCode::Y] = "Y";
			keyCodeToString[KeyCode::Z] = "Z";
			keyCodeToString[KeyCode::LeftWin] = "LeftWin";
			keyCodeToString[KeyCode::RightWin] = "RightWin";
			keyCodeToString[KeyCode::Sleep] = "Sleep";
			keyCodeToString[KeyCode::NumPad0] = "NumPad0";
			keyCodeToString[KeyCode::NumPad1] = "NumPad1";
			keyCodeToString[KeyCode::NumPad2] = "NumPad2";
			keyCodeToString[KeyCode::NumPad3] = "NumPad3";
			keyCodeToString[KeyCode::NumPad4] = "NumPad4";
			keyCodeToString[KeyCode::NumPad5] = "NumPad5";
			keyCodeToString[KeyCode::NumPad6] = "NumPad6";
			keyCodeToString[KeyCode::NumPad7] = "NumPad7";
			keyCodeToString[KeyCode::NumPad8] = "NumPad8";
			keyCodeToString[KeyCode::NumPad9] = "NumPad9";
			keyCodeToString[KeyCode::NumPadMultiply] = "NumPadMultiply";
			keyCodeToString[KeyCode::NumPadPlus] = "NumPadPlus";
			keyCodeToString[KeyCode::NumPadMinus] = "NumPadMinus";
			keyCodeToString[KeyCode::NumPadDecimal] = "NumPadDecimal";
			keyCodeToString[KeyCode::NumPadDivide] = "NumPadDivide";
			keyCodeToString[KeyCode::F1] = "F1";
			keyCodeToString[KeyCode::F2] = "F2";
			keyCodeToString[KeyCode::F3] = "F3";
			keyCodeToString[KeyCode::F4] = "F4";
			keyCodeToString[KeyCode::F5] = "F5";
			keyCodeToString[KeyCode::F6] = "F6";
			keyCodeToString[KeyCode::F7] = "F7";
			keyCodeToString[KeyCode::F8] = "F8";
			keyCodeToString[KeyCode::F9] = "F9";
			keyCodeToString[KeyCode::F10] = "F10";
			keyCodeToString[KeyCode::F11] = "F11";
			keyCodeToString[KeyCode::F12] = "F12";
			keyCodeToString[KeyCode::F13] = "F13";
			keyCodeToString[KeyCode::F14] = "F14";
			keyCodeToString[KeyCode::F15] = "F15";
			keyCodeToString[KeyCode::F16] = "F16";
			keyCodeToString[KeyCode::F17] = "F17";
			keyCodeToString[KeyCode::F18] = "F18";
			keyCodeToString[KeyCode::F19] = "F19";
			keyCodeToString[KeyCode::F20] = "F20";
			keyCodeToString[KeyCode::F21] = "F21";
			keyCodeToString[KeyCode::F22] = "F22";
			keyCodeToString[KeyCode::F23] = "F23";
			keyCodeToString[KeyCode::F24] = "F24";
			keyCodeToString[KeyCode::NumLock] = "NumLock";
			keyCodeToString[KeyCode::ScrollLock] = "ScrollLock";
			keyCodeToString[KeyCode::LeftShift] = "LeftShift";
			keyCodeToString[KeyCode::RightShift] = "RightShift";
			keyCodeToString[KeyCode::LeftControl] = "LeftControl";
			keyCodeToString[KeyCode::RightControl] = "RightControl";
			keyCodeToString[KeyCode::LeftMenu] = "LeftMenu";
			keyCodeToString[KeyCode::RightMenu] = "RightMenu";
			keyCodeToString[KeyCode::VolumeMute] = "VolumeMute";
			keyCodeToString[KeyCode::VolumeDown] = "VolumeDown";
			keyCodeToString[KeyCode::VolumeUp] = "VolumeUp";
			keyCodeToString[KeyCode::SemiColon] = "SemiColon";
			keyCodeToString[KeyCode::Plus] = "Plus";
			keyCodeToString[KeyCode::Comma] = "Comma";
			keyCodeToString[KeyCode::Minus] = "Minus";
			keyCodeToString[KeyCode::Period] = "Period";
			keyCodeToString[KeyCode::Slash] = "Slash";
			keyCodeToString[KeyCode::BackQuote] = "BackQuote";
			keyCodeToString[KeyCode::LeftBracket] = "LeftBracket";
			keyCodeToString[KeyCode::BackSlash] = "BackSlash";
			keyCodeToString[KeyCode::RightBracket] = "RightBracket";
			keyCodeToString[KeyCode::Quote] = "Quote";
		}

		return keyCodeToString[keyCode];
	}

	KeyCode GetKeyCodeFromString(const std::string& str)
	{
		static std::unordered_map<std::string, KeyCode> stringToKeyCode;

		if (stringToKeyCode.size() == 0)
		{
			stringToKeyCode["None"] = KeyCode::None;
			stringToKeyCode["LeftMouseButton"] = KeyCode::LeftMouseButton;
			stringToKeyCode["RightMouseButton"] = KeyCode::RightMouseButton;
			stringToKeyCode["MiddleMouseButton"] = KeyCode::MiddleMouseButton;
			stringToKeyCode["ThumbMouseButton1"] = KeyCode::ThumbMouseButton1;
			stringToKeyCode["ThumbMouseButton2"] = KeyCode::ThumbMouseButton2;
			stringToKeyCode["BackSpace"] = KeyCode::BackSpace;
			stringToKeyCode["Tab"] = KeyCode::Tab;
			stringToKeyCode["Enter"] = KeyCode::Enter;
			stringToKeyCode["Shift"] = KeyCode::Shift;
			stringToKeyCode["Control"] = KeyCode::Control;
			stringToKeyCode["Alt"] = KeyCode::Alt;
			stringToKeyCode["PauseBreak"] = KeyCode::PauseBreak;
			stringToKeyCode["CapsLock"] = KeyCode::CapsLock;
			stringToKeyCode["Hangul"] = KeyCode::Hangul;
			stringToKeyCode["Hanja"] = KeyCode::Hanja;
			stringToKeyCode["Escape"] = KeyCode::Escape;
			stringToKeyCode["Space"] = KeyCode::Space;
			stringToKeyCode["PageUp"] = KeyCode::PageUp;
			stringToKeyCode["PageDown"] = KeyCode::PageDown;
			stringToKeyCode["End"] = KeyCode::End;
			stringToKeyCode["Home"] = KeyCode::Home;
			stringToKeyCode["Left"] = KeyCode::Left;
			stringToKeyCode["Right"] = KeyCode::Right;
			stringToKeyCode["Up"] = KeyCode::Up;
			stringToKeyCode["Down"] = KeyCode::Down;
			stringToKeyCode["Print"] = KeyCode::Print;
			stringToKeyCode["PrintScreen"] = KeyCode::PrintScreen;
			stringToKeyCode["Insert"] = KeyCode::Insert;
			stringToKeyCode["Delete"] = KeyCode::Delete;
			stringToKeyCode["Zero"] = KeyCode::Zero;
			stringToKeyCode["One"] = KeyCode::One;
			stringToKeyCode["Two"] = KeyCode::Two;
			stringToKeyCode["Three"] = KeyCode::Three;
			stringToKeyCode["Four"] = KeyCode::Four;
			stringToKeyCode["Five"] = KeyCode::Five;
			stringToKeyCode["Six"] = KeyCode::Six;
			stringToKeyCode["Seven"] = KeyCode::Seven;
			stringToKeyCode["Eight"] = KeyCode::Eight;
			stringToKeyCode["Nine"] = KeyCode::Nine;
			stringToKeyCode["A"] = KeyCode::A;
			stringToKeyCode["B"] = KeyCode::B;
			stringToKeyCode["C"] = KeyCode::C;
			stringToKeyCode["D"] = KeyCode::D;
			stringToKeyCode["E"] = KeyCode::E;
			stringToKeyCode["F"] = KeyCode::F;
			stringToKeyCode["G"] = KeyCode::G;
			stringToKeyCode["H"] = KeyCode::H;
			stringToKeyCode["I"] = KeyCode::I;
			stringToKeyCode["J"] = KeyCode::J;
			stringToKeyCode["K"] = KeyCode::K;
			stringToKeyCode["L"] = KeyCode::L;
			stringToKeyCode["M"] = KeyCode::M;
			stringToKeyCode["N"] = KeyCode::N;
			stringToKeyCode["O"] = KeyCode::O;
			stringToKeyCode["P"] = KeyCode::P;
			stringToKeyCode["Q"] = KeyCode::Q;
			stringToKeyCode["R"] = KeyCode::R;
			stringToKeyCode["S"] = KeyCode::S;
			stringToKeyCode["T"] = KeyCode::T;
			stringToKeyCode["U"] = KeyCode::U;
			stringToKeyCode["V"] = KeyCode::V;
			stringToKeyCode["W"] = KeyCode::W;
			stringToKeyCode["X"] = KeyCode::X;
			stringToKeyCode["Y"] = KeyCode::Y;
			stringToKeyCode["Z"] = KeyCode::Z;
			stringToKeyCode["LeftWin"] = KeyCode::LeftWin;
			stringToKeyCode["RightWin"] = KeyCode::RightWin;
			stringToKeyCode["Sleep"] = KeyCode::Sleep;
			stringToKeyCode["NumPad0"] = KeyCode::NumPad0;
			stringToKeyCode["NumPad1"] = KeyCode::NumPad1;
			stringToKeyCode["NumPad2"] = KeyCode::NumPad2;
			stringToKeyCode["NumPad3"] = KeyCode::NumPad3;
			stringToKeyCode["NumPad4"] = KeyCode::NumPad4;
			stringToKeyCode["NumPad5"] = KeyCode::NumPad5;
			stringToKeyCode["NumPad6"] = KeyCode::NumPad6;
			stringToKeyCode["NumPad7"] = KeyCode::NumPad7;
			stringToKeyCode["NumPad8"] = KeyCode::NumPad8;
			stringToKeyCode["NumPad9"] = KeyCode::NumPad9;
			stringToKeyCode["NumPadMultiply"] = KeyCode::NumPadMultiply;
			stringToKeyCode["NumPadPlus"] = KeyCode::NumPadPlus;
			stringToKeyCode["NumPadMinus"] = KeyCode::NumPadMinus;
			stringToKeyCode["NumPadDecimal"] = KeyCode::NumPadDecimal;
			stringToKeyCode["NumPadDivide"] = KeyCode::NumPadDivide;
			stringToKeyCode["F1"] = KeyCode::F1;
			stringToKeyCode["F2"] = KeyCode::F2;
			stringToKeyCode["F3"] = KeyCode::F3;
			stringToKeyCode["F4"] = KeyCode::F4;
			stringToKeyCode["F5"] = KeyCode::F5;
			stringToKeyCode["F6"] = KeyCode::F6;
			stringToKeyCode["F7"] = KeyCode::F7;
			stringToKeyCode["F8"] = KeyCode::F8;
			stringToKeyCode["F9"] = KeyCode::F9;
			stringToKeyCode["F10"] = KeyCode::F10;
			stringToKeyCode["F11"] = KeyCode::F11;
			stringToKeyCode["F12"] = KeyCode::F12;
			stringToKeyCode["F13"] = KeyCode::F13;
			stringToKeyCode["F14"] = KeyCode::F14;
			stringToKeyCode["F15"] = KeyCode::F15;
			stringToKeyCode["F16"] = KeyCode::F16;
			stringToKeyCode["F17"] = KeyCode::F17;
			stringToKeyCode["F18"] = KeyCode::F18;
			stringToKeyCode["F19"] = KeyCode::F19;
			stringToKeyCode["F20"] = KeyCode::F20;
			stringToKeyCode["F21"] = KeyCode::F21;
			stringToKeyCode["F22"] = KeyCode::F22;
			stringToKeyCode["F23"] = KeyCode::F23;
			stringToKeyCode["F24"] = KeyCode::F24;
			stringToKeyCode["NumLock"] = KeyCode::NumLock;
			stringToKeyCode["ScrollLock"] = KeyCode::ScrollLock;
			stringToKeyCode["LeftShift"] = KeyCode::LeftShift;
			stringToKeyCode["RightShift"] = KeyCode::RightShift;
			stringToKeyCode["LeftControl"] = KeyCode::LeftControl;
			stringToKeyCode["RightControl"] = KeyCode::RightControl;
			stringToKeyCode["LeftMenu"] = KeyCode::LeftMenu;
			stringToKeyCode["RightMenu"] = KeyCode::RightMenu;
			stringToKeyCode["VolumeMute"] = KeyCode::VolumeMute;
			stringToKeyCode["VolumeDown"] = KeyCode::VolumeDown;
			stringToKeyCode["VolumeUp"] = KeyCode::VolumeUp;
			stringToKeyCode["SemiColon"] = KeyCode::SemiColon;
			stringToKeyCode["Plus"] = KeyCode::Plus;
			stringToKeyCode["Comma"] = KeyCode::Comma;
			stringToKeyCode["Minus"] = KeyCode::Minus;
			stringToKeyCode["Period"] = KeyCode::Period;
			stringToKeyCode["Slash"] = KeyCode::Slash;
			stringToKeyCode["BackQuote"] = KeyCode::BackQuote;
			stringToKeyCode["LeftBracket"] = KeyCode::LeftBracket;
			stringToKeyCode["BackSlash"] = KeyCode::BackSlash;
			stringToKeyCode["RightBracket"] = KeyCode::RightBracket;
			stringToKeyCode["Quote"] = KeyCode::Quote;
		}

		return stringToKeyCode[str];
	}

	bool __isKeyCode(KeyCode button)
	{
		return !__isMouseButtonCode(button);
	}

	bool __isMouseButtonCode(KeyCode button)
	{
		return button == KeyCode::LeftMouseButton ||
			button == KeyCode::RightMouseButton ||
			button == KeyCode::MiddleMouseButton ||
			button == KeyCode::ThumbMouseButton1 ||
			button == KeyCode::ThumbMouseButton2;
	}

	WindowEvent::WindowEvent(SystemEventType eventType, int x, int y, int width, int height)
		: SystemEvent(eventType), m_x(x), m_y(y), m_width(width), m_height(height)
	{
		assert(__isWindowEvent(eventType));
	}


	KeyEvent::KeyEvent(SystemEventType eventType, KeyCode keyCode)
		: SystemEvent(eventType), m_keyCode(keyCode)
	{
		assert(__isKeyEvent(eventType) || eventType == SystemEventType::None);
		assert(__isKeyCode(keyCode) || keyCode == KeyCode::None);
	}

	MouseEvent::MouseEvent(SystemEventType eventType, const Array<KeyCode>& buttons, int x, int y, int wheelDelta)
		: SystemEvent(eventType), m_buttons(buttons), m_x(x), m_y(y), m_wheelDelta(wheelDelta)
	{
		assert(__isMouseEvent(eventType) || eventType == SystemEventType::None);
		for (KeyCode button : buttons)
		{
			assert(__isMouseButtonCode(button) || button == KeyCode::None);
		}		
	}
}