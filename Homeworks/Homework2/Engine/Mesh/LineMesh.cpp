#include "Mesh/LineMesh.h"
#include "Core/Types.h"

namespace Engine
{
    using namespace Math;

    // ----------------------------------------------------------------------
    // Getter, Setter
    // ----------------------------------------------------------------------

    Array<Vector3>& LineMesh::getVertexColorData()
    {
        return m_vertexColorData;
    }

    UInt64 LineMesh::getVertexColorCount() const
    {
        return m_vertexColorData.size();
    }

    void LineMesh::setVertexColorData(Array<Vector3>& data)
    {
        m_vertexColorData = data;
    }

    // ----------------------------------------------------------------------
    // Public Member Method
    // ----------------------------------------------------------------------

    Vector3 LineMesh::getVertexColor(UInt64 arrayIndex)
    {
        return m_vertexColorData[arrayIndex];
    }

    void LineMesh::setVertexColor(UInt64 arrayIndex, const Vector3& vertexColor)
    {
        m_vertexColorData[arrayIndex] = vertexColor;
    }

    void LineMesh::insertVertexColor(UInt64 arrayIndex, const Vector3& vertexColor)
    {
        m_vertexColorData.insert(m_vertexColorData.begin() + arrayIndex, vertexColor);
    }

    void LineMesh::removeVertexColor(UInt64 arrayIndex)
    {
        m_vertexColorData.erase(m_vertexColorData.begin() + arrayIndex);
    }

    void LineMesh::pushVertexColor(const Vector3& vertexColor)
    {
        m_vertexColorData.push_back(vertexColor);
    }

    Vector3 LineMesh::popVertexColor()
    {
        auto vertexColor = m_vertexColorData.back();
        m_vertexColorData.pop_back();

        return vertexColor;
    }
}