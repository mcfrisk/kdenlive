/***************************************************************************
 *   Copyright (C) 2010 by Simon Andreas Eugster (simon.eu@gmail.com)      *
 *   This file is part of kdenlive. See www.kdenlive.org.                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef ABSTRACTAUDIOSCOPEWIDGET_H
#define ABSTRACTAUDIOSCOPEWIDGET_H


#include <QtCore>
#include <QWidget>

#include <stdint.h>

#include "../abstractscopewidget.h"

class QMenu;

class Monitor;
class Render;

/**
 \brief Abstract class for scopes analyzing audio samples.
 */
class AbstractAudioScopeWidget : public AbstractScopeWidget
{
    Q_OBJECT
public:
    explicit AbstractAudioScopeWidget(bool trackMouse = false, QWidget *parent = 0);
    virtual ~AbstractAudioScopeWidget();

public slots:
    void slotReceiveAudio(QVector<int16_t> sampleData, int freq, int num_channels, int num_samples);

protected:
    /** @brief This is just a wrapper function, subclasses can use renderAudioScope. */
    virtual QImage renderScope(uint accelerationFactor);

    ///// Unimplemented Methods /////
    /** @brief Scope renderer. Must emit signalScopeRenderingFinished()
        when calculation has finished, to allow multi-threading.
        accelerationFactor hints how much faster than usual the calculation should be accomplished, if possible. */
    virtual QImage renderAudioScope(uint accelerationFactor,
                               const QVector<int16_t> audioFrame, const int freq, const int num_channels, const int num_samples,
                               const int newData) = 0;

    int m_freq;
    int m_nChannels;
    int m_nSamples;

private:
    QVector<int16_t> m_audioFrame;
    QAtomicInt m_newData;

};

#endif // ABSTRACTAUDIOSCOPEWIDGET_H
