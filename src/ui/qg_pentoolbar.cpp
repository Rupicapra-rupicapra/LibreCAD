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

#include "qg_pentoolbar.h"


/**
 * Constructor.
 */
QG_PenToolBar::QG_PenToolBar( const QString & title, QWidget * parent )
        : QToolBar(title, parent) {

    colorBox = new QG_ColorBox(true, false, this, "colorbox");
    colorBox->setMinimumWidth(80);
    connect(colorBox, SIGNAL(colorChanged(const RS_Color&)),
            this, SLOT(slotColorChanged(const RS_Color&)));

    widthBox = new QG_WidthBox(true, false, this, "widthbox");
    widthBox->setMinimumWidth(80);
    connect(widthBox, SIGNAL(widthChanged(RS2::LineWidth)),
            this, SLOT(slotWidthChanged(RS2::LineWidth)));

    lineTypeBox = new QG_LineTypeBox(true, false, this, "lineTypebox");
    lineTypeBox->setMinimumWidth(80);
    connect(lineTypeBox, SIGNAL(lineTypeChanged(RS2::LineType)),
            this, SLOT(slotLineTypeChanged(RS2::LineType))); 

    currentPen.setColor(colorBox->getColor());
    currentPen.setWidth(widthBox->getWidth());
    currentPen.setLineType(lineTypeBox->getLineType());
			
	addWidget(colorBox);                                                                                                                                     
	addWidget(widthBox);                                                                                                                                     
	addWidget(lineTypeBox);  
			
}


/**
 * Destructor
 */
QG_PenToolBar::~QG_PenToolBar() {}


/**
 * Called by the layer list if this object was added as a listener 
 * to a layer list.
 */
void QG_PenToolBar::layerActivated(RS_Layer* l) {

    //printf("QG_PenToolBar::layerActivated\n");

    if (l==NULL) {
        return;
    }

    //colorBox->setColor(l->getPen().getColor());
    //widthBox->setWidth(l->getPen().getWidth());

    colorBox->setLayerColor(l->getPen().getColor());
    widthBox->setLayerWidth(l->getPen().getWidth());
    lineTypeBox->setLayerLineType(l->getPen().getLineType());

    //if (colorBox->getColor().getFlag(C_BY_LAYER)) {
    //printf("  Color by layer\n");
    //colorBox->setColor(l->getPen().getColor());
    //}
}


/**
 * Called by the layer list (if this object was previously 
 * added as a listener to a layer list).
 */
void QG_PenToolBar::layerEdited(RS_Layer*) {}


/**
 * Called when the color was changed by the user.
 */
void QG_PenToolBar::slotColorChanged(const RS_Color& color) {
    currentPen.setColor(color);
    //printf("  color changed\n");

    emit penChanged(currentPen);
}

/**
 * Called when the width was changed by the user.
 */
void QG_PenToolBar::slotWidthChanged(RS2::LineWidth w) {
    currentPen.setWidth(w);
    //printf("  width changed\n");

    emit penChanged(currentPen);
}

/**
 * Called when the linetype was changed by the user.
 */
void QG_PenToolBar::slotLineTypeChanged(RS2::LineType w) {
    currentPen.setLineType(w);
    //printf("  line type changed\n");

    emit penChanged(currentPen);
}

