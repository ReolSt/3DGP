#include "LineMesh.h"
#include "Alias.h"

namespace Engine
{
    // ----------------------------------------------------------------------
    // Getter, Setter
    // ----------------------------------------------------------------------

    Array<Vector3>& LineMesh::getVertexData()
    {
        return m_vertexData;
    }

    Array<Vector3>& LineMesh::getVertexColorData()
    {
        return m_vertexColorData;
    }

    Array<UInt64>& LineMesh::getIndices()
    {
        return m_indices;
    }

    UInt64 LineMesh::getVertexCount() const
    {
        return m_vertexData.size();
    }

    UInt64 LineMesh::getVertexColorCount() const
    {
        return m_vertexColorData.size();
    }

    UInt64 LineMesh::getIndexCount() const
    {
        return m_indices.size();
    }

    void LineMesh::setVertexData(Array<Vector3>& data)
    {
        m_vertexData = data;
    }

    void LineMesh::setVertexColorData(Array<Vector3>& data)
    {
        m_vertexColorData = data;
    }

    void LineMesh::setIndices(Array<UInt64>& data)
    {
        m_indices = data;
    }

    // ----------------------------------------------------------------------
    // Public Member Method
    // ----------------------------------------------------------------------

    Vector3 LineMesh::getVertex(UInt64 arrayIndex)
    {
        return m_vertexData[arrayIndex];
    }

    Vector3 LineMesh::getVertexColor(UInt64 arrayIndex)
    {
        return m_vertexColorData[arrayIndex];
    }

    UInt64 LineMesh::getIndex(UInt64 arrayIndex)
    {
        return m_indices[arrayIndex];
    }

    void LineMesh::setVertex(UInt64 arrayIndex, const Vector3& vertex)
    {
        m_vertexData[arrayIndex] = vertex;
    }

    void LineMesh::setVertexColor(UInt64 arrayIndex, const Vector3& vertexColor)
    {
        m_vertexColorData[arrayIndex] = vertexColor;
    }

    void LineMesh::setIdnex(UInt64 arrayIndex, UInt64 index)
    {
        m_indices[arrayIndex] = index;
    }

    void LineMesh::addVertex(UInt64 arrayIndex, const Vector3& vertex)
    {
        m_vertexData.insert(m_vertexColorData.begin() + arrayIndex, vertex);
    }

    void LineMesh::addVertexColor(UInt64 arrayIndex, const Vector3& vertexColor)
    {
        m_vertexColorData.insert(m_vertexColorData.begin() + arrayIndex, vertexColor);
    }

    void LineMesh::addIndex(UInt64 arrayIndex, UInt64 index)
    {
        m_indices.insert(m_indices.begin() + arrayIndex, index);
    }

    void LineMesh::removeVertex(UInt64 arrayIndex)
    {
        m_vertexData.erase(m_vertexData.begin() + arrayIndex);
    }

    void LineMesh::removeVertexColor(UInt64 arrayIndex)
    {
        m_vertexColorData.erase(m_vertexData.begin() + arrayIndex);
    }

    void LineMesh::removeIndex(UInt64 arrayIndex)
    {
        m_indices.erase(m_indices.begin() + arrayIndex);
    }

    void LineMesh::pushVertex(const Vector3& vertex)
    {
        m_vertexData.push_back(vertex);
    }

    void LineMesh::pushVertexColor(const Vector3& vertexColor)
    {
        m_vertexColorData.push_back(vertexColor);
    }

    void LineMesh::pushIndex(UInt64 index)
    {
        m_indices.push_back(index);
    }

    Vector3 LineMesh::popVertex()
    {
        auto vertex = m_vertexData.back();
        m_vertexData.pop_back();

        return vertex;
    }

    Vector3 LineMesh::popVertexColor()
    {
        auto vertexColor = m_vertexColorData.back();
        m_vertexColorData.pop_back();

        return vertexColor;
    }
    UInt64 LineMesh::popIndex()
    {
        return UInt64();
    }
}