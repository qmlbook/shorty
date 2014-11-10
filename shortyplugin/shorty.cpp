#include "shorty.h"
#include <QtQuick>

Shorty::Shorty(QQuickItem *parent):
    QQuickItem(parent)
{
}

Shorty::~Shorty()
{
}

void Shorty::shootFull(QString name)
{
    shoot(name, QSize());
}


void Shorty::shoot(QString name, QSize size) 
{    
    QQmlContext* ctx = QQmlEngine::contextForObject(this);
    if(!ctx) {
        qDebug() << "No context yet";
        return;
    }
    if(name.isEmpty()) {
        qDebug() << "invalid name";
        return;
    }
    QQuickWindow* win = window();
    if(!win) {
        qDebug() << "window not ready";
        return;
    }
    QImage image = win->grabWindow();
    if(size.isValid()) {
        image = image.scaled(size, Qt::KeepAspectRatioByExpanding);
    }
 
    QUrl dest = ctx->resolvedUrl(QUrl(name));
    image.save(dest.toLocalFile());
}

void Shorty::shootThumb(QString name)
{
    shoot(name, QSize(96, 96));   
}


