
MSHookFunction((void*)&Common::getGameVersionString, (void*)&Common_getGameVersionString_hook, (void**)&Common_getGameVersionString_real);