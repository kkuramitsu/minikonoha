// written by kimio

import("konoha.object");

void test() {
	Object o = 123;
	int n = o as int;
	String s = o as String;
	assert(n == 123);
	assert(s == "");  // default value
}

test();

