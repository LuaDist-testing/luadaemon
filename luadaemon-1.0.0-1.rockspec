-- This file was automatically generated for the LuaDist project.

package = "luadaemon"
version = "1.0.0-1"
-- LuaDist source
source = {
  tag = "1.0.0-1",
  url = "git://github.com/LuaDist-testing/luadaemon.git"
}
-- Original source
-- source = {
--    url = "http://lua.net-core.org/dl/telesto/luadaemon-1.0.0.tar.gz",
-- }
description = {
   summary = "Daemonize Lua Applications",
   detailed = [[
     Allows you to daemonize a Lua script/application, drop its uid/gid, ...
   ]],
   license = "MIT/X11",
   homepage = "http://lua.net-core.org/sputnik.lua?p=Telesto:About"
}
dependencies = {
   "lua >= 5.1",
}
build = {
   type = "make",
   build_variables = {
      LDFLAGS = "$(LIBFLAG)",
      LUA_PREFIX = "$(LUA_DIR)"
   },
   install_variables = {
      INSTALL_PREFIX = "$(LIBDIR)"
   }
}