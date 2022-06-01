#include "Mesh/Mesh.h"

namespace Engine
{
    using namespace Math;

    Array<Vector3>& Mesh::getVertexData()
    {
        return m_vertexData;
    }

    Array<UInt64>& Mesh::getIndices()
    {
        return m_indices;
    }

    UInt64 Mesh::getVertexCount() const
    {
        return m_vertexData.size();
    }

    UInt64 Mesh::getIndexCount() const
    {
        return m_indices.size();
    }

    void Mesh::setVertexData(Array<Vector3>& data)
    {
        m_vertexData = data;
    }

    void Mesh::setIndices(Array<UInt64>& data)
    {
        m_indices = data;
    }

    // ----------------------------------------------------------------------
    // Public Member Method
    // ----------------------------------------------------------------------

    Vector3 Mesh::getVertex(UInt64 arrayIndex)
    {
        return m_vertexData[arrayIndex];
    }

    UInt64 Mesh::getIndex(UInt64 arrayIndex)
    {
        return m_indices[arrayIndex];
    }

    void Mesh::setVertex(UInt64 arrayIndex, const Vector3& vertex)
    {
        m_vertexData[arrayIndex] = vertex;
    }

    void Mesh::setIndex(UInt64 arrayIndex, UInt64 index)
    {
        m_indices[arrayIndex] = index;
    }

    void Mesh::insertVertex(UInt64 arrayIndex, const Vector3& vertex)
    {
        m_vertexData.insert(m_vertexColorData.begin() + arrayIndex, vertex);
    }

    void Mesh::insertIndex(UInt64 arrayIndex, UInt64 index)
    {
        m_indices.insert(m_indices.begin() + arrayIndex, index);
    }

    void Mesh::removeVertex(UInt64 arrayIndex)
    {
        m_vertexData.erase(m_vertexData.begin() + arrayIndex);
    }

    void Mesh::removeIndex(UInt64 arrayIndex)
    {
        m_indices.erase(m_indices.begin() + arrayIndex);
    }

    void Mesh::pushVertex(const Vector3& vertex)
    {
        m_vertexData.push_back(vertex);
    }

    void Mesh::pushIndex(UInt64 index)
    {
        m_indices.push_back(index);
    }

    Vector3 Mesh::popVertex()
    {
        auto vertex = m_vertexData.back();
        m_vertexData.pop_back();

        return vertex;
    }

    UInt64 Mesh::popIndex()
    {
        return UInt64();
    }
}