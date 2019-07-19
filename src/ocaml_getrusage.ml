type timeval = {tv_sec : int; tv_usec : int}

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


external getrusage : unit -> rusage = "caml_getrusage_wrapper"

