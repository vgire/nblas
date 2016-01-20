#include "cblas.h"
#include "decl.h"

NAN_METHOD(dasum) {
	const int n = info[0]->Uint32Value();
	const double *x = reinterpret_cast<double*>(info[1].As<v8::Float64Array>()->Buffer()->GetContents().Data());
	const int inc_x = info[2]->Uint32Value();
	info.GetReturnValue().Set(
		Nan::New<v8::Number>(cblas_dasum(n, x, inc_x))
	);
}

NAN_METHOD(sasum) {
	const int n = info[0]->Uint32Value();
	const float *x = reinterpret_cast<float*>(info[1].As<v8::Float32Array>()->Buffer()->GetContents().Data());
	const int inc_x = info[2]->Uint32Value();
	info.GetReturnValue().Set(
		Nan::New<v8::Number>(cblas_sasum(n, x, inc_x))
	);
}
