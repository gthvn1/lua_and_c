-- script.lua

function lua_compare(a, b)
	--[[
	-- It allows you to provide your own comparaison function without rebuilding
	-- the main binary.
	--]]
	return a == b
end
