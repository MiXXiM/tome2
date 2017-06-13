#pragma once

#include "game_fwd.hpp"

#include "alloc.hpp"
#include "birther.hpp"
#include "game_edit_data.hpp"
#include "grid.hpp"
#include "h-basic.h"
#include "messages.hpp"
#include "player_defs.hpp"
#include "random_artifact.hpp"
#include "skill_type.hpp"
#include "wilderness_map.hpp"

#include <boost/circular_buffer.hpp>

/**
 * All structures for the game itself.
 */
struct Game {

	/**
	 * Player character name
	 */
	std::string player_name;

	/*
	 * Stripped version of "player_name"
	 */
	std::string player_base;

	/**
	 * What did the player die from?
	 */
	std::string died_from;

	/**
	 * Previous character
	 */
	birther previous_char;

	/**
	 * Wilderness map
	 */
	grid<wilderness_map> wilderness;

	/**
	 * Random artifacts
	 */
	std::vector<random_artifact> random_artifacts;

	/**
	 * Allocations
	 */
	Alloc alloc;

	/**
	 * Player's un-adjusted HP at every level.
	 * Stored to avoid shenanigans with draininging levels
	 * and restoring them back, &c.
	 */
	std::array<s16b, PY_MAX_LEVEL> player_hp { };

	/**
	 * Message buffer.
	 */
	messages messages { 2048 };

	/**
	 * Game edit data
	 */
	GameEditData edit_data;

	/**
	 * Current skill values.
	 */
	std::vector<skill_type> s_info;

};
