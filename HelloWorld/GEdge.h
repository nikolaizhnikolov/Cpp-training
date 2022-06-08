#pragma once

class GEdge
{
public:
	int a;
	int b;

	GEdge(int a, int b) : a(a), b(b) {};

	bool operator==(const GEdge& other) {
		return
			a == other.a &&
			b == other.b;
	};
};

