#ifndef ACMD_IMPORTS_H
#define ACMD_IMPORTS_H

#include <switch.h>

namespace app::sv_animcmd {
	extern void wait(u64, float) asm("_ZN3app10sv_animcmd4waitEP9lua_Statef") LINKABLE; // delay for a specified # of frames
	extern void frame(u64, float) asm("_ZN3app10sv_animcmd5frameEP9lua_Statef") LINKABLE; // delay until a certain frame of the animation is reached
	extern void is_excute(u64) asm("_ZN3app10sv_animcmd9is_excuteEP9lua_State") LINKABLE;
	
	/**
	 * sets throw paramters
	 * Arguments:
	 * - kind (int) -- FIGHTER_ATTACK_ABSOLUTE_KIND_???
	 * - ID (int) -- lower IDs have priority
	 * - damage (float)
	 * - angle (int)
	 * - knockback growth (int)
	 * - fixed knockback (int)
	 * - base knockback (int)
	 * - hitlag multiplier (float) -- usually 0.0
	 * - ??? (float) -- usually 1.0
	 * - facing restriction (int) -- ATTACK_LR_CHECK_???
	 * - ??? (float) -- usually 1.0
	 * - ??? (boolean) -- usually true
	 * - effect (hash) -- hash40("collision_attr_???")
	 * - SFX level (int) -- ATTACK_SOUND_LEVEL_???
	 * - SFX type (int) -- COLLISION_SOUND_ATTR_???
	 * - move type (int) -- usually ATTACK_REGION_THROW
	 */
	extern u64 ATK_ABS(u64) asm("_ZN3app10sv_animcmd10ATTACK_ABSEP9lua_State") LINKABLE;
	
	/**
	 * throw release
	 * Arguments:
	 * - ??? (int) -- usually FIGHTER_ATTACK_ABSOLUTE_KIND_THROW
	 * - ??? (hash) -- usually hash40("throw")
	 * - ??? (int) -- usually FIGHTER_STATUS_THROW_WORK_INT_TARGET_OBJECT
	 * - ??? (int) -- usually FIGHTER_STATUS_THROW_WORK_INT_TARGET_HIT_GROUP
	 * - ??? (int) -- usually FIGHTER_STATUS_THROW_WORK_INT_TARGET_HIT_NO
	 */
	extern u64 ATK_HIT_ABS(u64) asm("_ZN3app10sv_animcmd11ATK_HIT_ABSEP9lua_State") LINKABLE;
	
	/**
	 * Changes the damage of a specific hitbox.
	 * arguments:
	 * - ID (int)
	 * - damage (float)
	 */
	extern u64 ATK_POWER(u64) asm("_ZN3app10sv_animcmd9ATK_POWEREP9lua_State") LINKABLE;
	
	/**
	 * Creates a hitbox.
	 * 
	 * This function should not be called directly. Instead, use ACMD.wrap() like so:
	 * ACMD.wrap(app::sv_animcmd::ATTACK, { arg1, arg2, arg3 });
	 * Arguments:
	 * - ID (int) -- lower IDs have priority
	 * - bone (hash)
	 * - damage (float)
	 * - angle (int)
	 * - knockback growth (int)
	 * - fixed knockback (int) -- usually 0
	 * - base knockback (int)
	 * - size (float)
	 * - X (float)
	 * - Y (float)
	 * - Z (float)
	 * - X2 (float) -- use NaN for non-stretching hitboxes
	 * - Y2 (float) -- use NaN for non-stretching hitboxes
	 * - Z2 (float) -- use NaN for non-stretching hitboxes
	 * - hitlag multiplier (float) -- usually 1.0
	 * - SDI multiplier (float) -- usually 1.0
	 * - clang/rebound (int) -- ATTACK_LR_CHECK_???
	 * - facing restriction (int) -- ATTACK_LR_CHECK_???
	 * - fixed weight (bool) -- usually false
	 * - additional shield damage (int) -- usually 0, hash40("no") for unblockable moves
	 * - trip chance (float) -- usually 0.0
	 * - rehit rate (int) -- usually 0
	 * - reflectable (bool) -- always false for non-projectiles
	 * - absorbable (bool) -- always false for non-projectiles
	 * - flinchless (bool) -- usually false
	 * - disable hitlag (bool) -- usually false
	 * - direct/indirect (bool) -- true for non-projectiles, false for projectiles
	 * - ground/air (int) -- usually COLLISION_SITUATION_MASK_GA
	 * - hit bits (int) -- usually COLLISION_CATEGORY_MASK_ALL
	 * - collision bits (int) -- usually COLLISION_PART_MASK_ALL
	 * - friendly fire (boolean) -- usually false
	 * - effect (hash) -- hash40("collision_attr_???")
	 * - SFX level (int) -- ATTACK_SOUND_LEVEL_???
	 * - SFX type (int) -- COLLISION_SOUND_ATTR_???
	 * - move type (int) -- ATTACK_REGION_???
	 */
	extern u64 ATTACK(u64) asm("_ZN3app10sv_animcmd6ATTACKEP9lua_State") LINKABLE; // hitbox
	
