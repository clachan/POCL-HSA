/* OpenCL runtime library: clReleaseEvent()

   Copyright (c) 2012 Pekka Jääskeläinen / Tampere University of Technology
   
   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:
   
   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.
   
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

#include "pocl_cl.h"

CL_API_ENTRY cl_int CL_API_CALL
POname(clReleaseEvent)(cl_event event) CL_API_SUFFIX__VERSION_1_0
{
  int new_refcount;
  if (event == NULL || event->queue == NULL)
    return CL_INVALID_EVENT;

  POCL_RELEASE_OBJECT (event, new_refcount);

  if (new_refcount == 0)
    {
#ifdef HSA_RUNTIME
	  if(!(event->queue->device->type&CL_DEVICE_TYPE_GPU))
#endif
	  POname(clReleaseCommandQueue) (event->queue);

      free (event);
    }

  return CL_SUCCESS;
}
POsym(clReleaseEvent)
