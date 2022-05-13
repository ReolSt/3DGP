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
		__setId(UniqueIDGenerator::Generate());
		setName(name);
	}

	// ----------------------------------------------------------------------
	// Getter, Setter
	// ----------------------------------------------------------------------

	ObjectBase::ObjectBase(const ObjectBase& obj)
	{
		__setId(obj.getId());
		setName(obj.getName());
	}

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
		return m_id;
	}

	String ObjectBase::getName() const
	{
		return m_name;
	}

	void ObjectBase::setName(const String& name)
	{
		m_name = name;
	}

	void ObjectBase::__setId(const UUID& id)
	{
		m_id = id;
	}
}