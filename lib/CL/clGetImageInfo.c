#include "pocl_cl.h"

CL_API_ENTRY cl_int CL_API_CALL
POname(clGetImageInfo)(cl_mem            image ,
               cl_image_info     param_name , 
               size_t            param_value_size ,
               void *            param_value ,
               size_t *          param_value_size_ret ) CL_API_SUFFIX__VERSION_1_0
{
  POCL_ABORT_UNIMPLEMENTED("clGetImageInfo is not implemented.");
  return CL_SUCCESS;
}
POsym(clGetImageInfo)
