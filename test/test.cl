#include <OpenCL/opencl.h>

__kernel void test(__global char *data)
{
	data[0] = 'H';
	data[1] = 'e';
	data[2] = 'l';
	data[3] = 'l';
	data[4] = 'o';
	data[5] = '\n';
}