#include "ObjectBase.h"
#include "UniqueIDGenerator.h"

#include <string>

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	ObjectBase::ObjectBase(const std::string& name)
	{
		this->m_id = UniqueIDGenerator::Generate();
		this->m_name = name;
	}

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	std::string ObjectBase::getTypeName() const
	{
		return typeid(this).name();
	}

	size_t ObjectBase::getTypeId() const
	{
		return typeid(this).hash_code();
	}

	std::string ObjectBase::getId() const
	{
		return this->m_id;
	}

	std::string ObjectBase::getName() const
	{
		return this->m_name;
	}

	void ObjectBase::setName(const std::string& name)
	{
		this->m_name = name;
	}
}