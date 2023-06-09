#include "nspacepch.h"
#include "Entity.h"

namespace Newspace {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}