/*
 *  ======== main.c ========
 */
#include <xdc/cfg/global.h>
#include <xdc/std.h>
#include <xdc/runtime/Log.h> 		 // use this for the Log_info
#include <xdc/runtime/System.h> 	 // use this for printf
#include <ti/uia/events/UIABenchmark.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>


#include <ti/sysbios/family/c64p/Hwi.h> // added this line to use  EventId= Hwi_getEventId(5);

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/knl/Semaphore.h>





#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Task.h>

/* memory*/

#include <xdc/std.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
/*
 *  ======== main.c ========
 */
#include <xdc/std.h>
#include <xdc/runtime/Log.h>

Ptr buf1, buf2, buf3, buf4, buf5, buf6, buf7, buf8, buf9;
Error_Block eb;
//Error_init(&eb);

Int main(Void)
{
	Log_info0("Hello World!");
	System_printf("in main\n");
	Semaphore_post(semaphore0);

	// return (0);

	BIOS_start();
}

/*
 *  ======== task0Fxn ========
 */
Void task0Fxn(UArg arg0, UArg arg1)
{
	System_printf("entering task0 epilog and the semaphore0 is   = %d \n",
			Semaphore_getCount(semaphore0));

	if (Semaphore_getCount(semaphore0) == 0) {
		System_printf("semaphore0 blocked in task0\n");
	                                          }

	while (1) {

		Semaphore_pend(semaphore0, BIOS_WAIT_FOREVER); // wait here for the semaphore

		/* start process from from here when the semaphore is available*/
		System_printf("task0 unblocked\n");

		/* Alloc and free using the default Heap */
		buf1 = Memory_alloc(NULL, 128, 0, &eb);
		if (buf1 == NULL) {
			System_abort("Memory allocation for buf1 failed");
		}

		/*Alloc using another heap: with heapMem Implementation)  */
		buf2 = Memory_alloc(heapMem0, 128, 0, &eb);

		if (buf2 == NULL) {
			System_abort("Memory allocation for buf2 failed");
		}

		/*Alloc using another heap: with HeapBuf implementation)  */
		buf3 = Memory_alloc(myHeapbuf, 128, 0, &eb);

		if (buf3 == NULL) {
			System_abort("Memory allocation for buf3 failed");
		}

		/*Alloc using another heap: with HeapBuf implementation)  */
		buf4 = Memory_alloc(myHeapbuf, 128, 0, &eb);

		if (buf4 == NULL) {
			System_abort("Memory allocation for buf4 failed");
		}

		/*Alloc using another heap: with HeapMultiBuf implementation)  */

		buf5 = Memory_alloc(myHeap, 16, 0, &eb);
		if (buf5 == NULL) {
					System_abort("Memory allocation for buf5 failed");
				}
		buf6 = Memory_alloc(myHeap, 16, 0, &eb);
		if (buf6 == NULL) {
					System_abort("Memory allocation for buf6 failed");
				}
	/*	buf5 = Memory_alloc(myHeap, 16, 0, &eb);
		if (buf5 == NULL) {
					System_abort("Memory allocation for buf5 failed");
				}*/
		buf7 = Memory_alloc(myHeap, 128, 0, &eb);

		if (buf7 == NULL) {
					System_abort("Memory allocation for buf7 failed");
				}

		buf8 = Memory_alloc(myHeap, 32, 0, &eb);

		if (buf8 == NULL) {
			System_abort("Memory allocation for buf8 failed");
		}

		buf9 = Memory_alloc(myHeap, 128, 0, &eb);

		if (buf9 == NULL) {
			System_abort("Memory allocation for buf9 failed");
		}

		Memory_free(NULL, buf1, 128);
		Memory_free(heapMem0, buf2, 128);
		Memory_free(myHeapbuf, buf3, 128);
		Memory_free(myHeapbuf, buf4, 128);
		Memory_free(myHeap, buf5, 16);
		Memory_free(myHeap, buf6, 16);
		Memory_free(myHeap, buf7, 128);
		Memory_free(myHeap, buf8, 32);

		System_printf("All allocations succesful");
	}


}

