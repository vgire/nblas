#include "cblas.h"
#include "decl.h"

NAN_METHOD(dsymm) {
	const enum CBLAS_SIDE side = static_cast<CBLAS_SIDE>(info[0]->Uint32Value());
	const enum CBLAS_UPLO uplo = static_cast<CBLAS_UPLO>(info[1]->Uint32Value());
	const int m = info[2]->Uint32Value();
	const int n = info[3]->Uint32Value();
	const double alpha = info[4]->NumberValue();
	const double *a = reinterpret_cast<double*>(info[5].As<v8::Float64Array>()->Buffer()->GetContents().Data());
	const int lda = info[6]->Uint32Value();
	const double *b = reinterpret_cast<double*>(info[7].As<v8::Float64Array>()->Buffer()->GetContents().Data());
	const int ldb = info[8]->Uint32Value();
	const double beta = info[9]->NumberValue();
	double *c = reinterpret_cast<double*>(info[10].As<v8::Float64Array>()->Buffer()->GetContents().Data());
	const int ldc = info[11]->Uint32Value();
	cblas_dsymm(CblasRowMajor, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
}

NAN_METHOD(ssymm) {
	const enum CBLAS_SIDE side = static_cast<CBLAS_SIDE>(info[0]->Uint32Value());
	const enum CBLAS_UPLO uplo = static_cast<CBLAS_UPLO>(info[1]->Uint32Value());
	const int m = info[2]->Uint32Value();
	const int n = info[3]->Uint32Value();
	const float alpha = info[4]->NumberValue();
	const float *a = reinterpret_cast<float*>(info[5].As<v8::Float32Array>()->Buffer()->GetContents().Data());
	const int lda = info[6]->Uint32Value();
	const float *b = reinterpret_cast<float*>(info[7].As<v8::Float32Array>()->Buffer()->GetContents().Data());
	const int ldb = info[8]->Uint32Value();
	const float beta = info[9]->NumberValue();
	float *c = reinterpret_cast<float*>(info[10].As<v8::Float32Array>()->Buffer()->GetContents().Data());
	const int ldc = info[11]->Uint32Value();
	cblas_ssymm(CblasRowMajor, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
}
