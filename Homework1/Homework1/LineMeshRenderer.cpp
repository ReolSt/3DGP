#include "LineMeshRenderer.h"
#include "Engine.h"
#include "World.h"
#include "Component.h"
#include "LineMeshComponent.h"
#include "CameraComponent.h"

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	LineMeshRenderer::LineMeshRenderer()
	{

	}

	LineMeshRenderer::~LineMeshRenderer()
	{

	}

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	void LineMeshRenderer::initialize(HINSTANCE instance, HWND window)
	{
		m_instance = instance;
		m_window = window;

		GetClientRect(window, &m_rcClient);

		HDC dc = GetDC(window);

		m_dc = CreateCompatibleDC(dc);
		m_frameBuffer = CreateCompatibleBitmap(dc, m_rcClient.right - m_rcClient.left, m_rcClient.bottom - m_rcClient.top);
		::SelectObject(m_dc, m_frameBuffer);

		ReleaseDC(window, dc);
		SetBkMode(m_dc, TRANSPARENT);
	}

	void LineMeshRenderer::render(Engine* engine)
	{
		auto world = engine->getWorld();

		auto cameras = world->getRegisteredComponentsByTypeId(GetTypeId(CameraComponent));
		auto meshes = engine->getWorld()->getRegisteredComponentsByTypeId(GetTypeId(LineMeshComponent));

		DWORD color = RGB(255, 0, 0);

		HPEN pen = CreatePen(PS_SOLID, 0, color);
		HPEN oldPen = (HPEN)SelectObject(m_dc, pen);
		//HBRUSH brush = CreateSolidBrush(color);
		//HBRUSH oldBrush = (HBRUSH)SelectObject(m_dc, brush);

		HDC dc = GetDC(m_window);

		for (auto& component : cameras)
		{
			if (!component->isActive())
			{
				continue;
			}

			auto camera = dynamic_cast<CameraComponent*>(component);

			Matrix screenTransform = camera->getPerspectiveScreenTransformMatrix();

			for (auto& component : meshes)
			{
				auto mesh = dynamic_cast<LineMesh*>(component);
				auto& vertexData = mesh->getVertexData();
				auto& vertexColorData = mesh->getVertexColorData();
				auto& indices = mesh->getIndices();

				assert(indices.size() % 2 == 0);

				for (UInt64 i = 0; i < indices.size(); i += 2)
				{
					auto v1 = vertexData[indices[i]];
					auto v2 = vertexData[indices[i + 1]];

					auto screenVertex1 = camera->getPerspectiveScreenTransformMatrix() * v1;
					auto screenVertex2 = camera->getPerspectiveScreenTransformMatrix() * v2;

					MoveToEx(m_dc, screenVertex1.getX(), screenVertex2.getY(), NULL);
					LineTo(m_dc, screenVertex2.getX(), screenVertex2.getY());
				}
			}
		}

		//SelectObject(m_dc, oldBrush);
		//DeleteObject(brush);

		SelectObject(m_dc, oldPen);
		DeleteObject(pen);		

		BitBlt(dc, m_rcClient.left, m_rcClient.top, m_rcClient.right - m_rcClient.left, m_rcClient.bottom - m_rcClient.top, m_dc, m_rcClient.left, m_rcClient.top, SRCCOPY);

		ReleaseDC(m_window, dc);
	}
}

