/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.14.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // D:/code/src/projects/Qt/Cloud/TcpClient/TcpClient/client.cfg
  0x0,0x0,0x0,0xf,
  0x31,
  0x32,0x37,0x2e,0x30,0x2e,0x30,0x2e,0x31,0xd,0xa,0x38,0x38,0x38,0x38,
  
};

static const unsigned char qt_resource_name[] = {
  // config
  0x0,0x6,
  0x6,0xa6,0x4c,0xf7,
  0x0,0x63,
  0x0,0x6f,0x0,0x6e,0x0,0x66,0x0,0x69,0x0,0x67,
    // client.cfg
  0x0,0xa,
  0xc,0x5a,0xc,0x27,
  0x0,0x63,
  0x0,0x6c,0x0,0x69,0x0,0x65,0x0,0x6e,0x0,0x74,0x0,0x2e,0x0,0x63,0x0,0x66,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/config
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/config/client.cfg
  0x0,0x0,0x0,0x12,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x90,0x97,0x36,0xd5,0x5a,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_res)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_res)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_res)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_res)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_res)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_res)(); }
   } dummy;
}
