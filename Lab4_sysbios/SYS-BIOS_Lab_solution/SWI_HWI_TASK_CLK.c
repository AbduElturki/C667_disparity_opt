/*
 *  ======== static.c ========
 *  The static example focuses on SYS/BIOS configuration. It shows how to
 *  - Use and configure various modules.
 *  - Create static Instances.
 *  - Modify Program level configuration parameters.
 */

#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/family/c64p/Hwi.h> // added this line to use  EventId= Hwi_getEventId(5);

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/knl/Semaphore.h>

#include <xdc/cfg/global.h>

Bool finishFlag = FALSE;

/*
 *  ======== main ========
 */
Void main()
{ 
    Swi_post(swi0);
    Swi_post(swi1);
    Clock_start(clk1);
    
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
    System_printf("Running clk0Fxn\n");  
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
    System_printf("Running task0Fxn and setting sem0 =0\n");
    Semaphore_reset(sem0, 0);
}

/*
 *  ======== task1Fxn ========
 */
Void task1Fxn(UArg arg0, UArg arg1)
{
	System_printf("in task 1 and the semaphore0 is   = %d \n",  Semaphore_getCount(sem0));

	 if (Semaphore_getCount(sem0) == 0) {
	            System_printf("Sem0 blocked in task1\n");
	        }



Semaphore_pend(sem0, BIOS_WAIT_FOREVER);

   System_printf("in task1 and semaphore released\n");
}


Void myHWI(UArg arg0, UArg arg1)
{int EventId;
   System_printf("Running myHWI and posting sem0 \n");

   Semaphore_post(sem0);
  EventId= Hwi_getEventId(5);  // You must add this: #include <ti/sysbios/family/c64p/Hwi.h>
  	  	  	  	  	  	  	   // as it is not supported by the C66
  System_printf("the EventId is   = %d \n",  EventId);

}


/*
 *  ======== timer0Fxn ========
 */

Void timer0Fxn()
{
   System_printf("timer0Fxn\n");
   finishFlag = TRUE;

}




