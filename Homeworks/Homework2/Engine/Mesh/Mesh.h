#pragma once
#pragma once

#include <vector>

#include "Core/Types.h"
#include "Core/ObjectBase.h"
#include "Math/Math.h"

namespace Engine
{
    class Mesh : public ObjectBase
    {
    public:
        // ----------------------------------------------------------------------
        // Constructor, Destructor
        // ----------------------------------------------------------------------

        Mesh() { }

    public:
        // ----------------------------------------------------------------------
        // Getter, Setter
        // ----------------------------------------------------------------------

        Array<Math::Vector3>& getVertexData();
        Array<UInt64>& getIndices();

        UInt64 getVertexCount() const;
        UInt64 getIndexCount() const;

        void setVertexData(Array<Math::Vector3>& data);
        void setIndices(Array<UInt64>& data);

    public:
        // ----------------------------------------------------------------------
        // Public Member Method
        // ----------------------------------------------------------------------

        Math::Vector3 getVertex(UInt64 arrayIndex);
        UInt64 getIndex(UInt64 arrayIndex);

        void setVertex(UInt64 arrayIndex, const Math::Vector3& vertex);
        void setIndex(UInt64 arrayIndex, UInt64 index);

        void insertVertex(UInt64 arrayIndex, const Math::Vector3& vertex);
        void insertIndex(UInt64 arrayIndex, UInt64 index);

        void removeVertex(UInt64 arrayIndex);
        void removeIndex(UInt64 arrayIndex);

        void pushVertex(const Math::Vector3& vertex);
        void pushIndex(UInt64 index);

        Math::Vector3 popVertex();
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
