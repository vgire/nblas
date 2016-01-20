#include "cblas.h"
#include "decl.h"

NAN_METHOD(dtrmm) {
	const enum CBLAS_SIDE side = static_cast<CBLAS_SIDE>(info[0]->Uint32Value());
	const enum CBLAS_UPLO uplo = static_cast<CBLAS_UPLO>(info[1]->Uint32Value());
	const enum CBLAS_TRANSPOSE transa = static_cast<CBLAS_TRANSPOSE>(info[2]->Uint32Value());
	const enum CBLAS_DIAG diag = static_cast<CBLAS_DIAG>(info[3]->Uint32Value());
	const int m = info[4]->Uint32Value();
	const int n = info[5]->Uint32Value();
	const double alpha = info[6]->NumberValue();
	const double *a = reinterpret_cast<double*>(info[7].As<v8::Float64Array>()->Buffer()->GetContents().Data());
	const int lda = info[8]->Uint32Value();
	double *b = reinterpret_cast<double*>(info[9].As<v8::Float64Array>()->Buffer()->GetContents().Data());
	const int ldb = info[10]->Uint32Value();
	cblas_dtrmm(CblasRowMajor, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
}

NAN_METHOD(strmm) {
	const enum CBLAS_SIDE side = static_cast<CBLAS_SIDE>(info[0]->Uint32Value());
	const enum CBLAS_UPLO uplo = static_cast<CBLAS_UPLO>(info[1]->Uint32Value());
	const enum CBLAS_TRANSPOSE transa = static_cast<CBLAS_TRANSPOSE>(info[2]->Uint32Value());
	const enum CBLAS_DIAG diag = static_cast<CBLAS_DIAG>(info[3]->Uint32Value());
	const int m = info[4]->Uint32Value();
	const int n = info[5]->Uint32Value();
	const float alpha = info[6]->NumberValue();
	const float *a = reinterpret_cast<float*>(info[7].As<v8::Float32Array>()->Buffer()->GetContents().Data());
	const int lda = info[8]->Uint32Value();
	float *b = reinterpret_cast<float*>(info[9].As<v8::Float32Array>()->Buffer()->GetContents().Data());
	const int ldb = info[10]->Uint32Value();
	cblas_strmm(CblasRowMajor, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
}
