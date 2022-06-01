#pragma once

namespace Engine
{
	struct Viewport
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Viewport() { }

		Viewport(Float x, Float y, Float width, Float height)
		{
			m_x = x;
			m_y = y;
			m_width = width;
			m_height = height;
		}

	public:
		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		Float getX() const { return m_x; }
		Float getY() const { return m_y; }
		Float getWidth() const { return m_width; }
		Float getHeight() const { return m_height; }

		void setX(Float x) { m_x = x; }
		void setY(Float y) { m_y = y; }
		void setWidth(Float width) { m_width = width; }
		void setHeight(Float height) { m_height = height; }

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Float m_x = 0.0f;
		Float m_y = 0.0f;
		Float m_width = 1.0f;
		Float m_height = 1.0f;
	};
};

