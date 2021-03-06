#include "cblas.h"
#include "routines.h"

void dnrm2(const v8::FunctionCallbackInfo<v8::Value>& info) {
	const int n = info[0]->Uint32Value();
	const double *x = reinterpret_cast<double*>(info[1].As<v8::Float64Array>()->Buffer()->GetContents().Data());
	const int inc_x = info[2]->Uint32Value();
	info.GetReturnValue().Set(
		v8::Number::New(info.GetIsolate(), cblas_dnrm2(n, x, inc_x))
	);
}

void snrm2(const v8::FunctionCallbackInfo<v8::Value>& info) {
	const int n = info[0]->Uint32Value();
	const float *x = reinterpret_cast<float*>(info[1].As<v8::Float32Array>()->Buffer()->GetContents().Data());
	const int inc_x = info[2]->Uint32Value();
	info.GetReturnValue().Set(
		v8::Number::New(info.GetIsolate(), cblas_snrm2(n, x, inc_x))
	);
}
