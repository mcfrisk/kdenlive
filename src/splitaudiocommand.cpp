/***************************************************************************
 *   Copyright (C) 2007 by Jean-Baptiste Mardelle (jb@kdenlive.org)        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA          *
 ***************************************************************************/


#include "splitaudiocommand.h"
#include "customtrackview.h"

#include <KLocale>

SplitAudioCommand::SplitAudioCommand(CustomTrackView *view, const int track, const GenTime &pos, bool doIt, QUndoCommand * parent) : QUndoCommand(parent), m_view(view), m_track(track), m_pos(pos), m_doIt(doIt) {
    setText(i18n("Split audio"));
}

// virtual
void SplitAudioCommand::undo() {
// kDebug()<<"----  undoing action";
    m_doIt = true;
    m_view->doSplitAudio(m_pos, m_track, false);
}
// virtual
void SplitAudioCommand::redo() {
    kDebug() << "----  redoing action";
    if (m_doIt)
        m_view->doSplitAudio(m_pos, m_track, true);
    m_doIt = true;
}
