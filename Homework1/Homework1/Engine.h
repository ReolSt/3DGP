#pragma once

#include "Singleton.h"

namespace Engine
{
	class World;

	class Event;
	class WindowEvent;
	class KeyEvent;
	class MouseEvent;

	class Engine : public Singleton<Engine>
	{
	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		World* getWorld();

		void setWorld(World* world);

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void dispatchEvent(Event * evt);
		void dispatchWindowEvent(WindowEvent * evt);
		void dispatchKeyEvent(KeyEvent * evt);
		void dispatchMouseEvent(MouseEvent * evt);

		void renderWorld();

	private:
		// ----------------------------------------------------------------------
		// Private Member Method
		// ----------------------------------------------------------------------

		void __debugPrintWindowEvent(WindowEvent * evt);
		void __debugPrintMouseEvent(MouseEvent * evt);
		void __debugPrintKeyEvent(KeyEvent * evt);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		World* m_world;
	};
}