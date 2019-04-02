/*
 *  ======== static.c ========
 *  The static example focuses on SYS/BIOS configuration. It shows how to
 *  - Use and configure various modules.
 *  - Create static Instances.
 *  - Modify Program level configuration parameters.
 */

#include <xdc/std.h>
#include <xdc/runtime/System.h>

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
 //   Swi_post(swi0);
 //   Swi_post(swi1);
 //   Clock_start(clk1);
    
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
