/*simple.c*/
//#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#ifndef KERN_SOH
#define KERN_SOH "\001" //start of header
#endif

#ifndef KERN_INFO
#define KERN_INFO KERN_SOH "6"
#endif

/*called when module is loaded*/
int simple_init(void) {
  printk(KERN_INFO "Loading kernel module\n");
  return 0;
}

/*called when module is unloaded*/
void simple_exit(void) {
  printk(KERN_INFO "Removing kernel module\n");
}

/*register entry points for module*/
module_init(simple_init);
module_exit(simple_exit);


