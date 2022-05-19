#pragma once

#include <vector>

#include "ObjectBase.h"
#include "Math.h"
#include "Alias.h"

namespace Engine
{
    class LineMesh : public ObjectBase
    {
    public:
        // ----------------------------------------------------------------------
        // Constructor, Destructor
        // ----------------------------------------------------------------------

        LineMesh() { }

    public:
        // ----------------------------------------------------------------------
        // Getter, Setter
        // ----------------------------------------------------------------------

        Array<Math::Vector3>& getVertexData();
        Array<Math::Vector3>& getVertexColorData();
        Array<UInt64>& getIndices();
        UInt64 getVertexCount() const;
        UInt64 getVertexColorCount() const;
        UInt64 getIndexCount() const;

        void setVertexData(Array<Math::Vector3>& data);
        void setVertexColorData(Array<Math::Vector3>& data);
        void setIndices(Array<UInt64>& data);

    public:
        // ----------------------------------------------------------------------
        // Public Member Method
        // ----------------------------------------------------------------------

        Math::Vector3 getVertex(UInt64 arrayIndex);
        Math::Vector3 getVertexColor(UInt64 arrayIndex);
        UInt64 getIndex(UInt64 arrayIndex);

        void setVertex(UInt64 arrayIndex, const Math::Vector3& vertex);
        void setVertexColor(UInt64 arrayIndex, const Math::Vector3& vertexColor);
        void setIdnex(UInt64 arrayIndex, UInt64 index);

        void addVertex(UInt64 arrayIndex, const Math::Vector3& vertex);
        void addVertexColor(UInt64 arrayIndex, const Math::Vector3& vertexColor);
        void addIndex(UInt64 arrayIndex, UInt64 index);

        void removeVertex(UInt64 arrayIndex);
        void removeVertexColor(UInt64 arrayIndex);
        void removeIndex(UInt64 arrayIndex);

        void pushVertex(const Math::Vector3& vertex);
        void pushVertexColor(const Math::Vector3& vertexColor);
        void pushIndex(UInt64 index);

        Math::Vector3 popVertex();
        Math::Vector3 popVertexColor();
        UInt64 popIndex();

    private:
        // ----------------------------------------------------------------------
        // Private Member Variable
        // ----------------------------------------------------------------------

        Array<Math::Vector3> m_vertexData;
        Array<Math::Vector3> m_vertexColorData;
        Array<UInt64> m_indices;
    };
}