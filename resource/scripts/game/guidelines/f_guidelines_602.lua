--[[--
    新手指引
  	 主场景 指向排兵布阵
    步骤
--]]--

local f_guidelines_602 = class("f_guidelines_602")
f_guidelines_602.__index = f_guidelines_602

-------------------------------------------------
-- @function [parent=#f_guidelines_602] ctor
-------------------------------------------------
function f_guidelines_602:ctor()	
	self.m_guidelines_manager = nil
	
	self.m_time = 0
	self.m_finish = false
	
	self.STATE_INIT			= 1
	self.STATE_CHECK		= 2
	self.STATE_FINISH		= 4
	self.STATE_EXIT			= 5
	
	self.m_state_function_array = {}
	
	local state_init = function(dt)
		self:state_Init(dt)
	end
	self.m_state_function_array[self.STATE_INIT] = state_init
	
	local state_check = function(dt)
		self:state_Check(dt)
	end
	self.m_state_function_array[self.STATE_CHECK] = state_check
	
	local state_finish = function(dt)
		self:state_Finish(dt)
	end
	self.m_state_function_array[self.STATE_FINISH] = state_finish
	
	local state_exit = function(dt)
		self:state_Exit(dt)
	end
	self.m_state_function_array[self.STATE_EXIT] = state_exit
	
	self.m_current_state	= self.STATE_INIT
	
	self.guidelinesPanel = nil
	
end

-------------------------------------------------------------------------------
-- @function [parent=#f_guidelines_602] setGuidelinesManager
-- 设置新手指引管理
-------------------------------------------------------------------------------
function f_guidelines_602:setGuidelinesManager(manager)	
	self.m_guidelines_manager = manager
end

-------------------------------------------------------------------------------
-- @function [parent=#f_guidelines_602] update
-- 新手指引更新函数
-------------------------------------------------------------------------------
function f_guidelines_602:update(dt)	
	self.m_time = self.m_time + dt
	
	self.m_state_function_array[self.m_current_state](dt)
end

-------------------------------------------------------------------------------
-- @function [parent=#f_guidelines_602] state_Init
-- 初始化当前状态
-------------------------------------------------------------------------------
function f_guidelines_602:state_Init(dt)
	if g_game.g_current_scene_type == g_game.SCENE_TYPE_GAME then
		local stencilPanel = self.m_guidelines_manager:getComponent()
		stencilPanel:enableAllStencil(true)
		stencilPanel:scaleFullScreen(false)		
		stencilPanel:enableStencil(true)
		
		local buzhenBtn = g_game.g_director:getRunningScene().m_layout_manager.layout_right_center.m_componentTable["button_buzhen"]
		
		if buzhenBtn then
			local posx, posy = buzhenBtn:getPosition()
			local pos = buzhenBtn:getParent():convertToWorldSpace(cc.p(posx, posy))			
			stencilPanel:setRectType(pos, buzhenBtn:getSize(), false, false)
		
			local guidelinesBtn = fc.FScaleButton:create()
		    guidelinesBtn:setSize(cc.size(82,82))
		    guidelinesBtn:setAnchorPoint(cc.p(0.5,0.5))
		    guidelinesBtn:setButtonImage("batch_ui/gongnenganniu_up.png")
		    guidelinesBtn:setIconImage("batch_ui/buzhen_anniu.png",cc.p(41,41))
			
			stencilPanel:showIndicateComponent(guidelinesBtn, pos, buzhenBtn:getSize())
			stencilPanel:showIndicateAnimation(pos, buzhenBtn:getSize())
			
			self.guidelinesPanel = f_guidelines_text_show_panel.static_create()
			self.guidelinesPanel:panelInitBeforePopup()		
			stencilPanel:appendComponent(self.guidelinesPanel)
			self.guidelinesPanel:setComponentZOrder(100)
			local sizeT = self.guidelinesPanel:getSize()
			self.guidelinesPanel:setAnchorPoint(cc.p(0.5, 0.5))
			local stencilSize = stencilPanel:getStencilSize() 
			self.guidelinesPanel:setPositionInContainer(cc.p(stencilSize.width/2, stencilSize.height/2))
			self.guidelinesPanel:setSwallowsTouches(false)
			self.guidelinesPanel:showText(self.m_guidelines_manager:getGuidelinesText(602))
			self.guidelinesPanel:setGuidlinesPersonImage(self.m_guidelines_manager:getGuidelinesPerson(602), false)
			
			self.m_current_state = self.STATE_CHECK
			self.m_time = 0
			
			--注册监听函数
			self.event_openbuzhen = function()
				if self.m_current_state == self.STATE_CHECK then
					self.m_current_state = self.STATE_FINISH
				end
			end
			g_game.g_eventManager:registerLuaEvent(g_game.g_f_lua_game_event.F_LUA_SECOND_GUIDELINES_OPEN_BZ, self.event_openbuzhen)

		end
	
	end
end

-------------------------------------------------------------------------------
-- @function [parent=#f_guidelines_602] state_Check
-- 检查是否点击了金銮殿按钮
-------------------------------------------------------------------------------
function f_guidelines_602:state_Check(dt)	
end

-------------------------------------------------------------------------------
-- @function [parent=#f_guidelines_602] state_Finish
-- 结束当前步骤指引
-------------------------------------------------------------------------------
function f_guidelines_602:state_Finish(dt)	
	self.m_current_state = self.STATE_EXIT
	
	g_game.g_eventManager:removeLuaEventFunction(g_game.g_f_lua_game_event.F_LUA_SECOND_GUIDELINES_OPEN_BZ, self.event_openbuzhen)
	
	local stencilPanel = self.m_guidelines_manager:getComponent()
	stencilPanel:setRectType(cc.p(0,0), cc.size(0,0), true, false)
	stencilPanel:hideIndicateAnimation()
	stencilPanel:hideIndicateComponent()
		
	if self.guidelinesPanel then
		stencilPanel:deleteComponent(self.guidelinesPanel)
		self.guidelinesPanel = nil
	end
end

-------------------------------------------------------------------------------
-- @function [parent=#f_guidelines_602] state_Exit
-- 退出当前步骤指引
-------------------------------------------------------------------------------
function f_guidelines_602:state_Exit(dt)	
	self.m_finish = true
end

-------------------------------------------------------------------------------
-- @function [parent=#f_guidelines_602] guidelinesFinish
-- 判断当前指引是否结束
-------------------------------------------------------------------------------
function f_guidelines_602:guidelinesFinish()	
	return self.m_finish
end

-------------------------------------------------------------------------------
-- @function [parent=#f_guidelines_602] guidelinesNextIndex
-- 获取下一步指引index
-------------------------------------------------------------------------------
function f_guidelines_602:guidelinesNextIndex()	
	return 3
end

return f_guidelines_602