#pragma once

#include <string>
#include <typeinfo>

#include "Alias.h"

#define GetTypeName(obj) ((std::string(typeid(obj).name())))
#define GetTypeId(obj) ((typeid(obj).hash_code()))

namespace Engine
{
	class ObjectBase
	{
	public:
		// ----------------------------------------------------------------------
		// Constructor, Destructor
		// ----------------------------------------------------------------------

		ObjectBase(const std::string& name = "");

		virtual ~ObjectBase() { }

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		std::string getTypeName() const;
		UInt64 getTypeId() const;
		std::string getId() const;
		std::string getName() const;

		void setName(const std::string& name);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		std::string m_id;
		std::string m_name;
	};
}
