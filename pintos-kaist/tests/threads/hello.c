#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"


void
hello_world (void) 
{
  msg ("hello, world.");
}
