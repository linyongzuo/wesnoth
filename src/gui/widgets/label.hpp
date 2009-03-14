/* $Id$ */
/*
   copyright (C) 2008 - 2009 by mark de wever <koraq@xs4all.nl>
   part of the battle for wesnoth project http://www.wesnoth.org/

   this program is free software; you can redistribute it and/or modify
   it under the terms of the gnu general public license version 2
   or at your option any later version.
   this program is distributed in the hope that it will be useful,
   but without any warranty.

   see the copying file for more details.
*/

#ifndef GUI_WIDGETS_LABEL_HPP_INCLUDED
#define GUI_WIDGETS_LABEL_HPP_INCLUDED

#include "gui/widgets/control.hpp"

namespace gui2 {

/** Label showing a text. */
class tlabel : public tcontrol
{
public:

	tlabel()
		: tcontrol(COUNT)
		, state_(ENABLED)
		, can_wrap_(false)
	{
	}

	/** Inherited from twidget. */
	bool can_wrap() const { return can_wrap_; }

	/** Inherited from tcontrol. */
	void set_active(const bool active)
		{ if(get_active() != active) set_state(active ? ENABLED : DISABLED); };

	/** Inherited from tcontrol. */
	bool get_active() const { return state_ != DISABLED; }

	/** Inherited from tcontrol. */
	unsigned get_state() const { return state_; }

	/** Inherited from tcontrol. */
	bool does_block_easy_close() const { return false; }

	/***** ***** ***** setters / getters for members ***** ****** *****/

	void set_can_wrap(const bool wrap) { can_wrap_ = wrap; }

private:

	/**
	 * Possible states of the widget.
	 *
	 * Note the order of the states must be the same as defined in settings.hpp.
	 */
	enum tstate { ENABLED, DISABLED, COUNT };

	void set_state(const tstate state);

	/**
	 * Current state of the widget.
	 *
	 * The state of the widget determines what to render and how the widget
	 * reacts to certain 'events'.
	 */
	tstate state_;

	/** Holds the label can wrap or not. */
	bool can_wrap_;

	/** Inherited from tcontrol. */
	const std::string& get_control_type() const
		{ static const std::string type = "label"; return type; }
};

} // namespace gui2

#endif

