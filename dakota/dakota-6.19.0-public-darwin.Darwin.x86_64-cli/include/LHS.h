#ifndef LHS_HEADER_INCLUDED
#define LHS_HEADER_INCLUDED

/* Mangling for Fortran global symbols without underscores. */
#define LHS_GLOBAL(name,NAME) name##_

/* Mangling for Fortran global symbols with underscores. */
#define LHS_GLOBAL_(name,NAME) name##_

/* Mangling for Fortran module symbols without underscores. */
#define LHS_MODULE(mod_name,name, mod_NAME,NAME) __##mod_name##_MOD_##name

/* Mangling for Fortran module symbols with underscores. */
#define LHS_MODULE_(mod_name,name, mod_NAME,NAME) __##mod_name##_MOD_##name

#endif
