
require("scripts.config")
if DEBUG ~= 0 then
	require("scripts.debugger")(nil, nil, nil)
end
CCLOG=print
CCLuaLog=print
function __G__TRACKBACK__(errorMessage)
    CCLOG("----------------------------------------")
    CCLOG("LUA ERROR: " .. tostring(errorMessage) .. "\n")
    CCLOG(debug.traceback("", 2))
    CCLOG("----------------------------------------")
end

xpcall(function()
    require("scripts.game")
    g_game.startup()
end, __G__TRACKBACK__)
