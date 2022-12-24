#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>


static int __init my_init(void){
        printk("hello, kernel!\n");
        return 0;
}

static void __exit my_exit(void){
        printk("goodbye, kernel!\n");
}

module_init(my_init);
module_exit(my_exit);