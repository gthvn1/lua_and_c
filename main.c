#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

#define LUA_SCRIPT "compare.lua"

static bool compare(lua_State *L, int a, int b)
{
    bool ret = false;

    // Add the function name to the state
    lua_getglobal(L, "lua_compare");

    if (!lua_isfunction(L, -1)) {
        printf("Failed to load lua_compare function\n");
        lua_pop(L, 1);
    } else {
        lua_pushnumber(L, a);
        lua_pushnumber(L, b);
        lua_call(L, 2, 1);

        ret = lua_toboolean(L, -1);
    }

    return ret;
}

int main(void)
{
    lua_State *L;
    int a, b;

    L = luaL_newstate(); // Start new Lua state
    luaL_openlibs(L);    // Open Standard libs

    if (luaL_dofile(L, LUA_SCRIPT) != 0) {
        printf("Failed to load %s: %s", LUA_SCRIPT, lua_tostring(L, -1));
        return 1;
    }

    a = 2;
    b = 6;
    printf("%d and %d are %s\n", a, b, compare(L, a, b) ? "equal" : "not equal");

    a = 42;
    b = 42;
    printf("%d and %d are %s\n", a, b, compare(L, a, b) ? "equal" : "not equal");

    lua_close(L);

    return 0;
}
