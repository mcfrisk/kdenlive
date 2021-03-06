/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2011 by Jean-Baptiste Mardelle (jb@kdenlive.org)        *
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

#ifndef MELTJOB
#define MELTJOB

#include <QObject>
#include <QProcess>

#include "abstractclipjob.h"

namespace Mlt{
        class Profile;
        class Producer;
        class Consumer;
        class Filter;
        class Event;
};

class MeltJob : public AbstractClipJob
{
    Q_OBJECT

public:
    MeltJob(CLIPTYPE cType, const QString &id, QStringList parameters);
    virtual ~ MeltJob();
    const QString destination() const;
    void startJob();
    stringMap cancelProperties();
    bool addClipToProject;
    const QString statusMessage();
    void setProducer(Mlt::Producer *producer);
    void emitFrameNumber();
    
private:
    Mlt::Producer *m_producer;
    Mlt::Profile *m_profile;
    Mlt::Consumer *m_consumer;
    Mlt::Event *m_showFrameEvent;
    QStringList m_params;
    QString m_dest;
    int m_length;
};

#endif
