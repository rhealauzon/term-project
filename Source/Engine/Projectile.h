#ifndef PROJECTILE_H
#define PROJECTILE_H

/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: Projectile.h
--
-- PROGRAM:
--
-- FUNCTIONS: N/A
--
-- DATE: March 15, 2015
--
-- REVISIONS:
--
-- DESIGNER: Thomas Tallentire
--
-- PROGRAMMER: Thomas Tallentire
--
-- NOTES:
--        This file defines the Entity class members
--
----------------------------------------------------------------------------------------------------------------------*/

#include <functional>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include "VEntity.h"
#include "ProjectileManager.h"
#include "Map.h"

namespace Marx
{
	class Projectile : public VEntity
	{
		private:
			float _speed;
			std::function<void(Entity*)> onHit;
			sf::Vector2f heading;
			sf::Time TimeToLive;
			Action & act;
		public:
			Projectile(SGO&, Map*, float, float, Controller *, sf::Vector2f, float, float);

			Entity * move(float, float, bool);
			void setSpeed(float);
			void onCreate();
			void onDestroy();
			void onUpdate();
	};
}

#endif
