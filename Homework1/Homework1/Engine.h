
#pragma once

#include "Alias.h"
#include "Singleton.h"
#include "Renderer.h"

namespace Engine
{
	class World;

	class SystemEvent;
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
		Array<Renderer*>&& getRenderers();
		Int64 getRendererCount() const;

		void setWorld(World* world);

	public:
		// ----------------------------------------------------------------------
		// Public Member Method
		// ----------------------------------------------------------------------

		void dispatchEvent(SystemEvent * evt);
		void dispatchWindowEvent(WindowEvent * evt);
		void dispatchKeyEvent(KeyEvent * evt);
		void dispatchMouseEvent(MouseEvent * evt);

		void update(float deltaTime);
		void render();

		void addRenderer(Renderer* renderer);
		void removeRenderer(const UUID& uuid);
		void removeRenderer(Renderer* renderer);

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

		World* m_world = nullptr;
		UUIDMap<Renderer*> m_renderers;
	};
}