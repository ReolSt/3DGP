#include "MeshAsset.h"

#include "Asset/AssetStorage.h"
#include "Math/Math.h"

#include <string>

namespace Engine
{
	using namespace Math;

	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	MeshAsset::MeshAsset()
	{

	}

	MeshAsset::~MeshAsset()
	{
		
	}

	Array<Vector3>& MeshAsset::getVertices()
	{
		return m_vertices;
	}

	Array<Vector3>& MeshAsset::getNormals()
	{
		return m_normals;
	}

	Array<Vector2>& MeshAsset::getUVs()
	{
		return m_uvs;
	}

	Array<UInt64>& MeshAsset::getIndices()
	{
		return m_indices;
	}

	// ----------------------------------------------------------------------
	// Public Member Method
	// ----------------------------------------------------------------------

	void MeshAsset::load(const WString& assetFilePath)
	{
		Asset::load(assetFilePath);

		std::string filePath;
		filePath.assign(assetFilePath.begin(), assetFilePath.end());

		FILE* file = fopen(filePath.c_str(), "r");
		if (file == NULL)
		{
			return;
		}

		std::vector<Vector3> vertices;
		std::vector<Vector3> normals;
		std::vector<Vector2> uvs;
		std::vector<UInt64> indices;

		std::vector<UInt64> vertexIndices, uvIndices, normalIndices;

		while (1)
		{
			char lineHeader[128];

			int res = fscanf(file, "%s", lineHeader);
			if (res == EOF)
			{
				break;
			}

			if (strcmp(lineHeader, "v") == 0)
			{
				float x, y, z;
				fscanf(file, "%f %f %f\n", &x, &y, &z);

				vertices.push_back(Vector3(x, y, z));
			}
			else if (strcmp(lineHeader, "vt") == 0)
			{
				Vector2 uv;
				float x, y;
				fscanf(file, "%f %f\n", &x, &y);

				uv.setX(x);
				uv.setY(-y);
				uvs.push_back(uv);
			}
			else if (strcmp(lineHeader, "vn") == 0)
			{
				float x, y, z;
				fscanf(file, "%f %f %f\n", &x, &y, &z);

				normals.push_back(Vector3(x, y, z));
			}
			else if (strcmp(lineHeader, "f") == 0)
			{
				std::string vertex1, vertex2, vertex3;
				unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

				int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
					&vertexIndex[0], &uvIndex[0], &normalIndex[0],
					&vertexIndex[1], &uvIndex[1], &normalIndex[1],
					&vertexIndex[2], &uvIndex[2], &normalIndex[2]);

				if (matches != 9)
				{
					printf("File can't be read by our simple parser :-( Try exporting with other options\n");
					fclose(file);
					return;
				}

				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);

				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);

				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);
			}
			else
			{
				char stupidBuffer[1000];
				fgets(stupidBuffer, 1000, file);
			}

		}

		for (unsigned int i = 0; i < vertexIndices.size(); i++)
		{
			unsigned int vertexIndex = vertexIndices[i] - 1;
			unsigned int uvIndex = uvIndices[i] - 1;
			unsigned int normalIndex = normalIndices[i] - 1;

			m_vertices.push_back(vertices[vertexIndex]);
			m_normals.push_back(normals[normalIndex]);
			m_uvs.push_back(uvs[uvIndex]);
			m_indices.push_back(i);
		}

		fclose(file);
	}

	void MeshAsset::unload()
	{
		Asset::unload();
	}
}


