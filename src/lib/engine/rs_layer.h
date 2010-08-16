/****************************************************************************
**
** This file is part of the CADuntu project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (caduntu@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by 
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!  
**
**********************************************************************/


#ifndef RS_LAYER_H
#define RS_LAYER_H

#include <stddef.h>

#ifdef __hpux
#include <sys/_size_t.h>
#endif

#include <iostream>

#include "rs_flags.h"
#include "rs_pen.h"
#include "rs_string.h"



/**
 * Holds the data that defines a layer.
 */
class RS_LayerData {
public:
    RS_LayerData() {}

    RS_LayerData(const RS_String& name,
	             const RS_Pen& pen,
				 bool frozen,
				 bool locked) {
		this->name = name;
		this->pen = pen;
		this->frozen = frozen;
		this->locked = locked;
    }

    //! Layer name
    RS_String name;

    //! default pen for this layer
    RS_Pen pen;

	//! Frozen flag
	bool frozen;
	
	//! Locked flag
	bool locked;

	//! Converted flag (cam)
	bool converted;
};



/**
 * Class for representing a layer
 *
 * @author Andrew Mustun
 */
class RS_Layer {
public:
    explicit RS_Layer(const RS_String& name);
    //RS_Layer(const char* name);
	
    RS_Layer* clone() {
		return new RS_Layer(*this);
	}

    /** sets a new name for this layer. */
    void setName(const RS_String& name) {
        data.name = name;
    }

    /** @return the name of this layer. */
    RS_String getName() const {
        return data.name;
    }

    /** sets the default pen for this layer. */
    void setPen(const RS_Pen& pen) {
        data.pen = pen;
    }

    /** @return default pen for this layer. */
    RS_Pen getPen() const {
        return data.pen;
    }

    /**
     * @retval true if this layer is frozen (invisible)
     * @retval false if this layer isn't frozen (visible)
     */
    bool isFrozen() const {
        return data.frozen;
		//getFlag(RS2::FlagFrozen);
    }

	/**
	 * @retval true the layer has been converted already
	 * @retval false the layer still needs to be converted
	 */
    bool isConverted() const {
		return data.converted;
	}

	/**
	 * Sets the converted flag
	 */
	void setConverted(bool c) {
		data.converted = c;
	}

    /**
     * Toggles the visibility of this layer.
     * Freezes the layer if it's not frozen, thaws the layer otherwise
     */
    void toggle() {
        //toggleFlag(RS2::FlagFrozen);
		data.frozen = !data.frozen;
    }

    /**
     * (De-)freezes this layer.
     *
     * @param freeze true: freeze, false: defreeze
     */
    void freeze(bool freeze) {
		data.frozen = freeze;
        /*if (freeze) {
            setFlag(RS2::FlagFrozen);
        } else {
            delFlag(RS2::FlagFrozen);
        }*/
    }

    /**
     * Toggles the lock of this layer.
     */
    void toggleLock() {
        //toggleFlag(RS2::FlagFrozen);
		data.locked = !data.locked;
    }
	
	/**
     * Locks/Unlocks this layer.
     *
     * @param l true: lock, false: unlock
     */
	void lock(bool l) {
		data.locked = l;
	}

	/**
	 * return the LOCK state of the Layer
     */
	bool isLocked() {
		return data.locked;
	}

    /**
     * Copies all attributes (pen) and the name of the layer.
     */
	/*
    RS_Layer& operator = (const RS_Layer& l) {
        setName(l.getName());
        setPen(l.getPen());
		setFrozen(l.isFrozen());
        return *this;
    }
	*/

    friend std::ostream& operator << (std::ostream& os, const RS_Layer& l);

    //friend class RS_LayerList;

private:
	//! Layer data
	RS_LayerData data;

};

#endif
