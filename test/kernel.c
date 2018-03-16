#include <OpenCL/opencl.h>
#include <stdio.h>
#include <stdlib.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct	s_cl
{
	cl_device_id 					device_id;
	cl_uint							ret_num_devices;
	cl_context						context;
	cl_command_queue				command_queue;
	cl_program						program;
	cl_kernel						kernel;
	cl_mem 							buffer;
	char							*data;
}				t_cl;

void        ft_cl_init(t_cl *cl)
{
	int	max;
	/* получить доступные устройства */
	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_CPU, 1, &(cl->device_id), &(cl->ret_num_devices));
	/* создать контекст */
	cl->context = clCreateContext(NULL, 1, &(cl->device_id), NULL, NULL, NULL);
	/* создаем команду */
	cl->command_queue = clCreateCommandQueue(cl->context, cl->device_id, 0, NULL);
}

void		ft_kernel_create(t_cl *cl, char *source_str)
{
	/* создать бинарник из кода программы */
	cl->program = clCreateProgramWithSource(cl->context, 1, (const char **)&source_str, NULL, NULL);
	/*скомпилировать программу*/
	clBuildProgram(cl->program, 1, &(cl->device_id), NULL, NULL, NULL);
	/* создать кернел */
	cl->kernel = clCreateKernel(cl->program, "test", NULL);
}

void		ft_kernel_exec(t_cl cl)
{
	clSetKernelArg(cl.kernel, 0, sizeof(cl.buffer), &(cl.buffer));
	size_t global_dim[] = {5, 0, 0};
	clEnqueueNDRangeKernel(cl.command_queue, cl.kernel, 1, NULL, global_dim, NULL, 0, NULL, NULL);
}

int		main(void)
{
	t_cl	cl;
	char *source_str = {
	"__kernel void test(__global char *data){\n"
	"	data[0] = 'H';\n"
	"	data[1] = 'e';\n"
	"	data[2] = 'l';\n"
	"	data[3] = 'l';\n"
	"	data[4] = 'o';\n"
	"}\n"
	};

	cl.data = (char *)malloc(sizeof(char) * 6);
	ft_cl_init(&cl);
	ft_kernel_create(&cl, source_str);
	cl.buffer = clCreateBuffer(cl.context, CL_MEM_READ_WRITE, sizeof(cl.data), NULL, NULL);
	clEnqueueWriteBuffer(cl.command_queue, cl.buffer, CL_TRUE, 0, sizeof(cl.data), cl.data, 0, NULL, NULL);
	ft_kernel_exec(cl);
	clEnqueueReadBuffer(cl.command_queue, cl.buffer, CL_TRUE, 0, sizeof(cl.data), cl.data, 0, NULL, NULL);
	clFinish(cl.command_queue);
	printf("%s\n", cl.data);
}