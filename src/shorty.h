/*
 * Shorty - a QML screenshot utility
 * Copyright (C) 2012-14 Johan Thelin <e8johan@gmail.com>
 *                   and Juergen Bocklage-Ryannel <juergen@ryannel.org>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef SHORTY_H
#define SHORTY_H

#include <QtCore/QtCore>

class QQuickView;

class Shorty : public QObject
{
    Q_OBJECT
public:
    explicit Shorty(QQuickView *view, QObject *parent = 0);
    Q_INVOKABLE void shoot(const QString& name);
    Q_INVOKABLE void shootFull(const QString &name);
    Q_INVOKABLE void sendKeyPress(int key);
    Q_INVOKABLE void sendMouseClick(int x, int y);
private:
    QQuickView *_view;
};

#endif // SHORTY_H
