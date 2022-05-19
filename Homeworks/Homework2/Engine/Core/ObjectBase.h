#pragma once

#include <string>
#include <typeinfo>

#include "Types.h"

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

		ObjectBase(const String& name = "");
		ObjectBase(const ObjectBase& obj);

		virtual ~ObjectBase() { }

		// ----------------------------------------------------------------------
		// Getter, Setter
		// ----------------------------------------------------------------------

		String getTypeName() const;
		UInt64 getTypeId() const;
		String getId() const;
		String getName() const;

		void setName(const String& name);

	private:
		void __setId(const UUID& id);

	private:
		// ----------------------------------------------------------------------
		// Private Member Variable
		// ----------------------------------------------------------------------

		UUID m_id;
		String m_name;
	};
}
