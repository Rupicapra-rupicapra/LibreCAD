/****************************************************************************
**
** This file is part of the CADuntu project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (caduntu@rvt.dds.nl)
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


#include "rs_overlayline.h"
#include "rs_painter.h"

/**
 * Constructor.
 */
RS_OverlayLine::RS_OverlayLine(RS_EntityContainer* parent,
                 const RS_LineData& d)
        :RS_Line(parent, d) {
}


void RS_OverlayLine::draw(RS_Painter* painter, RS_GraphicView* view, double patternOffset) {
    if (painter==NULL || view==NULL) {
        return;
    }
	
	painter->drawLine(getStartpoint(),
					  getEndpoint());

}
