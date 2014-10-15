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

#include "shorty.h"

#include <QtCore/QtCore>
#include <QtQuick/QtQuick>

Shorty::Shorty(QQuickView *view, QObject *parent)
    : QObject(parent)
    , _view(view)
{
}

void Shorty::shootFull(const QString &name)
{
    qDebug() << "Shoot full: " << name;
    QImage image = _view->grabWindow();
    image.save(name);
}

void Shorty::shoot(const QString &name)
{
    qDebug() << "Shoot: " << name;
    QImage image = _view->grabWindow();
    QImage scaledImage = image.scaled(QSize(96,96), Qt::KeepAspectRatioByExpanding);
    scaledImage.save(name);
}

void Shorty::sendKeyPress(int key)
{
    qDebug() << "Sending keypress for" << key;
    qApp->postEvent(_view, new QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier));
    qApp->postEvent(_view, new QKeyEvent(QEvent::KeyRelease, key, Qt::NoModifier));
}

void Shorty::sendMouseClick(int x, int y)
{
    qDebug() << "Sending mouse click at " << x << "," << y;
    qApp->postEvent(_view, new QMouseEvent(QEvent::MouseButtonPress, QPoint(x,y), Qt::LeftButton, Qt::NoButton, Qt::NoModifier));
    qApp->postEvent(_view, new QMouseEvent(QEvent::MouseButtonRelease, QPoint(x,y), Qt::LeftButton, Qt::NoButton, Qt::NoModifier));
}