	/**
	 * Creates a grab box.
	 * 
	 * This function should not be called directly. Instead, use ACMD.wrap() like so:
	 * ACMD.wrap(app::sv_animcmd::CATCH, { arg1, arg2, arg3 });
	 * Arguments:
	 * - ID (int)
	 * - bone (hash) -- usually hash40("top")
	 * - size (float)
	 * - X (float)
	 * - Y (float)
	 * - Z (float)
	 * - X2 (float) -- use NaN for non-stretching grab boxes
	 * - Y2 (float) -- use NaN for non-stretching grab boxes
	 * - Z2 (float) -- use NaN for non-stretching grab boxes
	 * - status (int) -- usually FIGHTER_STATUS_KIND_CAPTURE_PULLED
	 * - ground/air (int) -- COLLISION_SITUATION_MASK_???
	 */
	extern u64 CATCH(u64) asm("_ZN3app10sv_animcmd5CATCHEP9lua_State") LINKABLE; // grab box
	
	/**
	 * Changes the frame speed multiplier.
	 * 
	 * The frame speed multiplier (FSM) is how long a frame of any given animation actually lasts in-game. It is the inverse of animation speed.
	 * For example, if you change the FSM to 0.4 on frame 1, then the animation will play at double speed, and you will see frames 1, 2.5, 6, 8.5, etc.
	 * Changing the FSM allows you to change the frame data of a move without having to change its animation.
	 * 
	 * This function should not be called directly. Instead, use ACMD.wrap() like so:
	 * ACMD.wrap(app::sv_animcmd::FT_MOTION_RATE, { arg1, arg2, arg3 });
	 * Arguments:
	 * - frame speed multipler (float)
	 */
	extern u64 FT_MOTION_RATE(u64) asm("_ZN3app10sv_animcmd14FT_MOTION_RATEEP9lua_State") LINKABLE; // set frame speed multiplier, lower = faster
	
	/**
	 * Changes the direction the character is facing.
	 * This function is used in moves that turn characters around, like Marth/Lucina back aerial and many back throws.
	 * 
	 * This function should not be called directly. Instead, use ACMD.wrap() like so:
	 * ACMD.wrap(app::sv_animcmd::REVERSE_LR, { arg1, arg2, arg3 });
	 * Arguments: none
	 */
	extern u64 REVERSE_LR(u64) asm("_ZN3app10sv_animcmd10REVERSE_LREP9lua_State") LINKABLE;
	
	extern u64 SEARCH(u64) asm("_ZN3app10sv_animcmd6SEARCHEP9lua_State") LINKABLE; // detect box
	extern u64 HIT_NODE(u64) asm("_ZN3app10sv_animcmd8HIT_NODEEP9lua_State") LINKABLE;
	extern u64 WHOLE_HIT(u64) asm("_ZN3app10sv_animcmd9WHOLE_HITEP9lua_State") LINKABLE;
}

#endif // ACMD_IMPORTS_H
