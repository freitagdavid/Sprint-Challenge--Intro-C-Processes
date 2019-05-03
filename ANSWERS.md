**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Running: Process is running or ready to.
Waiting: Process is waiting for an event or a resource.
Stopped: Either it has been stopped by a call or it reached the end of it's execution without an exit code.
Zombie: Process that has exited with an exit code.

**2. What is a zombie process?**

It's a process that has completed with an exit code but the system still stores some data from it until the parent no longer needs it.

**3. How does a zombie process get created? How does one get destroyed?**

It gets created when the process completes and exits properly. It then gets destroyed in a couple of way either by a SIGCHLD signal or by just straight out killing it. If the parent process dies the zombie gets reassigned to the system init process which periodically kills it's child zombie processes.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Number 1 is that the compiler does a lot of optimization for you in general a compiler can optimize way better than a human ever could.
Generally natively compiled languages tend to be lighter on resources. And I mean natively compiled not something like java that runs in a vm.
It also generally lets you get closer to the metal though there are similar mechanisms in for example Python it takes a lot more work to get to the lower levels of the system.