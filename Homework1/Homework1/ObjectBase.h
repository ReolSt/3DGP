#pragma once

#include <string>
#include <typeinfo>

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
		size_t getTypeId() const;
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
