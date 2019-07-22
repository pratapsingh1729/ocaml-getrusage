#define CAML_NAME_SPACE
#include <sys/time.h>
#include <sys/resource.h>
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>


value caml_getrusage_wrapper(value unit)
{
  CAMLparam1(unit);
  CAMLlocal3(caml_ru_utime, caml_ru_stime, caml_ru);

  caml_ru_utime = caml_alloc(2, 0);
  caml_ru_stime = caml_alloc(2, 0);
  caml_ru = caml_alloc(16, 0);
  
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);

  // fill caml_ru_utime
  Store_field(caml_ru_utime, 0, Val_long(usage.ru_utime.tv_sec));
  Store_field(caml_ru_utime, 1, Val_long(usage.ru_utime.tv_usec));

  // fill caml_ru_stime
  Store_field(caml_ru_stime, 0, Val_long(usage.ru_stime.tv_sec));
  Store_field(caml_ru_stime, 1, Val_long(usage.ru_stime.tv_usec));

  // fill caml_ru
  Store_field(caml_ru, 0, caml_ru_utime);
  Store_field(caml_ru, 1, caml_ru_stime);
  Store_field(caml_ru, 2, Val_long(usage.ru_maxrss));
  Store_field(caml_ru, 3, Val_long(usage.ru_ixrss));
  Store_field(caml_ru, 4, Val_long(usage.ru_idrss));
  Store_field(caml_ru, 5, Val_long(usage.ru_isrss));
  Store_field(caml_ru, 6, Val_long(usage.ru_minflt));
  Store_field(caml_ru, 7, Val_long(usage.ru_majflt));
  Store_field(caml_ru, 8, Val_long(usage.ru_nswap));
  Store_field(caml_ru, 9, Val_long(usage.ru_inblock));
  Store_field(caml_ru,10, Val_long(usage.ru_oublock));
  Store_field(caml_ru,11, Val_long(usage.ru_msgsnd));
  Store_field(caml_ru,12, Val_long(usage.ru_msgrcv));
  Store_field(caml_ru,13, Val_long(usage.ru_nsignals));
  Store_field(caml_ru,14, Val_long(usage.ru_nvcsw));
  Store_field(caml_ru,15, Val_long(usage.ru_nivcsw));

  CAMLreturn(caml_ru);
}



