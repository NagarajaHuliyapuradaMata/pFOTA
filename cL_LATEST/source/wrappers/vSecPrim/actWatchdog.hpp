

#ifndef ACTWATCHDOG_H
#define ACTWATCHDOG_H

#include "actConfig.hpp"
#include "actUtilities.hpp"

#if(actWD_LEVEL > 0)
#define actTriggerWD(watchdog)                                      actWatchdogTriggerFunction(watchdog)
#define actL1trigger(watchdog)                                      actTriggerWD(watchdog)
#else
#define actTriggerWD(watchdog)                                      VSECPRIM_DUMMY_STATEMENT(watchdog)
#define actL1trigger(watchdog)                                      VSECPRIM_DUMMY_STATEMENT(watchdog)
#endif

#if(actWD_LEVEL > 1)
#define actL2trigger(watchdog)                                      actTriggerWD(watchdog)
#else
#define actL2trigger(watchdog)                                      VSECPRIM_DUMMY_STATEMENT(watchdog)
#endif

#if(actWD_LEVEL > 2)
#define actL3trigger(watchdog)                                      actTriggerWD(watchdog)
#else
#define actL3trigger(watchdog)                                      VSECPRIM_DUMMY_STATEMENT(watchdog)
#endif

#if(actWD_LEVEL >= 1)
#define ifWDisL1(condition, watchdog)                               if((watchdog != NULL_PTR) && (condition)) (*watchdog)()
#else
#define ifWDisL1(condition, watchdog)                               VSECPRIM_DUMMY_STATEMENT(watchdog)
#endif

#if(actWD_LEVEL >= 2)
#define ifWDisL2(condition, watchdog)                               if((watchdog != NULL_PTR) && (condition)) (*watchdog)()
#else
#define ifWDisL2(condition, watchdog)                               VSECPRIM_DUMMY_STATEMENT(watchdog)
#endif

#if(actWD_LEVEL >= 3)
#define ifWDisL3(condition, watchdog)                               if((watchdog != NULL_PTR) && (condition)) (*watchdog)()
#else
#define ifWDisL3(condition, watchdog)                               VSECPRIM_DUMMY_STATEMENT(watchdog)
#endif

#endif

