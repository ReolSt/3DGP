#pragma once

#include "Box.h"

namespace Engine
{
	struct Viewport
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		Viewport() { }

		Viewport(Int x, Int y, Int width, Int height)
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

		Int getX() const { return m_x; }
		Int getY() const { return m_y; }
		Int getWidth() const { return m_width; }
		Int getHeight() const { return m_height; }

		void setX(Int x) { m_x = x; }
		void setY(Int y) { m_y = y; }
		void setWidth(Int width) { m_width = width; }
		void setHeight(Int height) { m_height = height; }

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		Int m_x = 0;
		Int m_y = 0;
		Int m_width = 0;
		Int m_height = 0;
	};
};

