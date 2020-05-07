#pragma once

using namespace System;

ref class Witch
{
public:
	String^ witchName;

	Witch(String^ name);

	void speak();
	void setName(String^ name) { witchName = gcnew String(name); }
	String^ getName() { return witchName; }
};

