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

#ifndef RS_ACTIONDRAWTEXT_H
#define RS_ACTIONDRAWTEXT_H

#include "rs_previewactioninterface.h"
#include "rs_text.h"


/**
 * This action class can handle user events to draw texts.
 *
 * @author Andrew Mustun
 */
class RS_ActionDrawText : public RS_PreviewActionInterface {
	Q_OBJECT
public:
    /**
     * Action States.
     */
    enum Status {
        ShowDialog,           /**< Showing the text dialog. */
        SetPos,               /**< Setting the position. */
		SetText               /**< Settting the text in the command line. */
    };

public:
    RS_ActionDrawText(RS_EntityContainer& container,
                      RS_GraphicView& graphicView);
    ~RS_ActionDrawText() {}

	static QAction* createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/);
	
	virtual RS2::ActionType rtti() {
		return RS2::ActionDrawText;
	}

    virtual void init(int status=0);

	void reset();
	
    virtual void trigger();
	void preparePreview();
	
    virtual void mouseMoveEvent(RS_MouseEvent* e);
    virtual void mouseReleaseEvent(RS_MouseEvent* e);
	
	virtual void coordinateEvent(RS_CoordinateEvent* e);
    virtual void commandEvent(RS_CommandEvent* e);
	virtual RS_StringList getAvailableCommands();

    virtual void hideOptions();
    virtual void showOptions();

    virtual void updateMouseButtonHints();
    virtual void updateMouseCursor();
    virtual void updateToolBar();

	void setText(const RS_String& t);
	RS_String getText();

	void setAngle(double a);
	double getAngle();

private:
    RS_TextData data;
	//RS_Text* text;
    RS_Vector pos;
	bool textChanged;
};

#endif
