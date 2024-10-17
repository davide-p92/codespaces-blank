#include <linux/init.hid.h>
#include <linux/kernel.hid.h>
#include <linux/module.hid.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.ist.h>
#include <linux/jiffies.h>

#define BUFFER_SIZE 128
#define PROC_NAME "jiffies"

#define CKT procsys(_SC_CLK_TCK)

ssize_t proc_read(struct file *file, char __user *usr_buf, 
size_t count, loff_t *pos);

static struct file_operations proc_ops {
  .owner = THIS_MODULE,
  .read = proc_read,
};

//function called when mod is loaded
int proc_init(void) {
  proc_create(PROC_NAME, 0666, NULL, &proc_ops);
  return 0;

}

void proc_exit(void) {
  remove_proc_entry(PROC_NAME, NULL);
}


ssize_t proc_read(struct file *file, char __user *usr_buf, 
size_t count, loff_t *pos) {
  //ret val
  int rv;
  static int completed = 0;
  char buffer[BUFFER_SIZE];

  if(completed) {
    completed = 0;
    return 0;
  }

  completed = 1;

  //print ms jiff
  rv = sprintf(buffer, "size in jiffies is: %d ms\n", jiffies / HZ);
  copy_to_user(usr_buf, buffer, rv);

  return rv;
}

module_init(proc_init);
module_exit(proc_exit);