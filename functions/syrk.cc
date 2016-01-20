#include "cblas.h"
#include "decl.h"

NAN_METHOD(dsyrk) {
	const enum CBLAS_UPLO uplo = static_cast<CBLAS_UPLO>(info[0]->Uint32Value());
	const enum CBLAS_TRANSPOSE trans = static_cast<CBLAS_TRANSPOSE>(info[1]->Uint32Value());
	const int n = info[2]->Uint32Value();
	const int k = info[3]->Uint32Value();
	const double alpha = info[4]->NumberValue();
	const double *a = reinterpret_cast<double*>(info[5].As<v8::Float64Array>()->Buffer()->GetContents().Data());
	const int lda = info[6]->Uint32Value();
	const double beta = info[7]->NumberValue();
	double *c = reinterpret_cast<double*>(info[8].As<v8::Float64Array>()->Buffer()->GetContents().Data());
	const int ldc = info[9]->Uint32Value();
	cblas_dsyrk(CblasRowMajor, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
}

NAN_METHOD(ssyrk) {
	const enum CBLAS_UPLO uplo = static_cast<CBLAS_UPLO>(info[0]->Uint32Value());
	const enum CBLAS_TRANSPOSE trans = static_cast<CBLAS_TRANSPOSE>(info[1]->Uint32Value());
	const int n = info[2]->Uint32Value();
	const int k = info[3]->Uint32Value();
	const float alpha = info[4]->NumberValue();
	const float *a = reinterpret_cast<float*>(info[5].As<v8::Float32Array>()->Buffer()->GetContents().Data());
	const int lda = info[6]->Uint32Value();
	const float beta = info[7]->NumberValue();
	float *c = reinterpret_cast<float*>(info[8].As<v8::Float32Array>()->Buffer()->GetContents().Data());
	const int ldc = info[9]->Uint32Value();
	cblas_ssyrk(CblasRowMajor, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
}
