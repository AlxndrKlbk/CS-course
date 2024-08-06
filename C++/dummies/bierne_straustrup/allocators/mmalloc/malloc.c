/* Include the sbrk function */

#include <unistd.h>     // main POSIX API header 

int has_initialized = 0;
void *managed_memory_start;
void *last_valid_address;

void malloc_init()
{ 
 /* grab the last valid address from the OS */  
 last_valid_address = sbrk(0);      // return void* to  new memory area, inremented by n bytes sbrk(n)     

 /* we don't have any memory to manage yet, so 
  *just set the beginning to be last_valid_address 
  */  
 managed_memory_start = last_valid_address;     

 /* Okay, we're initialized and ready to go */
  has_initialized = 1;   
}

struct mem_control_block {
 int is_available;
 int size;
};

void free(void *firstbyte) {
 struct mem_control_block *mcb;

 /* Backup from the given pointer to find the
  * mem_control_block
  */
 mcb = firstbyte - sizeof(struct mem_control_block);
 /* Mark the block as being available */
 mcb->is_available = 1;
 /* That's It!  We're done. */
 return;
}

void *mmalloc(long numbytes) {
 /* Holds where we are looking in memory */
 void *current_location;

 /* This is the same as current_location, but cast to a
  * memory_control_block
  */
 struct mem_control_block *current_location_mcb;

 /* This is the memory location we will return.  It will
  * be set to 0 until we find something suitable
  */
 void *memory_location;

 /* Initialize if we haven't already done so */
 if(! has_initialized)  {
  malloc_init();
 }

 /* The memory we search for has to include the memory
  * control block, but the user of malloc doesn't need
  * to know this, so we'll just add it in for them.
  */
 numbytes = numbytes + sizeof(struct mem_control_block);

 /* Set memory_location to 0 until we find a suitable
  * location
  */
 memory_location = 0;

 /* Begin searching at the start of managed memory */
 current_location = managed_memory_start;

 /* Keep going until we have searched all allocated space */
 while(current_location != last_valid_address)
 { 
  /* current_location and current_location_mcb point
   * to the same address.  However, current_location_mcb
   * is of the correct type so we can use it as a struct.
   * current_location is a void pointer so we can use it
   * to calculate addresses.
   */
  current_location_mcb =
   (struct mem_control_block *)current_location;

  if(current_location_mcb->is_available)
  {
   if(current_location_mcb->size >= numbytes)
   {
    /* Woohoo!  We've found an open,
     * appropriately-size location.
     */

    /* It is no longer available */
    current_location_mcb->is_available = 0;

    /* We own it */
    memory_location = current_location;

    /* Leave the loop */
    break;
   }
  }

  /* If we made it here, it's because the Current memory
   * block not suitable, move to the next one
   */
  current_location = current_location +
   current_location_mcb->size;
 }

 /* If we still don't have a valid location, we'll
  * have to ask the operating system for more memory
  */
 if(! memory_location)
 {
  /* Move the program break numbytes further */
  sbrk(numbytes);

  /* The new memory will be where the last valid 
   * address left off 
   */
  memory_location = last_valid_address;

  /* We'll move the last valid address forward 
   * numbytes 
   */
  last_valid_address = last_valid_address + numbytes;

  /* We need to initialize the mem_control_block */
  current_location_mcb = memory_location;
  current_location_mcb->is_available = 0;
  current_location_mcb->size = numbytes;
 }

 /* Now, no matter what (well, except for error conditions),
  * memory_location has the address of the memory, including
  * the mem_control_block
  */

 /* Move the pointer past the mem_control_block */
 memory_location = memory_location + sizeof(struct mem_control_block);

 /* Return the pointer */
 return memory_location;
 }

