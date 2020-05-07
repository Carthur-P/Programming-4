#pragma once

using namespace System;

ref class Monster
{
public:
	String^ monsterName;

	Monster(String^ name);

	void speak();
	void setName(String^ name) { monsterName = gcnew String(name);}
	String^ getName() { return monsterName; }
};


