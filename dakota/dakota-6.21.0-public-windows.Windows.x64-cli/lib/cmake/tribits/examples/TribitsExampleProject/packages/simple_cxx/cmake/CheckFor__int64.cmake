INCLUDE(CheckCXXSourceCompiles)

# This compiler test checks to see if the compiler supports a intrinic
# datatype __int64, such as on some 64 bit Windows compilers.
#
# The below test program checks to see that __int64 is defined, different from
# any existing standard intrinsic 'int' types, except for 'long long int'.
#
FUNCTION(CHECK_FOR___INT64 VARNAME)

  SET(SOURCE
  "
template<typename T> struct MyOrdinalTraits {};

template<> struct MyOrdinalTraits<int> { static inline int zero() { return 0; } };
template<> struct MyOrdinalTraits<long int> { static inline long int zero() { return 0; } };
template<> struct MyOrdinalTraits<__int64> { static inline __int64 zero() { return 0; } };

int main()
{
  MyOrdinalTraits<int>::zero();
  MyOrdinalTraits<long int>::zero();
  MyOrdinalTraits<__int64>::zero();
  return 0;
}
"
  )

  CHECK_CXX_SOURCE_COMPILES("${SOURCE}" ${VARNAME})

ENDFUNCTION()
