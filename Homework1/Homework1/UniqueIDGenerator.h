#pragma once

#include <cstdio>
#include <array>
#include <string>

#include <combaseapi.h>

namespace Engine
{
	class UniqueIDGenerator
	{
	public:
		UniqueIDGenerator() { }
		virtual ~UniqueIDGenerator() { }

	public:
		static std::string Generate()
		{
			GUID guid;
			HRESULT result = CoCreateGuid(&guid);

			std::array<char, 40> output;
			snprintf(output.data(), output.size(), "{%08X-%04hX-%04hX-%02X%02X-%02X%02X%02X%02X%02X%02X}", guid.Data1, guid.Data2, guid.Data3, guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

			return std::string(output.data());
		}
	};
}