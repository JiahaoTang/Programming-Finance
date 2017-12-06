#include<yvals.h>
#if(_MSC_VER>=1600)
#define _STDC_utf_16__
#endif
#include"mex.h"
#include<engine.h>
#include<iostream>


#pragma comment(lib,"libmx.lib")
#pragma comment(lib,"libmex.lib")
#pragma comment(lib,"libeng.lib")

using namespace std;

int main()
{
	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL)
	{
		cout << "ERROR:engine open failed" << endl;
		exit(1);
	}
	int size1 = 100;
	double *step = new double[size1];
	int size2 = 100;
	double *value = new double[size2];
	for (int i = 0; i < 100; i++)
	{
		step[i] = i;
		value[i] = sin(i);
	}

	mxArray *A;
	A = mxCreateDoubleMatrix(1, 100, mxREAL);
	memcpy((void*)mxGetPr(A), (void *)step, sizeof(double) * 100);
	mxArray *B;
	B = mxCreateDoubleMatrix(1, 100, mxREAL);
	memcpy((void*)mxGetPr(B), (void *)value, sizeof(double) * 100);

	engPutVariable(ep, "x", A);
	engPutVariable(ep, "y", B);
	engEvalString(ep, "plot(x,y)");

	system("pause");

	mxDestroyArray(A);
	engEvalString(ep, "close;");

	engClose(ep);

	return 0;
}