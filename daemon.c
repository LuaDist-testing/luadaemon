/*
** LuaDaemon
** Copyright DarkGod 2007
**
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

static int ldaemon_daemonize(lua_State *L)
{
	/* daemonize */
	if (fork() != 0)
		exit(0);
	if (setsid() == -1)
	{
		lua_pushliteral(L, "Could not become group leader");
		return 1;
	}

	close(0);
	close(1);
	close(2);

	if (fork() != 0)
		exit(0);


	return 0;
}

/*
** Assumes the table is on top of the stack.
*/
static void set_info (lua_State *L)
{
	lua_pushliteral (L, "_COPYRIGHT");
	lua_pushliteral (L, "Copyright (C) 2007 DarkGod");
	lua_settable (L, -3);
	lua_pushliteral (L, "_DESCRIPTION");
	lua_pushliteral (L, "LuaDaemon allows to create an unix daemon with Lua");
	lua_settable (L, -3);
	lua_pushliteral (L, "_VERSION");
	lua_pushliteral (L, "LuaDaemon 1.0.0");
	lua_settable (L, -3);
}

static const struct luaL_reg ldaemonlib[] =
{
	{"daemonize", ldaemon_daemonize},
	{NULL, NULL},
};

int luaopen_daemon(lua_State *L)
{
	luaL_openlib(L, "daemon", ldaemonlib, 0);

	set_info(L);
	return 1;
}
