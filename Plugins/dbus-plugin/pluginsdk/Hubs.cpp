/*
 * Copyright (C) 2012-2014 Jacek Sieka, arnetheduck on gmail point com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/* Helpers around the DCHub interface. */

#include "Hubs.h"

#include "Core.h"

namespace dcapi {

DCHubPtr Hubs::hubs;

bool Hubs::init() {
	if(!Core::handle()) { return false; }
	init(reinterpret_cast<DCHubPtr>(Core::handle()->query_interface(DCINTF_DCPP_HUBS, DCINTF_DCPP_HUBS_VER)));
	return hubs;
}
void Hubs::init(DCHubPtr coreHub) { hubs = coreHub; }
DCHubPtr Hubs::handle() { return hubs; }

} // namespace dcapi
