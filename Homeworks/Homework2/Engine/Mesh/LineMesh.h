#pragma once

#include <vector>

#include "Core/Types.h"
#include "Mesh/Mesh.h"

namespace Engine
{
    class LineMesh : public Mesh
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

        Array<Math::Vector3>& getVertexColorData();
        UInt64 getVertexColorCount() const;

        void setVertexColorData(Array<Math::Vector3>& data);

    public:
        // ----------------------------------------------------------------------
        // Public Member Method
        // ----------------------------------------------------------------------

        Math::Vector3 getVertexColor(UInt64 arrayIndex);
        void setVertexColor(UInt64 arrayIndex, const Math::Vector3& vertexColor);

        void insertVertexColor(UInt64 arrayIndex, const Math::Vector3& vertexColor);
        void removeVertexColor(UInt64 arrayIndex);

        void pushVertexColor(const Math::Vector3& vertexColor);
        Math::Vector3 popVertexColor();

    private:
        // ----------------------------------------------------------------------
        // Private Member Variable
        // ----------------------------------------------------------------------

        Array<Math::Vector3> m_vertexColorData;
    };
}