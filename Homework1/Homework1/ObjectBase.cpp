#include "ObjectBase.h"
#include "UniqueIDGenerator.h"
#include "Alias.h"

#include <string>

namespace Engine
{
	// ----------------------------------------------------------------------
	// Constructor, Destructor
	// ----------------------------------------------------------------------

	ObjectBase::ObjectBase(const String& name)
	{
		this->m_id = UniqueIDGenerator::Generate();
		this->m_name = name;
	}

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	String ObjectBase::getTypeName() const
	{
		return GetTypeName(*this);
	}

	UInt64 ObjectBase::getTypeId() const
	{
		return GetTypeId(*this);
	}

	String ObjectBase::getId() const
	{
		return this->m_id;
	}

	String ObjectBase::getName() const
	{
		return this->m_name;
	}

	void ObjectBase::setName(const String& name)
	{
		this->m_name = name;
	}
}