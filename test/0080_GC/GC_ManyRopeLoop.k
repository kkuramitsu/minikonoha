// written by unknown (maybe ide)
// added by kimio

import("cstyle");
import("konoha.string");

void f() {
	int i = 0;
	String t = "longLived";
	String dummy;
	while (i < 1000000) {
		dummy = t + " ";
		i = i + 1;
	}
	System.gc();
	System.p(t);
}
f();
