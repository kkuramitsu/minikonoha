// written by wakamatsu
import("konoha.bytes");
import("konoha.float");
import("konoha.mpi");

void test_bytes() {
	MPIComm w = MPIComm.getWorld();
	if(w.getRank() == 0) {
		MPIData d = MPIData.fromBytes("this_is_konoha".asBytes());
		d.setOffset(8);
		w.iSend(d, 6, 1, 0);
	} else {
		MPIData d = MPIData.fromBytes("hello ".asBytes());
		d.setOffset(6);
		MPIRequest req = w.iRecv(d, 6, 0, 0);
		req.wait();
		d.setOffset(0);
		p(d.toBytes().asString());
	}
}

void test_iarray() {
	MPIComm w = MPIComm.getWorld();
	if(w.getRank() == 0) {
		MPIData d = MPIData.newIntArray(5);
		d.seti(3, 100);
		d.seti(4, 101);
		d.setOffset(3);
		w.iSend(d, 2, 1, 0);
	} else {
		MPIData d = MPIData.newIntArray(1);
		d.seti(0, 99);
		d.setOffset(1);
		MPIRequest req = w.iRecv(d, 2, 0, 0);
		req.wait();
		d.setOffset(0);
		p(d.getSize());
		p(d.geti(0));
		p(d.geti(1));
		p(d.geti(2));
	}
}

void test_farray() {
	MPIComm w = MPIComm.getWorld();
	if(w.getRank() == 0) {
		MPIData d = MPIData.newFloatArray(5);
		d.setf(3, 100.0);
		d.setf(4, 101.0);
		d.setOffset(3);
		w.iSend(d, 2, 1, 0);
	} else {
		MPIData d = MPIData.newFloatArray(1);
		d.setf(0, 99);
		d.setOffset(1);
		MPIRequest req = w.iRecv(d, 2, 0, 0);
		req.wait();
		d.setOffset(0);
		p(d.getSize());
		p(d.getf(0));
		p(d.getf(1));
		p(d.getf(2));
	}
}

test_bytes();
test_iarray();
test_farray();

