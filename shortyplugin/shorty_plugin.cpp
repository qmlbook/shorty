#include "shorty_plugin.h"
#include "shorty.h"

#include <qqml.h>

//static QObject *shorty_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
//{
//    Q_UNUSED(engine)
//    Q_UNUSED(scriptEngine)

//    Shorty *shorty = new Shorty();
//    return shorty;
//}
void ShortyPlugin::registerTypes(const char *uri)
{
    // @uri org.qmlbook.utils
    qmlRegisterType<Shorty>(uri, 1, 0, "Shorty");
}


