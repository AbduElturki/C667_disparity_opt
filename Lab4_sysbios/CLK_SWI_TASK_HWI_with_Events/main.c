
/*
 *  ======== main.c ========
 */
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

#include <xdc/cfg/global.h>



#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Event.h>

Bool finishFlag = FALSE;

/*
 * Task Hook Functions
 */
#define TLSSIZE 32
Int hookId;
Int myHookSetId1, myHookSetId2;

/*
 *  ======== main ========
 */
Void main()
{

    Clock_start(clock1);

    BIOS_start();
}

/*
 *  ======== idl0Fxn ========
 */
Void idl0Fxn()
{
    if (finishFlag) {
        System_printf("Calling BIOS_exit from idl0Fxn\n");


        BIOS_exit(0);
    }
}

/*
 *  ======== swi0Fxn ========
 */
Void swi0Fxn(UArg arg0, UArg arg1)
{	UInt priority;
    System_printf("Running swi0Fxn\n");
    priority= Swi_getPri(swi0) ;
    System_printf("the Priority of SWI0 is   = %d \n",  priority);


}

/*
 *  ======== swi1Fxn ========
 */
Void swi1Fxn(UArg arg0, UArg arg1)
{	UInt priority;
    System_printf("Running swi1Fxn\n");
    priority= Swi_getPri(swi1) ;
    System_printf("the Priority of SWI1 is   = %d \n",  priority);

}

/*
 *  ======== clk0Fxn ========
 */
Void clk0Fxn(UArg arg0)
{




	UInt32 time;
	    // Use the finish variable to display the 10 first call to this function
	    int static finish =0;
	    time = Clock_getTicks();
	    System_printf("System time in clk0Fxn = %lu\n", (ULong)time);

	    // you have to use the "BIOS_exit(0)" in order to display the System_printf in the console
	    if (finish == 1)    BIOS_exit(0);
	    finish = finish + 1;

}

/*
 *  ======== clk1Fxn ========
 */
Void clk1Fxn(UArg arg0)
{
    System_printf("Running clk1Fxn to finish\n");

}

/*
Void timer0Fxn()
{
    System_printf("Running timer0Fxn\n");
}
*/


/*
 *  ======== task0Fxn ========
 */
Void task0Fxn(UArg arg0, UArg arg1)
{

  UInt all_events;

		            while (1){

		            	        /* wait for (Event_Id_00 & Event_Id_01) */
		            	        all_events = Event_pend(event0,
		            	            Event_Id_00 + Event_Id_01,  /* andMask */
		            	            NULL,                       /* orMask, not used*/
									BIOS_WAIT_FOREVER);


		            	        System_printf("task0 unblocked and all events occurred\n");
	           	            }


}

/*
 *  ======== task1Fxn ========
 */
Void task1Fxn(UArg arg0, UArg arg1)
{
	System_printf("entering task1 epilog and the semaphore0 is   = %d \n",  Semaphore_getCount(semaphore0));

	 if (Semaphore_getCount(semaphore0) == 0) {
	            System_printf("semaphore0 blocked in task1\n");
	                                          }

	            while (1){

	            	Semaphore_pend(semaphore0,  BIOS_WAIT_FOREVER );
	            	System_printf("task1 released\n");

           	            }


	 System_printf("task1 unblocked\n");


}


/*
 *  ======== task0Fxn ========
 */
Void task2Fxn(UArg arg0, UArg arg1)
{
	System_printf("entering task2 epilog and the semaphore0 is   = %d \n",  Semaphore_getCount(semaphore0));

		 if (Semaphore_getCount(semaphore0) == 0) {
		            System_printf("semaphore0 blocked in task2\n");
		                                          }

		            while (1){

		            	Semaphore_pend(semaphore0,  BIOS_WAIT_FOREVER );

		            	System_printf("task2 released\n");

	           	            }




	   System_printf("in task1 and semaphore released\n");

}

Void myHWI(UArg arg0, UArg arg1) {
	int EventId;

	System_printf("I am processing myHWI \n");
	Semaphore_post(semaphore0);

	Event_post(event0, Event_Id_00);

//	Event_post(event0, Event_Id_01);


	System_printf("the semaphore0 is   = %d \n",  Semaphore_getCount(semaphore0));

	EventId= Hwi_getEventId(5);  // You must add this: #include <ti/sysbios/family/c64p/Hwi.h>
	// as it is not supported by the C66
	System_printf("the EventId is   = %d \n",  EventId);

}


/*
 *  ======== timer0Fxn ========
 */

/*Void timer0Fxn()
{
   System_printf("timer0Fxn\n");
   finishFlag = TRUE;

}*/






/******************************* Hook Functions *****************/


/*
 * ======== myRegisterFxn ========
 * This function is called at boot time.
 */
Void myRegister1_Task(Int id)
{

	 System_printf("This is Task I am in myRegister1_Task before reaching main\n");
 hookId = id;
}


/*
 * ======== myCreateFxn ========
 */
Void myCreateFxn(Task_Handle task, Error_Block *eb)
{
 Ptr tls;
 System_printf("myCreateFxn: task = 0x%x\n", task);

 Error_init(eb);
 tls = Memory_alloc(NULL, TLSSIZE, 0, eb);
 Task_setHookContext(task, hookId, tls);
}


Void myDeleteFxn(Task_Handle task)
{
 Ptr tls;
 System_printf("myDeleteFxn: task = 0x%x\n", task);
 tls = Task_getHookContext(task, hookId);
 Memory_free(NULL, tls, TLSSIZE);
}



//Void mySwitchFxn(task0Fxn, task1Fxn)
Void mySwitchFxn(task0Fxn, task2Fxn)
{
 System_printf("mySwitchFxn: between task0 to task1\n\n");
}


/* HWI HOOK functions setup*/

/* ======== myRegister1 ========
* invoked during Hwi module startup before main()
* for each HookSet */
Void myRegister1_HWI(Int hookSetId)
{
System_printf("This is the HWI myRegister1_HWI  before reaching main: assigned hookSet Id = %d\n",
hookSetId);
//myHookSetId1 = hookSetId;
}



/* HWI Hook functions setup*/

/* ======== myRegister2 ========
* invoked during Hwi module startup before main()
* for each HookSet */
Void myRegister2_HWI(Int hookSetId)
{
System_printf("This is the HWI myRegister2_HWI  before reaching main: assigned hookSet Id = %d\n",
hookSetId);
//myHookSetId1 = hookSetId;
}


/* ======== myBegin1 ========
* invoked before Timer Hwi func */
Void myBegin1(Hwi_Handle myHWI)
{

System_printf("myBegin1:\n");

}


/* ======== myEnd1 ========
* invoked after Timer Hwi func */
Void myEnd1(Hwi_Handle myHWI)
{

System_printf("myEnd1\n");

}

/* SWI Hook Functions setup*
 *
 */
