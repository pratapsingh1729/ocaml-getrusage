(** The type wrapping `struct timeval` from Unix. *)
type timeval = 
  { tv_sec      : int     ;
    tv_usec     : int     }

(** The type wrapping `struct rusage` from Unix. *)
type rusage = 
  { ru_utime    : timeval ;
    ru_stime    : timeval ;
    ru_maxrss   : int     ;
    ru_ixrss    : int     ;
    ru_idrss    : int     ;
    ru_isrss    : int     ;
    ru_minflt   : int     ;
    ru_majflt   : int     ;
    ru_nswap    : int     ;
    ru_inblock  : int     ;   
    ru_oublock  : int     ;
    ru_msgsnd   : int     ;
    ru_msgrcv   : int     ;
    ru_nsignals : int     ;
    ru_nvcsw    : int     ;
    ru_nivcsw   : int     }

val getrusage : unit -> rusage 
(** `getrusage ()` returns an `rusage` record containing 
    the results of the Unix system call `getrusage()`. 
    Run `man getrusage` in a terminal to determine the
    units used on your system. *)