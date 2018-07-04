#pragma once

using namespace System;

namespace LeagueTeamStructureDLL {

	public ref class Class1
	{
	public:
		TeamStructure *pu;

		Class1() : pu(new TeamStructure()) {};

		DWORD getStructureString() {
			return pu->getStructureString();
		}
	};
}