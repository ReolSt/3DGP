#include "LineMeshRenderer.h"
#include "Engine.h"
#include "World.h"
#include "Component.h"
#include "LineMeshComponent.h"
#include "CameraComponent.h"


namespace Engine
{
	using namespace Math;

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

		auto cameras = Array<Component*>();
		world->getRegisteredComponentsByTypeId(GetTypeId(CameraComponent), cameras);

		auto meshes = Array<Component*>();
		engine->getWorld()->getRegisteredComponentsByTypeId(GetTypeId(LineMeshComponent), meshes);

		//PAINTSTRUCT ps;
		//BeginPaint(m_window, &ps);

		DWORD backgroundColor = RGB(255, 255, 255);
		HBRUSH backgroundBrush = CreateSolidBrush(backgroundColor);
		HBRUSH oldBrush = (HBRUSH)SelectObject(m_dc, backgroundBrush);

		Rectangle(m_dc, m_rcClient.left, m_rcClient.top, m_rcClient.right, m_rcClient.bottom);

		SelectObject(m_dc, oldBrush);
		DeleteObject(backgroundBrush);

		HPEN pen = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(m_dc, pen);

		for (auto& component : cameras)
		{
			if (!component->isActive())
			{
				continue;
			}

			auto camera = dynamic_cast<CameraComponent*>(component);
			auto view = camera->getViewMatrix();
			auto projection = camera->getPerspectiveProjectionMatrix();

			Viewport viewport = camera->getViewport();

			auto viewportX = viewport.getX();
			auto viewportY = viewport.getY();
			auto viewportWidth = viewport.getWidth();
			auto viewportHeight = viewport.getHeight();

			for (auto& component : meshes)
			{
				if (!component->isActive())
				{
					continue;
				}

				auto meshComponent = dynamic_cast<LineMeshComponent*>(component);
				auto meshWorldTransform = meshComponent->getWorldTransform();				

				auto mesh = meshComponent->getMesh();

				if (mesh == nullptr)
				{
					continue;
				}

				auto& vertexData = mesh->getVertexData();
				auto& vertexColorData = mesh->getVertexColorData();
				auto& indices = mesh->getIndices();

				assert(vertexData.size() == vertexColorData.size());
				assert(indices.size() % 3 == 0);

				auto modelToWorld = meshWorldTransform.toMatrix();
				auto modelToScreen = modelToWorld * view * projection;

				Array<Math::Vector4> screenVertices;
				//Array<TRIVERTEX> win32ScreenVertices;
				for(int i = 0; i < vertexData.size(); ++i)
				{
					auto screenVertex = modelToScreen * Math::Vector4(vertexData[i], 1.0f);

					screenVertex.setX(viewportX + viewportWidth / 2.0f + screenVertex.getX() / screenVertex.getW() * viewportWidth / 2.0f);
					screenVertex.setY(viewportY + viewportHeight / 2.0f + screenVertex.getY() / screenVertex.getW() * viewportHeight / 2.0f);

					screenVertices.push_back(screenVertex);
				}

				for (UInt64 i = 0; i < indices.size(); i += 3)
				{
					if (screenVertices[indices[i]].getW() < 0.0f ||
						screenVertices[indices[i + 1]].getW() < 0.0f ||
						screenVertices[indices[i + 2]].getW() < 0.0f)
					{
						continue;
					}

					POINT pts[4] = {
						{screenVertices[indices[i]].getX(), screenVertices[indices[i]].getY()},
						{screenVertices[indices[i + 1]].getX(), screenVertices[indices[i + 1]].getY()},
						{screenVertices[indices[i + 2]].getX(), screenVertices[indices[i + 2]].getY()},
						{screenVertices[indices[i]].getX(), screenVertices[indices[i]].getY()}
					};
					
					Polyline(m_dc, pts, 4);
				}				
			}
		}

		SelectObject(m_dc, oldPen);
		DeleteObject(pen);

		//EndPaint(m_window, &ps);

		HDC dc = GetDC(m_window);

		BitBlt(dc, m_rcClient.left, m_rcClient.top, m_rcClient.right - m_rcClient.left, m_rcClient.bottom - m_rcClient.top, m_dc, m_rcClient.left, m_rcClient.top, SRCCOPY);

		ReleaseDC(m_window, dc);
	}
}

